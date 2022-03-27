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
public class MyStructField21Patch implements TBase, java.io.Serializable, Cloneable {
  private static final TStruct STRUCT_DESC = new TStruct("MyStructField21Patch");
  private static final TField ASSIGN_FIELD_DESC = new TField("assign", TType.LIST, (short)1);
  private static final TField CLEAR_FIELD_DESC = new TField("clear", TType.BOOL, (short)2);
  private static final TField APPEND_FIELD_DESC = new TField("append", TType.LIST, (short)4);
  private static final TField PREPEND_FIELD_DESC = new TField("prepend", TType.LIST, (short)5);

  /**
   * Assigns to a given struct. If set, all other operations are ignored.
   */
  public final List<Short> assign;
  /**
   * Clears a given value. Applies first.
   */
  public final Boolean clear;
  /**
   * Appends to a given list. Currently Ignored.
   */
  public final List<Short> append;
  /**
   * Prepends to a given list. Currently Ignored.
   */
  public final List<Short> prepend;
  public static final int ASSIGN = 1;
  public static final int CLEAR = 2;
  public static final int APPEND = 4;
  public static final int PREPEND = 5;

  public MyStructField21Patch(
      List<Short> assign,
      Boolean clear,
      List<Short> append,
      List<Short> prepend) {
    this.assign = assign;
    this.clear = clear;
    this.append = append;
    this.prepend = prepend;
  }

  /**
   * Performs a deep copy on <i>other</i>.
   */
  public MyStructField21Patch(MyStructField21Patch other) {
    if (other.isSetAssign()) {
      this.assign = TBaseHelper.deepCopy(other.assign);
    } else {
      this.assign = null;
    }
    if (other.isSetClear()) {
      this.clear = TBaseHelper.deepCopy(other.clear);
    } else {
      this.clear = null;
    }
    if (other.isSetAppend()) {
      this.append = TBaseHelper.deepCopy(other.append);
    } else {
      this.append = null;
    }
    if (other.isSetPrepend()) {
      this.prepend = TBaseHelper.deepCopy(other.prepend);
    } else {
      this.prepend = null;
    }
  }

  public MyStructField21Patch deepCopy() {
    return new MyStructField21Patch(this);
  }

  /**
   * Assigns to a given struct. If set, all other operations are ignored.
   */
  public List<Short> getAssign() {
    return this.assign;
  }

  // Returns true if field assign is set (has been assigned a value) and false otherwise
  public boolean isSetAssign() {
    return this.assign != null;
  }

  /**
   * Clears a given value. Applies first.
   */
  public Boolean isClear() {
    return this.clear;
  }

  // Returns true if field clear is set (has been assigned a value) and false otherwise
  public boolean isSetClear() {
    return this.clear != null;
  }

  /**
   * Appends to a given list. Currently Ignored.
   */
  public List<Short> getAppend() {
    return this.append;
  }

  // Returns true if field append is set (has been assigned a value) and false otherwise
  public boolean isSetAppend() {
    return this.append != null;
  }

  /**
   * Prepends to a given list. Currently Ignored.
   */
  public List<Short> getPrepend() {
    return this.prepend;
  }

  // Returns true if field prepend is set (has been assigned a value) and false otherwise
  public boolean isSetPrepend() {
    return this.prepend != null;
  }

