project(lib LANGUAGES CXX)

# get srcs
file(GLOB_RECURSE sources CONFIGURE_DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/*.cpp")

# get internal headers and public headers
file(GLOB_RECURSE headers_internal CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE headers_public CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.h")
set(headers ${headers_internal} ${headers_public})

add_library(main ${sources} ${headers})
target_include_directories(main PUBLIC ${headers_public})
target_include_directories(main PRIVATE ${headers_internal})

target_link_libraries(main PRIVATE fmt::fmt-header-only doctest::doctest)
set_property(TARGET main PROPERTY CXX_STANDARD 23)
