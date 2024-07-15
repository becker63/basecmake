project(lib LANGUAGES CXX)

# get srcs
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# get internal headers and public headers
file(GLOB_RECURSE headers_public CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE headers_internal CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.h")
set(headers ${headers_internal} ${headers_public})

add_library(main ${sources} ${headers})

target_link_libraries(main PRIVATE fmt::fmt-header-only doctest::doctest)
set_property(TARGET main PROPERTY CXX_STANDARD 23)

include(CMakePrintHelpers)
cmake_print_variables(headers_public)

# include public lib interface
target_include_directories(main PUBLIC "${CMAKE_SOURCE_DIR}/include/public")
