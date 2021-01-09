set(compo_project_name "CompoMe")
set(compo_lib_name "CompoMe")

set(src_file src/Serialization_context.cpp 
src/Types/i8.cpp 
src/Types/i16.cpp 
src/Types/i32.cpp 
src/Types/i64.cpp 
src/Types/ui8.cpp 
src/Types/ui16.cpp 
src/Types/ui32.cpp 
src/Types/ui64.cpp 
src/Types/CompoMe/String.cpp 
src/Types/P.cpp 
src/Types/Vec.cpp 
src/Types/Map.cpp 
src/Types/Array.cpp 
src/Types/Pair.cpp 
src/Types/Tuple.cpp 
src/Types/Set.cpp 
src/Types/CompoMe/Struct_p.cpp 
src/Types/CompoMe/Error_p.cpp 
src/Types/CompoMe/Interface_p.cpp 
src/Types/CompoMe/Component_p.cpp 
src/Types/CompoMe/Link_p.cpp 
src/Types/CompoMe/Deployment_p.cpp 
src/Types/CompoMe/Component_state.cpp 
src/Data/CompoMe.cpp 
src/Structs/Struct.cpp 
src/Errors/Error.cpp 
src/Events/Event.cpp 
src/Bus/Bus.cpp 
src/Interfaces/Interface.cpp 
src/Interfaces/Fake_stream.cpp 
src/Interfaces/Caller_stream.cpp 
src/Interfaces/CompoMe/Component_Control/Component_Control.cpp 
src/Interfaces/CompoMe/Component_Control/Component_Control_fake_stream.cpp 
src/Interfaces/CompoMe/Component_Control/Component_Control_caller_stream.cpp 
src/Components/Component.cpp 
src/Components/CompoMe/Component_Core.cpp 
src/Components/CompoMe/Component_Core_serialization.cpp 
src/Components/CompoMe/Component_Core_function.cpp 
src/Components/CompoMe/Component_Core_get_set.cpp 
src/Components/CompoMe/Component_Core_fac.cpp 
src/Components/CompoMe/Component_Core_Component_Control_handle.cpp 
src/Components/CompoMe/Component_Core_Component_Control_handle_get_set.cpp 
src/Components/CompoMe/Component_Core_Component_Control_handle_fac.cpp 
src/Components/CompoMe/Component_Core_Component_Control_handle_function.cpp 
src/Links/Link.cpp 
src/Deployments/Deployment.cpp)

set(inc_file inc/Serialization_context.hpp 
inc/Types/i8.hpp 
inc/Types/i16.hpp 
inc/Types/i32.hpp 
inc/Types/i64.hpp 
inc/Types/ui8.hpp 
inc/Types/ui16.hpp 
inc/Types/ui32.hpp 
inc/Types/ui64.hpp 
inc/Types/CompoMe/String.hpp 
inc/Types/P.hpp 
inc/Types/Vec.hpp 
inc/Types/Map.hpp 
inc/Types/Array.hpp 
inc/Types/Pair.hpp 
inc/Types/Tuple.hpp 
inc/Types/Set.hpp 
inc/Types/CompoMe/Struct_p.hpp 
inc/Types/CompoMe/Error_p.hpp 
inc/Types/CompoMe/Interface_p.hpp 
inc/Types/CompoMe/Component_p.hpp 
inc/Types/CompoMe/Link_p.hpp 
inc/Types/CompoMe/Deployment_p.hpp 
inc/Types/CompoMe/Component_state.hpp 
inc/Data/CompoMe.hpp 
inc/Structs/Struct.hpp 
inc/Errors/Error.hpp 
inc/Events/Event.hpp 
inc/Bus/Bus.hpp 
inc/Interfaces/Interface.hpp 
inc/Interfaces/Fake_stream.hpp 
inc/Interfaces/Caller_stream.hpp 
inc/Interfaces/Return_stream_send.hpp 
inc/Interfaces/Return_stream_recv.hpp 
inc/Interfaces/Function_stream_send.hpp 
inc/Interfaces/Function_stream_recv.hpp 
inc/Interfaces/CompoMe/Component_Control/Component_Control.hpp 
inc/Interfaces/CompoMe/Component_Control/Component_Control_fake_stream.hpp 
inc/Interfaces/CompoMe/Component_Control/Component_Control_caller_stream.hpp 
inc/Components/Component.hpp 
inc/Components/Require_helper.hpp 
inc/Components/Require_helper_multi.hpp 
inc/Components/CompoMe/Component_Core.hpp 
inc/Components/CompoMe/Component_Core_fac.hpp 
inc/Components/CompoMe/Component_Core_Component_Control_handle.hpp 
inc/Links/Link.hpp 
inc/Deployments/Deployment.hpp)

set(swig_file )

list(APPEND CMAKE_MODULE_PATH "compile")
list(APPEND CMAKE_MODULE_PATH $ENV{COMPOME_PATH}/tool)
message($ENV{COMPOME_PATH}/tool)

include(${CMAKE_CURRENT_LIST_DIR}/Int_var.cmake OPTIONAL)
