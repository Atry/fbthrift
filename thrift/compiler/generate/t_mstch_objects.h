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

#pragma once

#include <iomanip>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <string>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

#include <thrift/compiler/ast/t_program.h>
#include <thrift/compiler/detail/mustache/mstch.h>
#include <thrift/compiler/lib/cpp2/util.h>

namespace apache {
namespace thrift {
namespace compiler {

class mstch_base;
struct mstch_factories;

enum ELEMENT_POSITION {
  NONE = 0,
  FIRST = 1,
  LAST = 2,
  FIRST_AND_LAST = 3,
};

struct mstch_cache {
  std::map<std::string, std::string> options_;
  std::unordered_map<std::string, std::shared_ptr<mstch_base>> enums_;
  std::unordered_map<std::string, std::shared_ptr<mstch_base>> structs_;
  std::unordered_map<std::string, std::shared_ptr<mstch_base>> services_;
  std::unordered_map<std::string, std::shared_ptr<mstch_base>> programs_;

  void clear() {
    enums_.clear();
    structs_.clear();
    services_.clear();
    programs_.clear();
  }
};

struct field_generator_context {
  const t_struct* strct = nullptr;
  const t_field* serialization_prev = nullptr;
  const t_field* serialization_next = nullptr;
  int isset_index = -1;
};

// A factory creating mstch objects wrapping Thrift AST nodes.
// Node: A Thrift AST node type to be wrapped.
// Args: Additional arguments passed to an mstch object constructor.
template <typename Node, typename... Args>
class mstch_factory {
 public:
  using node_type = Node; // Thrift AST node type.

  virtual ~mstch_factory() = default;

  // Creates an mstch object that wraps a Thrift AST node and provides access to
  // its properties. The `factories` object is owned by `t_mstch_generator` and
  // persists throughout the generation phase.
  virtual std::shared_ptr<mstch_base> make_mstch_object(
      const Node* node,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos = ELEMENT_POSITION::NONE,
      int32_t index = 0,
      Args...) const = 0;

  std::shared_ptr<mstch_base> make_mstch_object(
      const Node& node,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos = ELEMENT_POSITION::NONE,
      int32_t index = 0,
      Args... args) const {
    return make_mstch_object(&node, factories, cache, pos, index, args...);
  }
};

using mstch_program_factory = mstch_factory<t_program>;
using mstch_service_factory = mstch_factory<t_service>;
using mstch_interaction_factory =
    mstch_factory<t_interaction, const t_service*>;
using mstch_function_factory = mstch_factory<t_function>;
using mstch_type_factory = mstch_factory<t_type>;
using mstch_typedef_factory = mstch_factory<t_typedef>;
using mstch_struct_factory = mstch_factory<t_struct>;
using mstch_field_factory =
    mstch_factory<t_field, const field_generator_context*>;
using mstch_enum_factory = mstch_factory<t_enum>;
using mstch_enum_value_factory = mstch_factory<t_enum_value>;
using mstch_const_factory =
    mstch_factory<t_const, const t_const*, const t_type*, const t_field*>;
using mstch_const_value_factory =
    mstch_factory<t_const_value, const t_const*, const t_type*>;
using mstch_const_map_element_factory = mstch_factory<
    std::pair<t_const_value*, t_const_value*>,
    const t_const*,
    const std::pair<const t_type*, const t_type*>&>;
using mstch_structured_annotation_factory = mstch_factory<t_const>;
using mstch_deprecated_annotation_factory = mstch_factory<t_annotation>;

namespace detail {

// A factory implementation without an index or extra arguments.
template <typename MstchType, typename Base>
class basic_mstch_factory_impl : public Base {
 public:
  std::shared_ptr<mstch_base> make_mstch_object(
      const typename Base::node_type* node,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t) const override {
    return std::make_shared<MstchType>(node, factories, cache, pos);
  }
};

template <typename MstchType, typename Base, typename... Args>
class mstch_factory_impl : public Base {
 public:
  std::shared_ptr<mstch_base> make_mstch_object(
      const typename Base::node_type* node,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      Args... args) const override {
    return std::make_shared<MstchType>(
        node, factories, cache, pos, index, args...);
  }
};

} // namespace detail

struct mstch_factories {
  std::unique_ptr<mstch_program_factory> program_factory;
  std::unique_ptr<mstch_service_factory> service_factory;
  std::unique_ptr<mstch_interaction_factory> interaction_factory;
  std::unique_ptr<mstch_function_factory> function_factory;
  std::unique_ptr<mstch_type_factory> type_factory;
  std::unique_ptr<mstch_typedef_factory> typedef_factory;
  std::unique_ptr<mstch_struct_factory> struct_factory;
  std::unique_ptr<mstch_field_factory> field_factory;
  std::unique_ptr<mstch_enum_factory> enum_factory;
  std::unique_ptr<mstch_enum_value_factory> enum_value_factory;
  std::unique_ptr<mstch_const_factory> const_factory;
  std::unique_ptr<mstch_const_value_factory> const_value_factory;
  std::unique_ptr<mstch_const_map_element_factory> const_map_element_factory;
  std::unique_ptr<mstch_structured_annotation_factory>
      structured_annotation_factory;
  std::unique_ptr<mstch_deprecated_annotation_factory>
      deprecated_annotation_factory;

  mstch_factories();

  // The following functions set factories for mstch object types.
  //
  // Example:
  //   set_program_factory<my_mstch_program>();
  //
  // where my_mstch_program is a subclass of mstch_program.

  template <typename MstchType>
  void set_program_factory() {
    program_factory = std::make_unique<
        detail::basic_mstch_factory_impl<MstchType, mstch_program_factory>>();
  }

  template <typename MstchType>
  void set_service_factory() {
    service_factory = std::make_unique<
        detail::basic_mstch_factory_impl<MstchType, mstch_service_factory>>();
  }

