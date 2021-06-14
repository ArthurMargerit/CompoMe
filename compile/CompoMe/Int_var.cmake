LIST(APPEND inc_file "inc/Types/CompoMe/String_d.hpp")
LIST(APPEND src_file "src/Types/CompoMe/String_d.cpp")

LIST(APPEND inc_file "inc/Interfaces/Function_stream_send_func.hpp")
LIST(APPEND src_file "src/Interfaces/Function_stream_send_func.cpp")

LIST(APPEND inc_file "inc/Interfaces/Return_stream_recv_func.hpp")
LIST(APPEND src_file "src/Interfaces/Return_stream_recv_func.cpp")

FILE(GLOB_RECURSE src_file_component "src/Components/CompoMe/Component_Core*.cpp" )

LIST(APPEND src_file ${src_file_component})
