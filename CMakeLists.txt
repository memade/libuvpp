cmake_minimum_required(VERSION 3.25.1)

project(libuvpp)

set(CMAKE_CXX_STANDARD 23)
# 添加预定义宏
add_definitions(-DUNICODE -D_UNICODE)

set(PLATFORM "x86")
if (CMAKE_CL_64)
set(PLATFORM x64)
else(CMAKE_CL_64)
set(PLATFORM x86)
endif(CMAKE_CL_64)

# 设置默认编译类型
set(CMAKE_CONFIGURATION_TYPES "Debug;Release;" CACHE STRING "info" FORCE)

set(SOLUTION_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../)

set(CURRENT_SOLUTION_DIR ${CMAKE_CURRENT_SOURCE_DIR})
#cmake modules path
set(GLOBAL_CMAKE_MODULES_PATH ${SOLUTION_ROOT_DIR}/cmake/modules/)

LIST(APPEND CMAKE_MODULE_PATH ${GLOBAL_CMAKE_MODULES_PATH})
include(msvc_methods)
include(OutputPathConfig)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMakeTargets")

OutputPathConfig("bin" "bin" "lib")
add_subdirectory(${CURRENT_SOLUTION_DIR}/cmake/core/)
#set_target_properties(win PROPERTIES FOLDER "shared")

add_subdirectory(${CURRENT_SOLUTION_DIR}/cmake/tests/libuvpp_test_core/)
set_target_properties(libuvpp_test_core PROPERTIES FOLDER "tests")
OutputPathConfig("")