  @Override
  public boolean equals(Object _that) {
    if (_that == null)
      return false;
    if (this == _that)
      return true;
    if (!(_that instanceof MyStructField21Patch))
      return false;
    MyStructField21Patch that = (MyStructField21Patch)_that;

    if (!TBaseHelper.equalsNobinary(this.isSetAssign(), that.isSetAssign(), this.assign, that.assign)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetClear(), that.isSetClear(), this.clear, that.clear)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetAppend(), that.isSetAppend(), this.append, that.append)) { return false; }

    if (!TBaseHelper.equalsNobinary(this.isSetPrepend(), that.isSetPrepend(), this.prepend, that.prepend)) { return false; }

    return true;
  }

  @Override
  public int hashCode() {
    return Arrays.deepHashCode(new Object[] {assign, clear, append, prepend});
  }

  // This is required to satisfy the TBase interface, but can't be implemented on immutable struture.
  public void read(TProtocol iprot) throws TException {
    throw new TException("unimplemented in android immutable structure");
  }

  public static MyStructField21Patch deserialize(TProtocol iprot) throws TException {
    List<Short> tmp_assign = null;
    Boolean tmp_clear = null;
    List<Short> tmp_append = null;
    List<Short> tmp_prepend = null;
    TField __field;
    iprot.readStructBegin();
    while (true)
    {
      __field = iprot.readFieldBegin();
      if (__field.type == TType.STOP) {
        break;
      }
      switch (__field.id)
      {
        case ASSIGN:
          if (__field.type == TType.LIST) {
            {
              TList _list13 = iprot.readListBegin();
              tmp_assign = new ArrayList<Short>(Math.max(0, _list13.size));
              for (int _i14 = 0; 
                   (_list13.size < 0) ? iprot.peekList() : (_i14 < _list13.size); 
                   ++_i14)
              {
                Short _elem15;
                _elem15 = iprot.readI16();
                tmp_assign.add(_elem15);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case CLEAR:
          if (__field.type == TType.BOOL) {
            tmp_clear = iprot.readBool();
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case APPEND:
          if (__field.type == TType.LIST) {
            {
              TList _list16 = iprot.readListBegin();
              tmp_append = new ArrayList<Short>(Math.max(0, _list16.size));
              for (int _i17 = 0; 
                   (_list16.size < 0) ? iprot.peekList() : (_i17 < _list16.size); 
                   ++_i17)
              {
                Short _elem18;
                _elem18 = iprot.readI16();
                tmp_append.add(_elem18);
              }
              iprot.readListEnd();
            }
          } else {
            TProtocolUtil.skip(iprot, __field.type);
          }
          break;
        case PREPEND:
          if (__field.type == TType.LIST) {
            {
              TList _list19 = iprot.readListBegin();
              tmp_prepend = new ArrayList<Short>(Math.max(0, _list19.size));
              for (int _i20 = 0; 
                   (_list19.size < 0) ? iprot.peekList() : (_i20 < _list19.size); 
                   ++_i20)
              {
                Short _elem21;
                _elem21 = iprot.readI16();
                tmp_prepend.add(_elem21);
              }
              iprot.readListEnd();
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

    MyStructField21Patch _that;
    _that = new MyStructField21Patch(
      tmp_assign
      ,tmp_clear
      ,tmp_append
      ,tmp_prepend
    );
    _that.validate();
    return _that;
  }

  public void write(TProtocol oprot) throws TException {
    validate();

    oprot.writeStructBegin(STRUCT_DESC);
    if (this.assign != null) {
      if (isSetAssign()) {
        oprot.writeFieldBegin(ASSIGN_FIELD_DESC);
        {
          oprot.writeListBegin(new TList(TType.I16, this.assign.size()));
          for (Short _iter22 : this.assign)          {
            oprot.writeI16(_iter22);
          }
          oprot.writeListEnd();
        }
        oprot.writeFieldEnd();
      }
    }
    if (this.clear != null) {
      oprot.writeFieldBegin(CLEAR_FIELD_DESC);
      oprot.writeBool(this.clear);
      oprot.writeFieldEnd();
    }
    if (this.append != null) {
      oprot.writeFieldBegin(APPEND_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.I16, this.append.size()));
        for (Short _iter23 : this.append)        {
          oprot.writeI16(_iter23);
        }
        oprot.writeListEnd();
      }
      oprot.writeFieldEnd();
    }
    if (this.prepend != null) {
      oprot.writeFieldBegin(PREPEND_FIELD_DESC);
      {
        oprot.writeListBegin(new TList(TType.I16, this.prepend.size()));
        for (Short _iter24 : this.prepend)        {
          oprot.writeI16(_iter24);
        }
        oprot.writeListEnd();
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
    return TBaseHelper.toStringHelper(this, indent, prettyPrint);
  }

  public void validate() throws TException {
    // check for required fields
  }

}

