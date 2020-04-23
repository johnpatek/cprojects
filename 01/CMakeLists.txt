cmake_minimum_required(VERSION 2.8)

project(cprojects01)

if(WIN32)

else()
    set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wpedantic -O3" )
endif()

set(COMMON ${CMAKE_SOURCE_DIR}/../common/install)
set(COMMON_INCLUDE ${COMMON}/include)
set(COMMON_LIB ${COMMON}/lib)
set(IOCOLORS ${CMAKE_SOURCE_DIR}/../common/iocolors/build/install)
set(IOCOLORS_INCLUDE ${IOCOLORS}/include)
set(IOCOLORS_LIB ${IOCOLORS}/lib)

set(PROJECT_INCLUDE ${CMAKE_SOURCE_DIR}/include)

include_directories(${COMMON_INCLUDE} ${PROJECT_INCLUDE})

link_directories(${COMMON_LIB} ${IOCOLORS_LIB})

file(GLOB UNIT_TEST_SOURCES
    "test/*.c"
    "include/*.h"    
    "src/*.c"
)

add_executable(unittest ${UNIT_TEST_SOURCES})

target_include_directories(unittest PUBLIC ${COMMON_INCLUDE} ${PROJECT_INCLUDE} ${IOCOLORS_INCLUDE})

target_link_libraries(unittest common iocolors)