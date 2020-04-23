cmake_minimum_required(VERSION 2.8)

project(common)

if(WIN32)

else()
    set(CMAKE_CXX_FLAGS "-Wall -Werror -Wextra -Wpedantic -O3" )
endif()

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR}/install)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

set(IOCOLORS ${PROJECT_SOURCE_DIR}/iocolors/build/install)
set(IOCOLORS_INCLUDE ${IOCOLORS}/include)
set(IOCOLORS_LIB ${IOCOLORS}/lib)

link_directories(${IOCOLORS_LIB})
include_directories(include ${IOCOLORS_INCLUDE})

add_library(common src/test.c)
set_property(TARGET common PROPERTY POSITION_INDEPENDENT_CODE ON)
target_include_directories(common PUBLIC include ${IOCOLORS_INCLUDE})
target_link_libraries(common iocolors)

install(TARGETS common
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)

install(DIRECTORY include/ 
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
        PATTERN "include/*.h")