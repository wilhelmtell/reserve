cmake_minimum_required(VERSION 3.2.2)
project(reserve VERSION 0.0.0.1)

add_library(reserve_lib
            src/dummy.hh src/dummy.cc
            src/reserve.hh src/reserve.tcc)
add_executable(check_reserve
               test/main.cc
               test/dummy.cc
               test/reserve.cc)
add_executable(reserve_bin src/main.cc)
add_custom_target(check
                  COMMAND check_reserve
                  DEPENDS check_reserve
                  WORKING_DIRECTORY "${PROJECT_BINARY_DIR}"
                  COMMENT "Running unit tests")

configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
)

set_target_properties(reserve_lib reserve_bin PROPERTIES
                      OUTPUT_NAME reserve)
set_target_properties(check_reserve PROPERTIES OUTPUT_NAME check_reserve)
set_target_properties(reserve_lib reserve_bin check_reserve PROPERTIES
                      CXX_STANDARD 14
                      CXX_STANDARD_REQUIRED true
                      CXX_EXTENSIONS false)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -pedantic -Werror")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

find_package(Boost 1.57.0 REQUIRED)
if(BOOST_FOUND)
  include_directories("${Boost_INCLUDE_DIRS}")
  link_libraries("${Boost_LIBRARIES}")
endif()

include_directories("${PROJECT_BINARY_DIR}")

target_link_libraries(reserve_bin reserve_lib)
target_link_libraries(check_reserve reserve_lib)

install(TARGETS reserve_bin DESTINATION bin)
