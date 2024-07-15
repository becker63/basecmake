project(tests LANGUAGES CXX)

# get srcs
FILE(GLOB_RECURSE lib_src CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp )

# compile and link
add_executable(tester testmain.cpp ${lib_src})
target_link_libraries(tester doctest::doctest main)
set_property(TARGET main PROPERTY CXX_STANDARD 23)

# get include dirs
file(GLOB_RECURSE headers_internal CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE headers_public CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.h")
set(headers ${headers_internal} ${headers_public})

# this aint great
set(doctestcmakefilesrc "${VCPKG_INSTALLED_DIR}/${VCPKG_TARGET_TRIPLET}/share/doctest/doctest.cmake")

# do the doctest stuff
include(${doctestcmakefilesrc})
doctest_discover_tests(tester)

# ctest stuff
enable_testing()
add_test(NAME doctest COMMAND tester --config $<CONFIG>)
