/*
 * Copyright (c) Meta Platforms, Inc. and affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <string>
#include <vector>

#include <folly/portability/GTest.h>

#include <thrift/compiler/generate/t_mstch_generator.h>

namespace apache {
namespace thrift {
namespace compiler {

TEST(t_mstch_generator_test, cache_leaks) {
  class leaky_program : public mstch_program {
   public:
    leaky_program(
        const t_program* program,
        const mstch_factories& factories,
        std::shared_ptr<mstch_cache> cache,
        ELEMENT_POSITION pos,
        int* object_count)
        : mstch_program(program, factories, cache, pos),
          object_count_(object_count) {
      (*object_count_) += 1;
    }
    virtual ~leaky_program() override { (*object_count_)--; }

   private:
    int* object_count_;
  };

  class leaky_program_factory : public mstch_program_factory {
   public:
    explicit leaky_program_factory(int* object_count_)
        : object_count_(object_count_) {}

    virtual std::shared_ptr<mstch_base> make_mstch_object(
        const t_program* program,
        const mstch_factories& factories,
        std::shared_ptr<mstch_cache> cache,
        ELEMENT_POSITION pos,
        int32_t /*index*/) const override {
      return std::make_shared<leaky_program>(
          program, factories, cache, pos, object_count_);
    }

   private:
    int* object_count_;
  };

  class leaky_generator : public t_mstch_generator {
   public:
    leaky_generator(t_program* program, int* object_count)
        : t_mstch_generator(program, t_generation_context(), ".", {}),
          object_count_(object_count) {}

    void generate_program() override {
      factories_.program_factory =
          std::make_unique<leaky_program_factory>(object_count_);
      std::shared_ptr<mstch_base> prog = cached_program(get_program());
    }

   private:
    int* object_count_;
  };

  int object_count = 0;
  {
    auto program = std::make_unique<t_program>("my_leak.thrift");
    leaky_generator generator(program.get(), &object_count);
    generator.generate_program();
  }

  EXPECT_EQ(object_count, 0);
}

} // namespace compiler
} // namespace thrift
} // namespace apache
