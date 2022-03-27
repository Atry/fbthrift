/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
package test.fixtures.patch;

import java.util.List;
import java.util.ArrayList;
import java.util.Map;
import java.util.HashMap;
import java.util.Set;
import java.util.HashSet;
import java.util.Collections;
import java.util.BitSet;
import java.util.Arrays;
import com.facebook.thrift.*;
import com.facebook.thrift.annotations.*;
import com.facebook.thrift.async.*;
import com.facebook.thrift.meta_data.*;
import com.facebook.thrift.server.*;
import com.facebook.thrift.transport.*;
import com.facebook.thrift.protocol.*;

@SuppressWarnings({ "unused", "serial" })
public class MyStructField22Patch implements TBase, java.io.Serializable, Cloneable, Comparable<MyStructField22Patch> {
  private static final TStruct STRUCT_DESC = new TStruct("MyStructField22Patch");
  private static final TField ASSIGN_FIELD_DESC = new TField("assign", TType.SET, (short)1);
  private static final TField CLEAR_FIELD_DESC = new TField("clear", TType.BOOL, (short)2);
  private static final TField ADD_FIELD_DESC = new TField("add", TType.SET, (short)4);
  private static final TField REMOVE_FIELD_DESC = new TField("remove", TType.SET, (short)5);

  /**
   * Assigns to a given struct. If set, all other operations are ignored.
   */
  public Set<String> assign;
  /**
   * Clears a given value. Applies first.
   */
  public boolean clear;
  /**
   * Adds entries, if not already present. Currently Ignored.
   */
  public Set<String> add;
  /**
   * Removes entries, if present. Currently Ignored.
   */
  public Set<String> remove;
  public static final int ASSIGN = 1;
  public static final int CLEAR = 2;
  public static final int ADD = 4;
  public static final int REMOVE = 5;

  // isset id assignments
  private static final int __CLEAR_ISSET_ID = 0;
  private BitSet __isset_bit_vector = new BitSet(1);

  public static final Map<Integer, FieldMetaData> metaDataMap;

  static {
    Map<Integer, FieldMetaData> tmpMetaDataMap = new HashMap<Integer, FieldMetaData>();
    tmpMetaDataMap.put(ASSIGN, new FieldMetaData("assign", TFieldRequirementType.OPTIONAL, 
        new SetMetaData(TType.SET, 
            new FieldValueMetaData(TType.STRING))));
    tmpMetaDataMap.put(CLEAR, new FieldMetaData("clear", TFieldRequirementType.DEFAULT, 
        new FieldValueMetaData(TType.BOOL)));
    tmpMetaDataMap.put(ADD, new FieldMetaData("add", TFieldRequirementType.DEFAULT, 
        new SetMetaData(TType.SET, 
            new FieldValueMetaData(TType.STRING))));
    tmpMetaDataMap.put(REMOVE, new FieldMetaData("remove", TFieldRequirementType.DEFAULT, 
        new SetMetaData(TType.SET, 
            new FieldValueMetaData(TType.STRING))));
    metaDataMap = Collections.unmodifiableMap(tmpMetaDataMap);
  }

  static {
    FieldMetaData.addStructMetaDataMap(MyStructField22Patch.class, metaDataMap);
  }

  public MyStructField22Patch() {
  }

  public MyStructField22Patch(
      boolean clear,
      Set<String> add,
      Set<String> remove) {
    this();
    this.clear = clear;
    setClearIsSet(true);
    this.add = add;
    this.remove = remove;
  }

  public MyStructField22Patch(
      Set<String> assign,
      boolean clear,
      Set<String> add,
      Set<String> remove) {
    this();
    this.assign = assign;
    this.clear = clear;
    setClearIsSet(true);
    this.add = add;
    this.remove = remove;
  }

  public static class Builder {
    private Set<String> assign;
    private boolean clear;
    private Set<String> add;
    private Set<String> remove;

    BitSet __optional_isset = new BitSet(1);

    public Builder() {
    }

    public Builder setAssign(final Set<String> assign) {
      this.assign = assign;
      return this;
    }

    public Builder setClear(final boolean clear) {
      this.clear = clear;
      __optional_isset.set(__CLEAR_ISSET_ID, true);
      return this;
    }

    public Builder setAdd(final Set<String> add) {
      this.add = add;
      return this;
    }

    public Builder setRemove(final Set<String> remove) {
      this.remove = remove;
      return this;
    }

    public MyStructField22Patch build() {
      MyStructField22Patch result = new MyStructField22Patch();
      result.setAssign(this.assign);
      if (__optional_isset.get(__CLEAR_ISSET_ID)) {
        result.setClear(this.clear);
      }
      result.setAdd(this.add);
      result.setRemove(this.remove);
      return result;
    }
  }

