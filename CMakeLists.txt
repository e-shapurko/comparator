cmake_minimum_required(VERSION 3.2)

project(comparator VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(comparator main.cpp)

add_library(pars_lib pars.h)

add_executable(test_comparator test_comparator.cpp)

set_target_properties(comparator pars_lib test_comparator PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
)

set_target_properties(test_comparator PROPERTIES
    COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
    INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
) 

target_link_libraries(comparator
    comparator_lib
)

target_link_libraries(test_comparator
	${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
)

target_link_libraries(test_comparator
    ${Boost_LIBRARIES}
    comparator_lib
)

install(TARGETS comparator RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT e.shapurko@gmail.com)

set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

include(CPack)

enable_testing()

add_test(ip_filter_tests test_ip_filter)
