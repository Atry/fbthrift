/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.patch;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import com.google.common.collect.*;
import java.util.*;
import javax.annotation.Nullable;
import org.apache.thrift.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@com.facebook.swift.codec.ThriftStruct(value="MyStructField22Patch", builder=MyStructField22Patch.Builder.class)
public final class MyStructField22Patch implements com.facebook.thrift.payload.ThriftSerializable {

    @ThriftConstructor
    public MyStructField22Patch(
        @com.facebook.swift.codec.ThriftField(value=1, name="assign", requiredness=Requiredness.OPTIONAL) final Set<String> assign,
        @com.facebook.swift.codec.ThriftField(value=2, name="clear", requiredness=Requiredness.NONE) final boolean clear,
        @com.facebook.swift.codec.ThriftField(value=4, name="add", requiredness=Requiredness.NONE) final Set<String> add,
        @com.facebook.swift.codec.ThriftField(value=5, name="remove", requiredness=Requiredness.NONE) final Set<String> remove
    ) {
        this.assign = assign;
        this.clear = clear;
        this.add = add;
        this.remove = remove;
    }
    
    @ThriftConstructor
    protected MyStructField22Patch() {
      this.assign = null;
      this.clear = false;
      this.add = null;
      this.remove = null;
    }
    
    public static class Builder {
    
        private Set<String> assign = null;
        private boolean clear = false;
        private Set<String> add = null;
        private Set<String> remove = null;
    
        @com.facebook.swift.codec.ThriftField(value=1, name="assign", requiredness=Requiredness.OPTIONAL)
        public Builder setAssign(Set<String> assign) {
            this.assign = assign;
            return this;
        }
    
        public Set<String> getAssign() { return assign; }
    
            @com.facebook.swift.codec.ThriftField(value=2, name="clear", requiredness=Requiredness.NONE)
        public Builder setClear(boolean clear) {
            this.clear = clear;
            return this;
        }
    
        public boolean isClear() { return clear; }
    
            @com.facebook.swift.codec.ThriftField(value=4, name="add", requiredness=Requiredness.NONE)
        public Builder setAdd(Set<String> add) {
            this.add = add;
            return this;
        }
    
        public Set<String> getAdd() { return add; }
    
            @com.facebook.swift.codec.ThriftField(value=5, name="remove", requiredness=Requiredness.NONE)
        public Builder setRemove(Set<String> remove) {
            this.remove = remove;
            return this;
        }
    
        public Set<String> getRemove() { return remove; }
    
        public Builder() { }
        public Builder(MyStructField22Patch other) {
            this.assign = other.assign;
            this.clear = other.clear;
            this.add = other.add;
            this.remove = other.remove;
        }
    
        @ThriftConstructor
        public MyStructField22Patch build() {
            MyStructField22Patch result = new MyStructField22Patch (
                this.assign,
                this.clear,
                this.add,
                this.remove
            );
            return result;
        }
    }
    