  template <typename MstchType>
  void set_interaction_factory() {
    interaction_factory = std::make_unique<detail::mstch_factory_impl<
        MstchType,
        mstch_interaction_factory,
        const t_service*>>();
  }

  template <typename MstchType>
  void set_function_factory() {
    function_factory = std::make_unique<
        detail::basic_mstch_factory_impl<MstchType, mstch_function_factory>>();
  }

  template <typename MstchType>
  void set_type_factory() {
    type_factory = std::make_unique<
        detail::basic_mstch_factory_impl<MstchType, mstch_type_factory>>();
  }

  template <typename MstchType>
  void set_typedef_factory() {
    typedef_factory = std::make_unique<
        detail::basic_mstch_factory_impl<MstchType, mstch_typedef_factory>>();
  }

  template <typename MstchType>
  void set_struct_factory() {
    struct_factory = std::make_unique<
        detail::basic_mstch_factory_impl<MstchType, mstch_struct_factory>>();
  }

  template <typename MstchType>
  void set_field_factory() {
    field_factory = std::make_unique<detail::mstch_factory_impl<
        MstchType,
        mstch_field_factory,
        const field_generator_context*>>();
  }

  template <typename MstchType>
  void set_enum_factory() {
    enum_factory = std::make_unique<
        detail::basic_mstch_factory_impl<MstchType, mstch_enum_factory>>();
  }

  template <typename MstchType>
  void set_enum_value_factory() {
    enum_value_factory = std::make_unique<detail::basic_mstch_factory_impl<
        MstchType,
        mstch_enum_value_factory>>();
  }

  template <typename MstchType>
  void set_const_factory() {
    const_factory = std::make_unique<detail::mstch_factory_impl<
        MstchType,
        mstch_const_factory,
        const t_const*,
        const t_type*,
        const t_field*>>();
  }

  template <typename MstchType>
  void set_const_value_factory() {
    const_value_factory = std::make_unique<detail::mstch_factory_impl<
        MstchType,
        mstch_const_value_factory,
        const t_const*,
        const t_type*>>();
  }

  template <typename MstchType>
  void set_const_map_element_factory() {
    const_map_element_factory = std::make_unique<detail::mstch_factory_impl<
        MstchType,
        mstch_const_map_element_factory,
        const t_const*,
        const std::pair<const t_type*, const t_type*>&>>();
  }

  template <typename MstchType>
  void set_structured_annotation_factory() {
    structured_annotation_factory = std::make_unique<detail::mstch_factory_impl<
        MstchType,
        mstch_structured_annotation_factory>>();
  }

  template <typename MstchType>
  void set_deprecated_annotation_factory() {
    deprecated_annotation_factory = std::make_unique<detail::mstch_factory_impl<
        MstchType,
        mstch_deprecated_annotation_factory>>();
  }
};

std::shared_ptr<mstch_base> make_mstch_program_cached(
    const t_program* program,
    const mstch_factories& factories,
    std::shared_ptr<mstch_cache> cache,
    ELEMENT_POSITION pos = ELEMENT_POSITION::NONE);

std::shared_ptr<mstch_base> make_mstch_service_cached(
    const t_program* program,
    const t_service* service,
    const mstch_factories& factories,
    std::shared_ptr<mstch_cache> cache,
    ELEMENT_POSITION pos = ELEMENT_POSITION::NONE);

// A base class for mstch object types that wrap Thrift AST nodes. It is called
// mstch_base rather than mstch_node to avoid confusion with mstch::node.
class mstch_base : public mstch::object {
 protected:
  // A range of t_field* to avoid copying between std::vector<t_field*>
  // and std::vector<const t_field*>.
  class field_range {
   public:
    /* implicit */ field_range(const std::vector<t_field*>& fields) noexcept
        : begin_(const_cast<const t_field* const*>(fields.data())),
          end_(const_cast<const t_field* const*>(
              fields.data() + fields.size())) {}
    /* implicit */ field_range(
        const std::vector<const t_field*>& fields) noexcept
        : begin_(fields.data()), end_(fields.data() + fields.size()) {}
    constexpr size_t size() const noexcept { return end_ - begin_; }
    constexpr const t_field* const* begin() const noexcept { return begin_; }
    constexpr const t_field* const* end() const noexcept { return end_; }

   private:
    const t_field* const* begin_;
    const t_field* const* end_;
  };

 public:
  mstch_base(
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      const ELEMENT_POSITION pos)
      : factories_(factories), cache_(cache), pos_(pos) {
    register_methods(
        this,
        {
            {"first?", &mstch_base::first},
            {"last?", &mstch_base::last},
            {"is_struct?", &mstch_base::is_struct},
        });
  }
  virtual ~mstch_base() = default;

  mstch::node first() {
    return pos_ == ELEMENT_POSITION::FIRST ||
        pos_ == ELEMENT_POSITION::FIRST_AND_LAST;
  }
  mstch::node last() {
    return pos_ == ELEMENT_POSITION::LAST ||
        pos_ == ELEMENT_POSITION::FIRST_AND_LAST;
  }
  mstch::node is_struct();

  mstch::node annotations(const t_named* annotated) {
    return make_mstch_annotations(annotated->annotations());
  }

  mstch::node structured_annotations(const t_named* annotated) {
    return make_mstch_array(
        annotated->structured_annotations(),
        *factories_.structured_annotation_factory);
  }

  static ELEMENT_POSITION element_position(size_t index, size_t length) {
    ELEMENT_POSITION pos = ELEMENT_POSITION::NONE;
    if (index == 0) {
      pos = ELEMENT_POSITION::FIRST;
    }
    if (index == length - 1) {
      pos = ELEMENT_POSITION::LAST;
    }
    if (length == 1) {
      pos = ELEMENT_POSITION::FIRST_AND_LAST;
    }
    return pos;
  }

