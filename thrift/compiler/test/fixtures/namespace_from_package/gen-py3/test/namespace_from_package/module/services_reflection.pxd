#
# Autogenerated by Thrift
#
# DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
#  @generated
#

from thrift.py3.reflection cimport (
  InterfaceSpec as __InterfaceSpec,
)


cdef __InterfaceSpec get_reflection__TestService(bint for_clients)

cdef extern from "src/gen-cpp2/TestService.h" namespace "::test::namespace_from_package::module":
    cdef cppclass cTestServiceSvIf "::test::namespace_from_package::module::TestServiceSvIf":
        pass
