# Copyright  (c) 2016-2025 Antony Polukhin
# Distributed under the Boost Software License, Version 1.0.
# See accompanying file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt

cmake_minimum_required(VERSION 3.5...4.0)

project(lexical_cast_subdir_test LANGUAGES CXX)

add_subdirectory(../../../array boostorg/array)
add_subdirectory(../../../assert boostorg/assert)
add_subdirectory(../../../compat boostorg/compat)
add_subdirectory(../../../conversion boostorg/conversion)
add_subdirectory(../../../core boostorg/core)
add_subdirectory(../../../config boostorg/config)
add_subdirectory(../../../container boostorg/container)
add_subdirectory(../../../container_hash boostorg/container_hash)
add_subdirectory(../../../describe boostorg/describe)
add_subdirectory(../../../detail boostorg/detail)
add_subdirectory(../../../exception boostorg/exception)
add_subdirectory(../../../io boostorg/io)
add_subdirectory(../../../iterator boostorg/iterator)
add_subdirectory(../../../integer boostorg/integer)
add_subdirectory(../../../intrusive boostorg/intrusive)
add_subdirectory(../../../move boostorg/move)
add_subdirectory(../../../mp11 boostorg/mp11)
add_subdirectory(../../../mpl boostorg/mpl)
add_subdirectory(../../../predef boostorg/predef)
add_subdirectory(../../../preprocessor boostorg/preprocessor)
add_subdirectory(../../../static_assert boostorg/static_assert)
add_subdirectory(../../../throw_exception boostorg/throw_exception)
add_subdirectory(../../../type_index boostorg/type_index)
add_subdirectory(../../../type_traits boostorg/type_traits)
add_subdirectory(../../../utility boostorg/utility)

add_subdirectory(../../ boostorg/lexical_cast)

enable_testing()

#if (BOOST_USE_MODULES)
#    add_executable(boost_any_module_usage ../modules/usage_sample.cpp)
#    target_link_libraries(boost_any_module_usage PRIVATE Boost::any)
#    add_test(NAME boost_any_module_usage COMMAND boost_any_module_usage)
#endif()

list(APPEND RUN_TESTS_SOURCES
    lexical_cast_test.cpp
    loopback_test.cpp
    abstract_test.cpp
    noncopyable_test.cpp
    vc8_bug_test.cpp
    implicit_convert.cpp
    float_types_test.cpp
    inf_nan_test.cpp
    containers_test.cpp
    pointers_test.cpp
    integral_types_test.cpp
    stream_detection_test.cpp
    try_lexical_convert.cpp
)

foreach (testsourcefile ${RUN_TESTS_SOURCES})
    get_filename_component(testname ${testsourcefile} NAME_WLE)
    add_executable(${PROJECT_NAME}_${testname} ../${testsourcefile})
    target_link_libraries(${PROJECT_NAME}_${testname} Boost::lexical_cast Boost::type_traits Boost::core)
    add_test(NAME ${PROJECT_NAME}_${testname} COMMAND ${PROJECT_NAME}_${testname})
endforeach()