  template <typename Container, typename Factory, typename... Args>
  mstch::array make_mstch_array(
      const Container& container, const Factory& factory, const Args&... args) {
    mstch::array a;
    size_t i = 0;
    for (auto&& element : container) {
      auto pos = element_position(i, container.size());
      a.push_back(factory.make_mstch_object(
          element, factories_, cache_, pos, i, args...));
      ++i;
    }
    return a;
  }

  template <typename C, typename... Args>
  mstch::array make_mstch_services(const C& container, const Args&... args) {
    return make_mstch_array(
        container, factories_.service_factory.get(), args...);
  }

  template <typename C, typename... Args>
  mstch::array make_mstch_interactions(
      const C& container,
      const t_service* containing_service,
      const Args&... args) {
    if (factories_.interaction_factory) {
      return make_mstch_array(
          container,
          *factories_.interaction_factory,
          containing_service,
          args...);
    }
    return make_mstch_array(container, *factories_.service_factory, args...);
  }

  template <typename C, typename... Args>
  mstch::array make_mstch_annotations(const C& container, const Args&... args) {
    return make_mstch_array(
        container, *factories_.deprecated_annotation_factory, args...);
  }

  template <typename C, typename... Args>
  mstch::array make_mstch_enum_values(const C& container, const Args&... args) {
    return make_mstch_array(container, *factories_.enum_value_factory, args...);
  }

  template <typename C, typename... Args>
  mstch::array make_mstch_consts(const C& container, const Args&... args) {
    return make_mstch_array(
        container, *factories_.const_value_factory, args...);
  }

  virtual mstch::array make_mstch_fields(const field_range& fields) {
    return make_mstch_array(fields, *factories_.field_factory, nullptr);
  }

  template <typename C, typename... Args>
  mstch::array make_mstch_functions(const C& container, const Args&... args) {
    return make_mstch_array(container, *factories_.function_factory, args...);
  }

  template <typename C, typename... Args>
  mstch::array make_mstch_typedefs(const C& container, const Args&... args) {
    return make_mstch_array(container, *factories_.typedef_factory, args...);
  }

  template <typename C, typename... Args>
  mstch::array make_mstch_types(const C& container, const Args&... args) {
    return make_mstch_array(container, *factories_.type_factory, args...);
  }

  template <typename Item, typename Factory, typename Cache>
  mstch::node make_mstch_element_cached(
      const Item& item,
      const Factory& factory,
      Cache& c,
      const std::string& id,
      size_t element_index,
      size_t element_count) {
    std::string elem_id = id + item->get_name();
    auto pos = element_position(element_index, element_count);
    auto itr = c.find(elem_id);
    if (itr == c.end()) {
      itr = c.emplace_hint(
          itr,
          elem_id,
          factory.make_mstch_object(
              item, factories_, cache_, pos, element_index));
    }
    return itr->second;
  }

  template <typename Container, typename Factory, typename Cache>
  mstch::array make_mstch_array_cached(
      const Container& container,
      const Factory& factory,
      Cache& c,
      const std::string& id) {
    mstch::array a;
    for (size_t i = 0; i < container.size(); ++i) {
      a.push_back(make_mstch_element_cached(
          container[i], factory, c, id, i, container.size()));
    }
    return a;
  }

  bool has_option(const std::string& option) const;
  std::string get_option(const std::string& option) const;

  // Registers has_option(option) under the given name.
  void register_has_option(std::string key, std::string option);

 protected:
  const mstch_factories& factories_;
  std::shared_ptr<mstch_cache> cache_;
  const ELEMENT_POSITION pos_;
};

class mstch_enum_value : public mstch_base {
 public:
  using node_type = t_enum_value;
  mstch_enum_value(
      const t_enum_value* enum_value,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_base(factories, cache, pos), enum_value_(enum_value) {
    register_methods(
        this,
        {
            {"enum_value:name", &mstch_enum_value::name},
            {"enum_value:value", &mstch_enum_value::value},
        });
  }
  mstch::node name() { return enum_value_->get_name(); }
  mstch::node value() { return std::to_string(enum_value_->get_value()); }

 protected:
  const t_enum_value* enum_value_;
};

class mstch_enum : public mstch_base {
 public:
  using node_type = t_enum;
  mstch_enum(
      const t_enum* enm,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_base(factories, cache, pos), enm_(enm) {
    register_methods(
        this,
        {
            {"enum:name", &mstch_enum::name},
            {"enum:values", &mstch_enum::values},
            {"enum:structured_annotations",
             &mstch_enum::structured_annotations},
        });
  }

  mstch::node name() { return enm_->get_name(); }
  mstch::node values();
  mstch::node structured_annotations() {
    return mstch_base::structured_annotations(enm_);
  }

 protected:
  const t_enum* enm_;
};

class mstch_const_value : public mstch_base {
 public:
  using cv = t_const_value::t_const_value_type;
  mstch_const_value(
      const t_const_value* const_value,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      const t_const* current_const,
      const t_type* expected_type)
      : mstch_base(factories, cache, pos),
        const_value_(const_value),
        current_const_(current_const),
        expected_type_(expected_type),
        type_(const_value->get_type()),
        index_(index) {
    register_methods(
        this,
        {
            {"value:bool?", &mstch_const_value::is_bool},
            {"value:double?", &mstch_const_value::is_double},
            {"value:integer?", &mstch_const_value::is_integer},
            {"value:enum?", &mstch_const_value::is_enum},
            {"value:enum_value?", &mstch_const_value::has_enum_value},
            {"value:string?", &mstch_const_value::is_string},
            {"value:string_multi_line?",
             &mstch_const_value::is_string_multi_line},
            {"value:base?", &mstch_const_value::is_base},
            {"value:map?", &mstch_const_value::is_map},
            {"value:list?", &mstch_const_value::is_list},
            {"value:container?", &mstch_const_value::is_container},
            {"value:empty_container?", &mstch_const_value::is_empty_container},
            {"value:value", &mstch_const_value::value},
            {"value:integer_value", &mstch_const_value::integer_value},
            {"value:double_value", &mstch_const_value::double_value},
            {"value:bool_value", &mstch_const_value::bool_value},
            {"value:nonzero?", &mstch_const_value::is_non_zero},
            {"value:enum_name", &mstch_const_value::enum_name},
            {"value:enum_value_name", &mstch_const_value::enum_value_name},
            {"value:string_value", &mstch_const_value::string_value},
            {"value:list_elements", &mstch_const_value::list_elems},
            {"value:map_elements", &mstch_const_value::map_elems},
            {"value:const_struct", &mstch_const_value::const_struct},
            {"value:const_struct?", &mstch_const_value::is_const_struct},
            {"value:const_struct_type", &mstch_const_value::const_struct_type},
            {"value:referenceable?", &mstch_const_value::referenceable},
            {"value:owning_const", &mstch_const_value::owning_const},
            {"value:enable_referencing",
             &mstch_const_value::enable_referencing},
        });
  }