  public static Builder builder() {
    return new Builder();
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public MyStructField22Patch(MyStructField22Patch other) {
    __isset_bit_vector.clear();
    __isset_bit_vector.or(other.__isset_bit_vector);
    if (other.isSetAssign()) {
      this.assign = TBaseHelper.deepCopy(other.assign);
    }
    this.clear = TBaseHelper.deepCopy(other.clear);
    if (other.isSetAdd()) {
      this.add = TBaseHelper.deepCopy(other.add);
    }
    if (other.isSetRemove()) {
      this.remove = TBaseHelper.deepCopy(other.remove);
    }
  }

  public MyStructField22Patch deepCopy() {
    return new MyStructField22Patch(this);
  }

  /**
   * Assigns to a given struct. If set, all other operations are ignored.
   */
  public Set<String> getAssign() {
    return this.assign;
  }

  /**
   * Assigns to a given struct. If set, all other operations are ignored.
   */
  public MyStructField22Patch setAssign(Set<String> assign) {
    this.assign = assign;
    return this;
  }

  public void unsetAssign() {
    this.assign = null;
  }

  // Returns true if field assign is set (has been assigned a value) and false otherwise
  public boolean isSetAssign() {
    return this.assign != null;
  }

  public void setAssignIsSet(boolean __value) {
    if (!__value) {
      this.assign = null;
    }
  }

  /**
   * Clears a given value. Applies first.
   */
  public boolean isClear() {
    return this.clear;
  }

  /**
   * Clears a given value. Applies first.
   */
  public MyStructField22Patch setClear(boolean clear) {
    this.clear = clear;
    setClearIsSet(true);
    return this;
  }

  public void unsetClear() {
    __isset_bit_vector.clear(__CLEAR_ISSET_ID);
  }

  // Returns true if field clear is set (has been assigned a value) and false otherwise
  public boolean isSetClear() {
    return __isset_bit_vector.get(__CLEAR_ISSET_ID);
  }

  public void setClearIsSet(boolean __value) {
    __isset_bit_vector.set(__CLEAR_ISSET_ID, __value);
  }

  /**
   * Adds entries, if not already present. Currently Ignored.
   */
  public Set<String> getAdd() {
    return this.add;
  }

  /**
   * Adds entries, if not already present. Currently Ignored.
   */
  public MyStructField22Patch setAdd(Set<String> add) {
    this.add = add;
    return this;
  }

  public void unsetAdd() {
    this.add = null;
  }

  // Returns true if field add is set (has been assigned a value) and false otherwise
  public boolean isSetAdd() {
    return this.add != null;
  }

  public void setAddIsSet(boolean __value) {
    if (!__value) {
      this.add = null;
    }
  }

  /**
   * Removes entries, if present. Currently Ignored.
   */
  public Set<String> getRemove() {
    return this.remove;
  }

  /**
   * Removes entries, if present. Currently Ignored.
   */
  public MyStructField22Patch setRemove(Set<String> remove) {
    this.remove = remove;
    return this;
  }

  public void unsetRemove() {
    this.remove = null;
  }

  // Returns true if field remove is set (has been assigned a value) and false otherwise
  public boolean isSetRemove() {
    return this.remove != null;
  }

  public void setRemoveIsSet(boolean __value) {
    if (!__value) {
      this.remove = null;
    }
  }

  @SuppressWarnings("unchecked")
  public void setFieldValue(int fieldID, Object __value) {
    switch (fieldID) {
    case ASSIGN:
      if (__value == null) {
        unsetAssign();
      } else {
        setAssign((Set<String>)__value);
      }
      break;

    case CLEAR:
      if (__value == null) {
        unsetClear();
      } else {
        setClear((Boolean)__value);
      }
      break;

    case ADD:
      if (__value == null) {
        unsetAdd();
      } else {
        setAdd((Set<String>)__value);
      }
      break;

    case REMOVE:
      if (__value == null) {
        unsetRemove();
      } else {
        setRemove((Set<String>)__value);
      }
      break;

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  public Object getFieldValue(int fieldID) {
    switch (fieldID) {
    case ASSIGN:
      return getAssign();

    case CLEAR:
      return new Boolean(isClear());

    case ADD:
      return getAdd();

    case REMOVE:
      return getRemove();

    default:
      throw new IllegalArgumentException("Field " + fieldID + " doesn't exist!");
    }
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof MyStructField22Patch))
      return false;
    MyStructField22Patch that = (MyStructField22Patch)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetAssign(), that.isSetAssign(), this.assign, that.assign)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.clear, that.clear)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAdd(), that.isSetAdd(), this.add, that.add)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetRemove(), that.isSetRemove(), this.remove, that.remove)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {assign, clear, add, remove});
  }

  @Override
  public int compareTo(MyStructField22Patch other) {
    if (other == null) {
      // See java.lang.Comparable docs
      throw new NullPointerException();
    }

    if (other == this) {
      return 0;
    }
    int lastComparison = 0;

    lastComparison = Boolean.valueOf(isSetAssign()).compareTo(other.isSetAssign());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(assign, other.assign);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetClear()).compareTo(other.isSetClear());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(clear, other.clear);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetAdd()).compareTo(other.isSetAdd());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(add, other.add);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    lastComparison = Boolean.valueOf(isSetRemove()).compareTo(other.isSetRemove());
    if (lastComparison != 0) {
      return lastComparison;
    }
    lastComparison = TBaseHelper.compareTo(remove, other.remove);
    if (lastComparison != 0) { 
      return lastComparison;
    }
    return 0;
  }

  public void read(TProtocol iprot) throws TException {
    TField __field;
    iprot.readStructBegin(metaDataMap);
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case ASSIGN:
          if (__field.type == TType.SET) {
            {
              TSet _set29 = iprot.readSetBegin();
              this.assign = new HashSet<String>(Math.max(0, 2*_set29.size));
              for (int _i30 = 0; 
                   (_set29.size < 0) ? iprot.peekSet() : (_i30 < _set29.size); 
                   ++_i30)
              {
                String _elem31;
                _elem31 = iprot.readString();
                this.assign.add(_elem31);
              }
              iprot.readSetEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case CLEAR:
          if (__field.type == TType.BOOL) {
            this.clear = iprot.readBool();
            setClearIsSet(true);
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case ADD:
          if (__field.type == TType.SET) {
            {
              TSet _set32 = iprot.readSetBegin();
              this.add = new HashSet<String>(Math.max(0, 2*_set32.size));
              for (int _i33 = 0; 
                   (_set32.size < 0) ? iprot.peekSet() : (_i33 < _set32.size); 
                   ++_i33)
              {
                String _elem34;
                _elem34 = iprot.readString();
                this.add.add(_elem34);
              }
              iprot.readSetEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case REMOVE:
          if (__field.type == TType.SET) {
            {
              TSet _set35 = iprot.readSetBegin();
              this.remove = new HashSet<String>(Math.max(0, 2*_set35.size));
              for (int _i36 = 0; 
                   (_set35.size < 0) ? iprot.peekSet() : (_i36 < _set35.size); 
                   ++_i36)
              {
                String _elem37;
                _elem37 = iprot.readString();
                this.remove.add(_elem37);
              }
              iprot.readSetEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        default:
          TProtocolUtil.skip(iprot, __field.type);
          break;
      }
      iprot.readFieldEnd();
    }
    iprot.readStructEnd();


    // check for required fields of primitive type, which can't be checked in the validate method
    validate();
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.assign != null) {
      if (isSetAssign()) {
        oprot.writeFieldBegin(ASSIGN_FIELD_DESC);
        {
          oprot.writeSetBegin(new TSet(TType.STRING, this.assign.size()));
          for (String _iter38 : this.assign)          {
            oprot.writeString(_iter38);
          }
          oprot.writeSetEnd();
        }
        oprot.writeFieldEnd();
      }
    }
    oprot.writeFieldBegin(CLEAR_FIELD_DESC);
    oprot.writeBool(this.clear);
    oprot.writeFieldEnd();
    if (this.add != null) {
      oprot.writeFieldBegin(ADD_FIELD_DESC);
      {
        oprot.writeSetBegin(new TSet(TType.STRING, this.add.size()));
        for (String _iter39 : this.add)        {
          oprot.writeString(_iter39);
        }
        oprot.writeSetEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.remove != null) {
      oprot.writeFieldBegin(REMOVE_FIELD_DESC);
      {
        oprot.writeSetBegin(new TSet(TType.STRING, this.remove.size()));
        for (String _iter40 : this.remove)        {
          oprot.writeString(_iter40);
        }
        oprot.writeSetEnd();
      }
      oprot.writeFieldEnd();
    }
    oprot.writeFieldStop();
    oprot.writeStructEnd();
  }

  @Override
  public String toString() {
    return toString(1, true);
  }

  @Override
  public String toString(int indent, boolean prettyPrint) {
    String indentStr = prettyPrint ? TBaseHelper.getIndentedString(indent) : "";
    String newLine = prettyPrint ? "\n" : "";
    String space = prettyPrint ? " " : "";
    StringBuilder sb = new StringBuilder("MyStructField22Patch");
    sb.append(space);
    sb.append("(");
    sb.append(newLine);
    boolean first = true;

    if (isSetAssign())
    {
      sb.append(indentStr);
      sb.append("assign");
      sb.append(space);
      sb.append(":").append(space);
      if (this.getAssign() == null) {
        sb.append("null");
      } else {
        sb.append(TBaseHelper.toString(this.getAssign(), indent + 1, prettyPrint));
      }
      first = false;
    }
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("clear");
    sb.append(space);
    sb.append(":").append(space);
    sb.append(TBaseHelper.toString(this.isClear(), indent + 1, prettyPrint));
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("add");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getAdd() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getAdd(), indent + 1, prettyPrint));
    }
    first = false;
    if (!first) sb.append("," + newLine);
    sb.append(indentStr);
    sb.append("remove");
    sb.append(space);
    sb.append(":").append(space);
    if (this.getRemove() == null) {
      sb.append("null");
    } else {
      sb.append(TBaseHelper.toString(this.getRemove(), indent + 1, prettyPrint));
    }
    first = false;
    sb.append(newLine + TBaseHelper.reduceIndent(indentStr));
    sb.append(")");
    return sb.toString();
  }

  public void validate() throws TException {
    // check for required fields
  }

}