    public static final Map<String, Integer> NAMES_TO_IDS = new HashMap();
    public static final Map<String, Integer> THRIFT_NAMES_TO_IDS = new HashMap();
    public static final Map<Integer, TField> FIELD_METADATA = new HashMap<>();
    private static final TStruct STRUCT_DESC = new TStruct("MyStructField22Patch");
    private final Set<String> assign;
    public static final int _ASSIGN = 1;
    private static final TField ASSIGN_FIELD_DESC = new TField("assign", TType.SET, (short)1);
        private final boolean clear;
    public static final int _CLEAR = 2;
    private static final TField CLEAR_FIELD_DESC = new TField("clear", TType.BOOL, (short)2);
        private final Set<String> add;
    public static final int _ADD = 4;
    private static final TField ADD_FIELD_DESC = new TField("add", TType.SET, (short)4);
        private final Set<String> remove;
    public static final int _REMOVE = 5;
    private static final TField REMOVE_FIELD_DESC = new TField("remove", TType.SET, (short)5);
    static {
      NAMES_TO_IDS.put("assign", 1);
      THRIFT_NAMES_TO_IDS.put("assign", 1);
      FIELD_METADATA.put(1, ASSIGN_FIELD_DESC);
      NAMES_TO_IDS.put("clear", 2);
      THRIFT_NAMES_TO_IDS.put("clear", 2);
      FIELD_METADATA.put(2, CLEAR_FIELD_DESC);
      NAMES_TO_IDS.put("add", 4);
      THRIFT_NAMES_TO_IDS.put("add", 4);
      FIELD_METADATA.put(4, ADD_FIELD_DESC);
      NAMES_TO_IDS.put("remove", 5);
      THRIFT_NAMES_TO_IDS.put("remove", 5);
      FIELD_METADATA.put(5, REMOVE_FIELD_DESC);
    }
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=1, name="assign", requiredness=Requiredness.OPTIONAL)
    public Set<String> getAssign() { return assign; }
    
    
    
    @com.facebook.swift.codec.ThriftField(value=2, name="clear", requiredness=Requiredness.NONE)
    public boolean isClear() { return clear; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=4, name="add", requiredness=Requiredness.NONE)
    public Set<String> getAdd() { return add; }
    
    
    @Nullable
    @com.facebook.swift.codec.ThriftField(value=5, name="remove", requiredness=Requiredness.NONE)
    public Set<String> getRemove() { return remove; }
    
    @java.lang.Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("assign", assign);
        helper.add("clear", clear);
        helper.add("add", add);
        helper.add("remove", remove);
        return helper.toString();
    }
    
    @java.lang.Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        MyStructField22Patch other = (MyStructField22Patch)o;
    
        return
            Objects.equals(assign, other.assign) &&
            Objects.equals(clear, other.clear) &&
            Objects.equals(add, other.add) &&
            Objects.equals(remove, other.remove) &&
            true;
    }
    
    @java.lang.Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            assign,
            clear,
            add,
            remove
        });
    }
    
    
    public static com.facebook.thrift.payload.Reader<MyStructField22Patch> asReader() {
      return MyStructField22Patch::read0;
    }
    
    public static MyStructField22Patch read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin(MyStructField22Patch.NAMES_TO_IDS, MyStructField22Patch.THRIFT_NAMES_TO_IDS, MyStructField22Patch.FIELD_METADATA);
      MyStructField22Patch.Builder builder = new MyStructField22Patch.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _ASSIGN:
          if (__field.type == TType.SET) {
            Set<String> assign;
            {
            TSet _set = oprot.readSetBegin();
            assign = new HashSet<String>(Math.max(0, _set.size));
            for (int _i = 0; (_set.size < 0) ? oprot.peekSet() : (_i < _set.size); _i++) {
                
                String _value1 = oprot.readString();
                assign.add(_value1);
            }
            oprot.readSetEnd();
            }
            builder.setAssign(assign);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _CLEAR:
          if (__field.type == TType.BOOL) {
            boolean clear = oprot.readBool();
            builder.setClear(clear);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _ADD:
          if (__field.type == TType.SET) {
            Set<String> add;
            {
            TSet _set = oprot.readSetBegin();
            add = new HashSet<String>(Math.max(0, _set.size));
            for (int _i = 0; (_set.size < 0) ? oprot.peekSet() : (_i < _set.size); _i++) {
                
                String _value1 = oprot.readString();
                add.add(_value1);
            }
            oprot.readSetEnd();
            }
            builder.setAdd(add);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _REMOVE:
          if (__field.type == TType.SET) {
            Set<String> remove;
            {
            TSet _set = oprot.readSetBegin();
            remove = new HashSet<String>(Math.max(0, _set.size));
            for (int _i = 0; (_set.size < 0) ? oprot.peekSet() : (_i < _set.size); _i++) {
                
                String _value1 = oprot.readString();
                remove.add(_value1);
            }
            oprot.readSetEnd();
            }
            builder.setRemove(remove);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(oprot, __field.type);
          break;
        }
        oprot.readFieldEnd();
      }
      oprot.readStructEnd();
      return builder.build();
    }
    
    public void write0(TProtocol oprot) throws TException {
      oprot.writeStructBegin(STRUCT_DESC);
      if (this.assign != null) {
        oprot.writeFieldBegin(ASSIGN_FIELD_DESC);
        Set<String> _iter0 = this.assign;
        oprot.writeSetBegin(new TSet(TType.STRING, _iter0.size()));
        for (String _iter1 : _iter0) {
          oprot.writeString(_iter1);
        }
        oprot.writeSetEnd();
        oprot.writeFieldEnd();
      }
      oprot.writeFieldBegin(CLEAR_FIELD_DESC);
      oprot.writeBool(this.clear);
      oprot.writeFieldEnd();
      if (this.add != null) {
        oprot.writeFieldBegin(ADD_FIELD_DESC);
        Set<String> _iter0 = this.add;
        oprot.writeSetBegin(new TSet(TType.STRING, _iter0.size()));
        for (String _iter1 : _iter0) {
          oprot.writeString(_iter1);
        }
        oprot.writeSetEnd();
        oprot.writeFieldEnd();
      }
      if (this.remove != null) {
        oprot.writeFieldBegin(REMOVE_FIELD_DESC);
        Set<String> _iter0 = this.remove;
        oprot.writeSetBegin(new TSet(TType.STRING, _iter0.size()));
        for (String _iter1 : _iter0) {
          oprot.writeString(_iter1);
        }
        oprot.writeSetEnd();
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
    private static class _MyStructField22PatchLazy {
        private static final MyStructField22Patch _DEFAULT = new MyStructField22Patch.Builder().build();
    }
    
    public static MyStructField22Patch defaultInstance() {
        return  _MyStructField22PatchLazy._DEFAULT;
    }
}