  std::string format_double_string(const double d) {
    std::ostringstream oss;
    oss << std::setprecision(std::numeric_limits<double>::digits10) << d;
    return oss.str();
  }
  mstch::node is_bool() { return type_ == cv::CV_BOOL; }
  mstch::node is_double() { return type_ == cv::CV_DOUBLE; }
  mstch::node is_integer() {
    return type_ == cv::CV_INTEGER && !const_value_->is_enum();
  }
  mstch::node is_enum() {
    return type_ == cv::CV_INTEGER && const_value_->is_enum();
  }
  mstch::node has_enum_value() {
    return const_value_->get_enum_value() != nullptr;
  }
  mstch::node is_string() { return type_ == cv::CV_STRING; }
  mstch::node is_string_multi_line() {
    return type_ == cv::CV_STRING &&
        const_value_->get_string().find("\n") != std::string::npos;
  }
  mstch::node is_base() {
    return type_ == cv::CV_BOOL || type_ == cv::CV_DOUBLE ||
        type_ == cv::CV_INTEGER || type_ == cv::CV_STRING;
  }
  mstch::node is_map() { return type_ == cv::CV_MAP; }
  mstch::node is_list() { return type_ == cv::CV_LIST; }
  mstch::node is_container() {
    return type_ == cv::CV_MAP || type_ == cv::CV_LIST;
  }
  mstch::node is_empty_container() {
    return (type_ == cv::CV_MAP && const_value_->get_map().empty()) ||
        (type_ == cv::CV_LIST && const_value_->get_list().empty());
  }
  mstch::node value();
  mstch::node integer_value();
  mstch::node double_value();
  mstch::node bool_value();
  mstch::node is_non_zero();
  mstch::node enum_name();
  mstch::node enum_value_name();
  mstch::node string_value();
  mstch::node list_elems();
  mstch::node map_elems();
  mstch::node const_struct();
  mstch::node referenceable() {
    return current_const_ && const_value_->get_owner() &&
        current_const_ != const_value_->get_owner() && same_type_as_expected();
  }
  mstch::node owning_const();
  mstch::node enable_referencing() {
    return mstch::map{{"value:enable_referencing?", true}};
  }
  mstch::node is_const_struct();
  mstch::node const_struct_type();

 protected:
  const t_const_value* const_value_;
  const t_const* current_const_;
  const t_type* expected_type_;
  const cv type_;
  int32_t index_;

  virtual bool same_type_as_expected() const { return false; }
};

class mstch_const_map_element : public mstch_base {
 public:
  mstch_const_map_element(
      const std::pair<t_const_value*, t_const_value*>* element,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      const t_const* current_const,
      const std::pair<const t_type*, const t_type*>& expected_types)
      : mstch_base(factories, cache, pos),
        element_(*element),
        index_(index),
        current_const_(current_const),
        expected_types_(expected_types) {
    register_methods(
        this,
        {
            {"element:key", &mstch_const_map_element::element_key},
            {"element:value", &mstch_const_map_element::element_value},
        });
  }
  mstch::node element_key();
  mstch::node element_value();

