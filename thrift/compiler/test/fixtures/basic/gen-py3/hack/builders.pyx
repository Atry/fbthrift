#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#
cdef class FieldWrapper_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _hack_types.FieldWrapper

    def __iter__(self):
        yield "name", self.name

cdef class SkipCodegen_Builder(thrift.py3.builder.StructBuilder):
    _struct_type = _hack_types.SkipCodegen

    def __iter__(self):
        yield "reason", self.reason
