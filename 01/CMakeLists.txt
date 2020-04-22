cmake_minimum_required(VERSION 2.8)

project(cprojects01)

if(WIN32)

else()
    set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wpedantic -O3" )
endif()

set(COMMON "${CMAKE_SOURCE_DIR}/../common/install")
find_path(COMMON_INLCUDE NAMES test.h HINTS "${COMMON}/include")
message(${COMMON_INLCUDE})
set(COMMON_LIB "${COMMON}/lib")
message(${COMMON_LIB})

set(PROJECT_INCLUDE "${CMAKE_SOURCE_DIR}/include")

include_directories(${COMMON_INCLUDE} ${PROJECT_INCLUDE})

link_directories(${COMMON_LIB})

add_executable(unittest test/unittest.c src/file.c)

target_include_directories(unittest PUBLIC ${COMMON_INCLUDE} ${PROJECT_INCLUDE})

target_link_libraries(unittest common)