 protected:
  const std::pair<t_const_value*, t_const_value*> element_;
  const int32_t index_;
  const t_const* current_const_;
  const std::pair<const t_type*, const t_type*> expected_types_;
};

class mstch_type : public mstch_base {
 public:
  mstch_type(
      const t_type* type,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_base(factories, cache, pos),
        type_(type),
        resolved_type_(type->get_true_type()) {
    register_methods(
        this,
        {
            {"type:name", &mstch_type::name},
            {"type:void?", &mstch_type::is_void},
            {"type:string?", &mstch_type::is_string},
            {"type:binary?", &mstch_type::is_binary},
            {"type:bool?", &mstch_type::is_bool},
            {"type:byte?", &mstch_type::is_byte},
            {"type:i16?", &mstch_type::is_i16},
            {"type:i32?", &mstch_type::is_i32},
            {"type:i64?", &mstch_type::is_i64},
            {"type:double?", &mstch_type::is_double},
            {"type:float?", &mstch_type::is_float},
            {"type:floating_point?", &mstch_type::is_floating_point},
            {"type:struct?", &mstch_type::is_struct},
            {"type:union?", &mstch_type::is_union},
            {"type:enum?", &mstch_type::is_enum},
            {"type:sink?", &mstch_type::is_sink},
            {"type:sink_has_first_response?",
             &mstch_type::sink_has_first_response},
            {"type:stream_or_sink?", &mstch_type::is_stream_or_sink},
            {"type:streamresponse?", &mstch_type::is_streamresponse},
            {"type:stream_has_first_response?",
             &mstch_type::stream_has_first_response},
            {"type:service?", &mstch_type::is_service},
            {"type:base?", &mstch_type::is_base},
            {"type:container?", &mstch_type::is_container},
            {"type:list?", &mstch_type::is_list},
            {"type:set?", &mstch_type::is_set},
            {"type:map?", &mstch_type::is_map},
            {"type:typedef?", &mstch_type::is_typedef},
            {"type:struct", &mstch_type::get_struct},
            {"type:enum", &mstch_type::get_enum},
            {"type:list_elem_type", &mstch_type::get_list_type},
            {"type:set_elem_type", &mstch_type::get_set_type},
            {"type:sink_elem_type", &mstch_type::get_sink_elem_type},
            {"type:sink_final_response_type",
             &mstch_type::get_sink_final_reponse_type},
            {"type:sink_first_response_type",
             &mstch_type::get_sink_first_response_type},
            {"type:stream_elem_type", &mstch_type::get_stream_elem_type},
            {"type:stream_first_response_type",
             &mstch_type::get_stream_first_response_type},
            {"type:key_type", &mstch_type::get_key_type},
            {"type:value_type", &mstch_type::get_value_type},
            {"type:typedef_type", &mstch_type::get_typedef_type},
            {"type:typedef", &mstch_type::get_typedef},
            {"type:interaction?", &mstch_type::is_interaction},
        });
  }

  mstch::node name() { return type_->get_name(); }
  mstch::node is_void() { return resolved_type_->is_void(); }
  mstch::node is_string() { return resolved_type_->is_string(); }
  mstch::node is_binary() { return resolved_type_->is_binary(); }
  mstch::node is_bool() { return resolved_type_->is_bool(); }
  mstch::node is_byte() { return resolved_type_->is_byte(); }
  mstch::node is_i16() { return resolved_type_->is_i16(); }
  mstch::node is_i32() { return resolved_type_->is_i32(); }
  mstch::node is_i64() { return resolved_type_->is_i64(); }
  mstch::node is_double() { return resolved_type_->is_double(); }
  mstch::node is_float() { return resolved_type_->is_float(); }
  mstch::node is_floating_point() {
    return resolved_type_->is_floating_point();
  }
  mstch::node is_struct() {
    return resolved_type_->is_struct() || resolved_type_->is_xception();
  }
  mstch::node is_union() { return resolved_type_->is_union(); }
  mstch::node is_enum() { return resolved_type_->is_enum(); }
  mstch::node is_sink() { return resolved_type_->is_sink(); }
  mstch::node sink_has_first_response() {
    return resolved_type_->is_sink() &&
        dynamic_cast<const t_sink*>(resolved_type_)->sink_has_first_response();
  }
  mstch::node is_stream_or_sink() {
    return resolved_type_->is_streamresponse() || resolved_type_->is_sink();
  }
  mstch::node is_streamresponse() {
    return resolved_type_->is_streamresponse();
  }
  mstch::node stream_has_first_response() {
    return resolved_type_->is_streamresponse() &&
        !dynamic_cast<const t_stream_response*>(resolved_type_)
             ->first_response_type()
             .empty();
  }
  mstch::node is_service() { return resolved_type_->is_service(); }
  mstch::node is_base() { return resolved_type_->is_base_type(); }
  mstch::node is_container() { return resolved_type_->is_container(); }
  mstch::node is_list() { return resolved_type_->is_list(); }
  mstch::node is_set() { return resolved_type_->is_set(); }
  mstch::node is_map() { return resolved_type_->is_map(); }
  mstch::node is_typedef() { return type_->is_typedef(); }
  virtual std::string get_type_namespace(const t_program*) { return ""; }
  mstch::node get_struct();
  mstch::node get_enum();
  mstch::node get_list_type();
  mstch::node get_set_type();
  mstch::node get_key_type();
  mstch::node get_value_type();
  mstch::node get_typedef_type();
  mstch::node get_typedef();
  mstch::node get_sink_first_response_type();
  mstch::node get_sink_elem_type();
  mstch::node get_sink_final_reponse_type();
  mstch::node get_stream_elem_type();
  mstch::node get_stream_first_response_type();
  mstch::node is_interaction() { return type_->is_service(); }

 protected:
  const t_type* type_;
  const t_type* resolved_type_;
};

class mstch_field : public mstch_base {
 public:
  mstch_field(
      const t_field* field,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      const field_generator_context* field_context)
      : mstch_base(factories, cache, pos),
        field_(field),
        index_(index),
        field_context_(field_context) {
    register_methods(
        this,
        {
            {"field:name", &mstch_field::name},
            {"field:key", &mstch_field::key},
            {"field:value", &mstch_field::value},
            {"field:type", &mstch_field::type},
            {"field:index", &mstch_field::index},
            {"field:required?", &mstch_field::is_required},
            {"field:terse?", &mstch_field::is_terse},
            {"field:optional?", &mstch_field::is_optional},
            {"field:opt_in_req_out?", &mstch_field::is_optInReqOut},
            {"field:annotations", &mstch_field::annotations},
            {"field:structured_annotations",
             &mstch_field::structured_annotations},
        });
  }
  mstch::node name() { return field_->get_name(); }
  mstch::node key() { return std::to_string(field_->get_key()); }
  mstch::node value();
  mstch::node type();
  mstch::node index() { return std::to_string(index_); }
  mstch::node is_terse() {
    return field_->qualifier() == t_field_qualifier::terse;
  }
  mstch::node is_required() {
    return field_->get_req() == t_field::e_req::required;
  }
  mstch::node is_optional() {
    return field_->get_req() == t_field::e_req::optional;
  }
  mstch::node is_optInReqOut() {
    return field_->get_req() == t_field::e_req::opt_in_req_out;
  }
  mstch::node annotations() { return mstch_base::annotations(field_); }
  mstch::node structured_annotations() {
    return mstch_base::structured_annotations(field_);
  }

