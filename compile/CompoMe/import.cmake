set(_include_directories "")
set(_include_directories_swig "")

list(APPEND _include_directories      "./inc")
list(APPEND _include_directories_swig "./swig")

include("./compile/CompoMe/Ext_import.cmake" OPTIONAL)



###############################################################################
list(APPEND _include_directories      "/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Log/inc")
list(APPEND _include_directories_swig "/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Log/swig")
include("/home/ruhtra/compo/Test/gen/cpp_before/CompoMe_Log/compile/CompoMe_Log/Ext_import.cmake" OPTIONAL)


