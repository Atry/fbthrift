/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.refs;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.codec.ThriftField.Recursiveness;
import java.util.*;
import org.apache.thrift.*;
import org.apache.thrift.async.*;
import org.apache.thrift.meta_data.*;
import org.apache.thrift.server.*;
import org.apache.thrift.transport.*;
import org.apache.thrift.protocol.*;
import org.apache.thrift.meta_data.FieldMetaData;
import org.apache.thrift.meta_data.FieldValueMetaData;
import static com.google.common.base.MoreObjects.toStringHelper;
import static com.google.common.base.MoreObjects.ToStringHelper;

@SwiftGenerated
@ThriftStruct(value="StructWithSharedConst", builder=StructWithSharedConst.Builder.class)
public final class StructWithSharedConst {
    @ThriftConstructor
    public StructWithSharedConst(
        @ThriftField(value=1, name="opt_shared_const", requiredness=Requiredness.OPTIONAL) final test.fixtures.refs.MyField optSharedConst,
        @ThriftField(value=2, name="shared_const", requiredness=Requiredness.NONE) final test.fixtures.refs.MyField sharedConst,
        @ThriftField(value=3, name="req_shared_const", requiredness=Requiredness.REQUIRED) final test.fixtures.refs.MyField reqSharedConst
    ) {
        this.optSharedConst = optSharedConst;
        this.sharedConst = sharedConst;
        this.reqSharedConst = reqSharedConst;
    }
    
    @ThriftConstructor
    protected StructWithSharedConst() {
      this.optSharedConst = null;
      this.sharedConst = null;
      this.reqSharedConst = null;
    }
    
    public static class Builder {
        private test.fixtures.refs.MyField optSharedConst;
        @ThriftField(value=1, name="opt_shared_const", requiredness=Requiredness.OPTIONAL)
        public Builder setOptSharedConst(test.fixtures.refs.MyField optSharedConst) {
            this.optSharedConst = optSharedConst;
            return this;
        }
        private test.fixtures.refs.MyField sharedConst;
        @ThriftField(value=2, name="shared_const", requiredness=Requiredness.NONE)
        public Builder setSharedConst(test.fixtures.refs.MyField sharedConst) {
            this.sharedConst = sharedConst;
            return this;
        }
        private test.fixtures.refs.MyField reqSharedConst;
        @ThriftField(value=3, name="req_shared_const", requiredness=Requiredness.REQUIRED)
        public Builder setReqSharedConst(test.fixtures.refs.MyField reqSharedConst) {
            this.reqSharedConst = reqSharedConst;
            return this;
        }
    
        public Builder() { }
        public Builder(StructWithSharedConst other) {
            this.optSharedConst = other.optSharedConst;
            this.sharedConst = other.sharedConst;
            this.reqSharedConst = other.reqSharedConst;
        }
    
        @ThriftConstructor
        public StructWithSharedConst build() {
            return new StructWithSharedConst (
                this.optSharedConst,
                this.sharedConst,
                this.reqSharedConst
            );
        }
    }
    
    private static final TStruct STRUCT_DESC = new TStruct("StructWithSharedConst");
    private final test.fixtures.refs.MyField optSharedConst;
    public static final int _OPT_SHARED_CONST = 1;
    private static final TField OPT_SHARED_CONST_FIELD_DESC = new TField("optSharedConst", TType.STRUCT, (short)1);
    private final test.fixtures.refs.MyField sharedConst;
    public static final int _SHARED_CONST = 2;
    private static final TField SHARED_CONST_FIELD_DESC = new TField("sharedConst", TType.STRUCT, (short)2);
    private final test.fixtures.refs.MyField reqSharedConst;
    public static final int _REQ_SHARED_CONST = 3;
    private static final TField REQ_SHARED_CONST_FIELD_DESC = new TField("reqSharedConst", TType.STRUCT, (short)3);

    
    @ThriftField(value=1, name="opt_shared_const", requiredness=Requiredness.OPTIONAL)
    public test.fixtures.refs.MyField getOptSharedConst() { return optSharedConst; }
        
    @ThriftField(value=2, name="shared_const", requiredness=Requiredness.NONE)
    public test.fixtures.refs.MyField getSharedConst() { return sharedConst; }
        
    @ThriftField(value=3, name="req_shared_const", requiredness=Requiredness.REQUIRED)
    public test.fixtures.refs.MyField getReqSharedConst() { return reqSharedConst; }
    
    @Override
    public String toString() {
        ToStringHelper helper = toStringHelper(this);
        helper.add("optSharedConst", optSharedConst);
        helper.add("sharedConst", sharedConst);
        helper.add("reqSharedConst", reqSharedConst);
        return helper.toString();
    }
    
    @Override
    public boolean equals(Object o) {
        if (this == o) {
            return true;
        }
        if (o == null || getClass() != o.getClass()) {
            return false;
        }
    
        StructWithSharedConst other = (StructWithSharedConst)o;
    
        return
            Objects.equals(optSharedConst, other.optSharedConst) &&
            Objects.equals(sharedConst, other.sharedConst) &&
            Objects.equals(reqSharedConst, other.reqSharedConst) &&
            true;
    }
    
    @Override
    public int hashCode() {
        return Arrays.deepHashCode(new Object[] {
            optSharedConst,
            sharedConst,
            reqSharedConst
        });
    }
    
    
      // Currently, the read0 method cannot read metadatamap for JSON styled serialization.
      // Perhaps, it will be implemented in the future!
    public static StructWithSharedConst read0(TProtocol oprot) throws TException {
      TField __field;
      oprot.readStructBegin();
      StructWithSharedConst.Builder builder = new StructWithSharedConst.Builder();
      while (true) {
        __field = oprot.readFieldBegin();
        if (__field.type == TType.STOP) { break; }
        switch (__field.id) {
        case _OPT_SHARED_CONST:
          if (__field.type == TType.STRUCT) {
            test.fixtures.refs.MyField optSharedConst = test.fixtures.refs.MyField.read0(oprot);
            builder.setOptSharedConst(optSharedConst);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _SHARED_CONST:
          if (__field.type == TType.STRUCT) {
            test.fixtures.refs.MyField sharedConst = test.fixtures.refs.MyField.read0(oprot);
            builder.setSharedConst(sharedConst);
          } else {
            TProtocolUtil.skip(oprot, __field.type);
          }
          break;
        case _REQ_SHARED_CONST:
          if (__field.type == TType.STRUCT) {
            test.fixtures.refs.MyField reqSharedConst = test.fixtures.refs.MyField.read0(oprot);
            builder.setReqSharedConst(reqSharedConst);
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
      if (this.optSharedConst != null) {
        oprot.writeFieldBegin(OPT_SHARED_CONST_FIELD_DESC);
        this.optSharedConst.write0(oprot);
        oprot.writeFieldEnd();
      }
      if (this.sharedConst != null) {
        oprot.writeFieldBegin(SHARED_CONST_FIELD_DESC);
        this.sharedConst.write0(oprot);
        oprot.writeFieldEnd();
      }
      if (this.reqSharedConst != null) {
        oprot.writeFieldBegin(REQ_SHARED_CONST_FIELD_DESC);
        this.reqSharedConst.write0(oprot);
        oprot.writeFieldEnd();
      }
      oprot.writeFieldStop();
      oprot.writeStructEnd();
    }
    
}