 protected:
  const t_field* field_;
  int32_t index_;
  const field_generator_context* field_context_;
};

class mstch_deprecated_annotation : public mstch_base {
 public:
  mstch_deprecated_annotation(
      const t_annotation* annotation,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t)
      : mstch_base(factories, cache, pos),
        key_(annotation->first),
        val_(annotation->second) {
    register_methods(
        this,
        {
            {"annotation:key", &mstch_deprecated_annotation::key},
            {"annotation:value", &mstch_deprecated_annotation::value},
        });
  }
  mstch::node key() { return key_; }
  mstch::node value() { return val_.value; }

 protected:
  const std::string key_;
  const annotation_value val_;
};

class mstch_structured_annotation : public mstch_base {
 public:
  mstch_structured_annotation(
      const t_const* c,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index)
      : mstch_base(factories, cache, pos), const_(*c), index_(index) {
    register_methods(
        this,
        {{"structured_annotation:const",
          &mstch_structured_annotation::constant},
         {"structured_annotation:const_struct?",
          &mstch_structured_annotation::is_const_struct}});
  }
  mstch::node constant() {
    return factories_.const_factory->make_mstch_object(
        &const_,
        factories_,
        cache_,
        pos_,
        index_,
        &const_,
        const_.type()->get_true_type(),
        nullptr);
  }

  mstch::node is_const_struct() {
    return const_.type()->get_true_type()->is_struct();
  }

 protected:
  const t_const& const_;
  int32_t index_;
};

class mstch_struct : public mstch_base {
 public:
  mstch_struct(
      const t_struct* s,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_base(factories, cache, pos), struct_(s) {
    register_methods(
        this,
        {
            {"struct:name", &mstch_struct::name},
            {"struct:fields?", &mstch_struct::has_fields},
            {"struct:fields", &mstch_struct::fields},
            {"struct:fields_in_serialization_order",
             &mstch_struct::fields_in_serialization_order},
            {"struct:exception?", &mstch_struct::is_exception},
            {"struct:union?", &mstch_struct::is_union},
            {"struct:plain?", &mstch_struct::is_plain},
            {"struct:annotations", &mstch_struct::annotations},
            {"struct:thrift_uri", &mstch_struct::thrift_uri},
            {"struct:structured_annotations",
             &mstch_struct::structured_annotations},
            {"struct:exception_kind", &mstch_struct::exception_kind},
            {"struct:exception_safety", &mstch_struct::exception_safety},
            {"struct:exception_blame", &mstch_struct::exception_blame},
        });

    // Populate field_context_generator for each field.
    auto ctx = field_generator_context{};
    ctx.strct = struct_;
    for (const t_field& field : s->fields()) {
      if (cpp2::field_has_isset(&field)) {
        ctx.isset_index++;
      }
      context_map[&field] = ctx;
    }

    const t_field* prev = nullptr;
    for (const t_field* curr : get_members_in_serialization_order()) {
      if (prev) {
        context_map[prev].serialization_next = curr;
        context_map[curr].serialization_prev = prev;
      }
      prev = curr;
    }
  }
  mstch::node name() { return struct_->get_name(); }
  mstch::node has_fields() { return struct_->has_fields(); }
  mstch::node fields();
  mstch::node is_exception() { return struct_->is_xception(); }
  mstch::node is_union() { return struct_->is_union(); }
  mstch::node is_plain() {
    return !struct_->is_xception() && !struct_->is_union();
  }
  mstch::node annotations() { return mstch_base::annotations(struct_); }
  mstch::node structured_annotations() {
    return mstch_base::structured_annotations(struct_);
  }
  mstch::node thrift_uri() { return struct_->uri(); }

  mstch::node exception_safety();
  mstch::node exception_blame();
  mstch::node exception_kind();

  mstch::array make_mstch_fields(const field_range& fields) override {
    mstch::array a;
    size_t i = 0;
    for (const auto* field : fields) {
      auto pos = element_position(i, fields.size());
      a.push_back(factories_.field_factory->make_mstch_object(
          field, factories_, cache_, pos, i, &context_map[field]));
      ++i;
    }
    return a;
  }

  // Returns the struct members ordered by the key.
  const std::vector<const t_field*>& get_members_in_key_order();

  field_range get_members_in_serialization_order() {
    if (struct_->find_structured_annotation_or_null(
            "facebook.com/thrift/annotation/SerializeInFieldIdOrder")) {
      return get_members_in_key_order();
    }

    return struct_->get_members();
  }

  mstch::node fields_in_serialization_order() {
    return make_mstch_fields(get_members_in_serialization_order());
  }

 protected:
  const t_struct* struct_;
  // Although mstch_fields can be generated in a different order than the IDL
  // order, field_generator_context should be always computed in the IDL order,
  // as the context does not change by reordering. Without the map, each
  // different reordering recomputes field_generator_context, and each
  // field takes O(N) to loop through node_list_view<t_field> or
  // std::vector<t_field*> to find the exact t_field to compute
  // field_generator_context.
  std::unordered_map<const t_field*, field_generator_context> context_map;

  std::vector<const t_field*> fields_in_key_order_;
};

class mstch_function : public mstch_base {
 public:
  mstch_function(
      const t_function* function,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_base(factories, cache, pos), function_(function) {
    register_methods(
        this,
        {
            {"function:name", &mstch_function::name},
            {"function:oneway?", &mstch_function::oneway},
            {"function:return_type", &mstch_function::return_type},
            {"function:exceptions", &mstch_function::exceptions},
            {"function:stream_exceptions", &mstch_function::stream_exceptions},
            {"function:sink_exceptions", &mstch_function::sink_exceptions},
            {"function:sink_final_response_exceptions",
             &mstch_function::sink_final_response_exceptions},
            {"function:exceptions?", &mstch_function::has_exceptions},
            {"function:stream_exceptions?",
             &mstch_function::has_streamexceptions},
            {"function:sink_exceptions?", &mstch_function::has_sinkexceptions},
            {"function:sink_final_response_exceptions?",
             &mstch_function::has_sink_final_response_exceptions},
            {"function:args", &mstch_function::arg_list},
            {"function:comma", &mstch_function::has_args},
            {"function:priority", &mstch_function::priority},
            {"function:returns_sink?", &mstch_function::returns_sink},
            {"function:returns_streams?", &mstch_function::returns_stream},
            {"function:returns_stream?", &mstch_function::returns_stream},
            {"function:stream_has_first_response?",
             &mstch_function::stream_has_first_response},
            {"function:annotations", &mstch_function::annotations},
            {"function:starts_interaction?",
             &mstch_function::starts_interaction},
            {"function:structured_annotations",
             &mstch_function::structured_annotations},
            {"function:qualifier", &mstch_function::qualifier},
            {"function:creates_interaction?",
             &mstch_function::creates_interaction},
            {"function:in_or_creates_interaction?",
             &mstch_function::in_or_creates_interaction},
            {"function:void?", &mstch_function::is_void},
        });
  }

  mstch::node name() { return function_->get_name(); }
  mstch::node oneway() {
    return function_->qualifier() == t_function_qualifier::one_way;
  }
  mstch::node has_exceptions() {
    return function_->get_xceptions()->has_fields();
  }
  mstch::node has_streamexceptions() {
    return function_->get_stream_xceptions()->has_fields();
  }
  mstch::node has_sinkexceptions() {
    return function_->get_sink_xceptions()->has_fields();
  }
  mstch::node has_sink_final_response_exceptions() {
    return function_->get_sink_final_response_xceptions()->has_fields();
  }
  mstch::node stream_has_first_response() {
    const auto& rettype = *function_->return_type();
    auto stream = dynamic_cast<const t_stream_response*>(&rettype);
    return stream && !stream->first_response_type().empty();
  }
  mstch::node has_args() {
    if (function_->get_paramlist()->has_fields()) {
      return std::string(", ");
    }
    return std::string();
  }
  mstch::node priority() {
    return function_->get_annotation("priority", "NORMAL");
  }
  mstch::node returns_sink() { return function_->returns_sink(); }
  mstch::node annotations() { return mstch_base::annotations(function_); }

  mstch::node return_type();
  mstch::node exceptions();
  mstch::node stream_exceptions();
  mstch::node sink_exceptions();
  mstch::node sink_final_response_exceptions();
  mstch::node arg_list();
  mstch::node returns_stream();
  mstch::node starts_interaction() {
    return function_->get_returntype()->is_service();
  }

  mstch::node structured_annotations() {
    return mstch_base::structured_annotations(function_);
  }

  mstch::node qualifier() {
    auto q = function_->qualifier();
    switch (q) {
      case t_function_qualifier::one_way:
        return std::string("OneWay");
      case t_function_qualifier::idempotent:
        return std::string("Idempotent");
      case t_function_qualifier::read_only:
        return std::string("ReadOnly");
      default:
        return std::string("Unspecified");
    }
  }

  mstch::node creates_interaction() {
    return !function_->returned_interaction().empty();
  }
  mstch::node in_or_creates_interaction() {
    return !function_->returned_interaction().empty() ||
        function_->is_interaction_member();
  }
  mstch::node is_void() {
    return function_->return_type().deref().is_void() &&
        !function_->returned_interaction();
  }

 protected:
  const t_function* function_;
};

class mstch_service : public mstch_base {
 public:
  mstch_service(
      const t_service* service,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_base(factories, cache, pos), service_(service) {
    register_methods(
        this,
        {
            {"service:name", &mstch_service::name},
            {"service:functions", &mstch_service::functions},
            {"service:functions?", &mstch_service::has_functions},
            {"service:extends", &mstch_service::extends},
            {"service:extends?", &mstch_service::has_extends},
            {"service:streams?", &mstch_service::has_streams},
            {"service:sinks?", &mstch_service::has_sinks},
            {"service:annotations", &mstch_service::annotations},
            {"service:thrift_uri", &mstch_service::thrift_uri},
            {"service:parent", &mstch_service::parent},
            {"service:interaction?", &mstch_service::is_interaction},
            {"service:interactions", &mstch_service::interactions},
            {"service:interactions?", &mstch_service::has_interactions},
            {"service:structured_annotations",
             &mstch_service::structured_annotations},
            {"interaction:serial?", &mstch_service::is_serial_interaction},
            {"interaction:eb?", &mstch_service::is_event_base_interaction},
        });

    // Collect performed interactions and cache them
    for (const auto* function : get_functions()) {
      if (function->get_returntype()->is_service()) {
        interactions_.insert(
            dynamic_cast<const t_interaction*>(function->get_returntype()));
      } else if (auto interaction = function->returned_interaction()) {
        interactions_.insert(
            dynamic_cast<const t_interaction*>(interaction->get_true_type()));
      }
    }
    assert(interactions_.count(nullptr) == 0);
  }

  virtual std::string get_service_namespace(const t_program*) { return {}; }

  mstch::node name() { return service_->get_name(); }
  mstch::node has_functions() { return !get_functions().empty(); }
  mstch::node has_extends() { return service_->get_extends() != nullptr; }
  mstch::node functions();
  mstch::node extends();
  mstch::node annotations() { return mstch_base::annotations(service_); }
  mstch::node thrift_uri() { return service_->uri(); }

  mstch::node parent() { return cache_->options_.at("parent_service_name"); }

  mstch::node has_streams() {
    auto& funcs = get_functions();
    return std::any_of(funcs.cbegin(), funcs.cend(), [](const auto& func) {
      return func->returns_stream();
    });
  }

  mstch::node has_sinks() {
    auto& funcs = get_functions();
    return std::any_of(funcs.cbegin(), funcs.cend(), [](const auto& func) {
      return func->returns_sink();
    });
  }

  mstch::node has_interactions() { return !interactions_.empty(); }
  mstch::node interactions() {
    if (!service_->is_interaction()) {
      // for Python interactions
      cache_->options_["parent_service_name"] = service_->get_name();
      cache_->options_["parent_service_cpp_name"] = cpp2::get_name(service_);
    }
    return make_mstch_interactions(interactions_, service_);
  }
  mstch::node structured_annotations() {
    return mstch_base::structured_annotations(service_);
  }
  mstch::node is_interaction() { return service_->is_interaction(); }
  mstch::node is_serial_interaction() {
    return service_->is_serial_interaction();
  }
  mstch::node is_event_base_interaction() {
    return service_->has_annotation("process_in_event_base");
  }

  virtual ~mstch_service() = default;

 protected:
  const t_service* service_;
  std::set<const t_interaction*> interactions_;

  mstch::node make_mstch_extended_service_cached(const t_service* service);
  virtual const std::vector<t_function*>& get_functions() const {
    return service_->get_functions();
  }
};

class mstch_typedef : public mstch_base {
 public:
  mstch_typedef(
      const t_typedef* t,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_base(factories, cache, pos), typedef_(t) {
    register_methods(
        this,
        {
            {"typedef:type", &mstch_typedef::type},
            {"typedef:is_same_type", &mstch_typedef::is_same_type},
            {"typedef:name", &mstch_typedef::name},
            {"typedef:structured_annotations",
             &mstch_typedef::structured_annotations},
        });
  }
  mstch::node type();
  mstch::node name() { return typedef_->name(); }
  mstch::node is_same_type() {
    return typedef_->get_name() == typedef_->get_type()->get_name();
  }
  mstch::node structured_annotations() {
    return mstch_base::structured_annotations(typedef_);
  }

 protected:
  const t_typedef* typedef_;
};

class mstch_const : public mstch_base {
 public:
  mstch_const(
      const t_const* c,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos,
      int32_t index,
      const t_const* current_const,
      const t_type* expected_type,
      const t_field* field)
      : mstch_base(factories, cache, pos),
        const_(c),
        current_const_(current_const),
        expected_type_(expected_type),
        index_(index),
        field_(field) {
    register_methods(
        this,
        {
            {"constant:name", &mstch_const::name},
            {"constant:index", &mstch_const::index},
            {"constant:type", &mstch_const::type},
            {"constant:value", &mstch_const::value},
            {"constant:program", &mstch_const::program},
        });
  }
  mstch::node name() { return const_->get_name(); }
  mstch::node index() { return index_; }
  mstch::node type();
  mstch::node value();
  mstch::node program();

 protected:
  const t_const* const_;
  const t_const* current_const_;
  const t_type* expected_type_;
  int32_t index_;
  const t_field* field_;
};

class mstch_program : public mstch_base {
 public:
  mstch_program(
      const t_program* program,
      const mstch_factories& factories,
      std::shared_ptr<mstch_cache> cache,
      ELEMENT_POSITION pos)
      : mstch_base(factories, cache, pos), program_(program) {
    register_methods(
        this,
        {
            {"program:name", &mstch_program::name},
            {"program:path", &mstch_program::path},
            {"program:includePrefix", &mstch_program::include_prefix},
            {"program:structs", &mstch_program::structs},
            {"program:enums", &mstch_program::enums},
            {"program:services", &mstch_program::services},
            {"program:typedefs", &mstch_program::typedefs},
            {"program:constants", &mstch_program::constants},
            {"program:enums?", &mstch_program::has_enums},
            {"program:structs?", &mstch_program::has_structs},
            {"program:unions?", &mstch_program::has_unions},
            {"program:services?", &mstch_program::has_services},
            {"program:typedefs?", &mstch_program::has_typedefs},
            {"program:constants?", &mstch_program::has_constants},
            {"program:thrift_uris?", &mstch_program::has_thrift_uris},
        });
    register_has_option("program:frozen?", "frozen");
    register_has_option("program:json?", "json");
    register_has_option("program:any?", "any");
    register_has_option(
        "program:unstructured_annotations_in_metadata?",
        "deprecated_unstructured_annotations_in_metadata");
  }

  virtual std::string get_program_namespace(const t_program*) { return {}; }

  mstch::node name() { return program_->name(); }
  mstch::node path() { return program_->path(); }
  mstch::node include_prefix() { return program_->include_prefix(); }
  mstch::node has_enums() { return !program_->enums().empty(); }
  mstch::node has_structs() {
    return !program_->structs().empty() || !program_->xceptions().empty();
  }
  mstch::node has_services() { return !program_->services().empty(); }
  mstch::node has_typedefs() { return !program_->typedefs().empty(); }
  mstch::node has_constants() { return !program_->consts().empty(); }
  mstch::node has_unions() {
    auto& structs = program_->structs();
    return std::any_of(
        structs.cbegin(), structs.cend(), std::mem_fn(&t_struct::is_union));
  }

  mstch::node has_thrift_uris();
  mstch::node structs();
  mstch::node enums();
  mstch::node services();
  mstch::node typedefs();
  mstch::node constants();

 protected:
  const t_program* program_;

  virtual const std::vector<t_struct*>& get_program_objects();
  virtual const std::vector<t_enum*>& get_program_enums();
};

} // namespace compiler
} // namespace thrift
} // namespace apache
