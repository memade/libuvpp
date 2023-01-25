project(libuvpp_test_core)

set(SOURCES_DIR ${CURRENT_SOLUTION_DIR}/tests/${PROJECT_NAME}/)

set(SOURCES
${SOURCES_DIR}main.cpp
)

# Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

MSVC_SET_LINK_FLAG_CONSOLE(${PROJECT_NAME})

# 指定专用库头文件目录
target_include_directories(${PROJECT_NAME} 
PRIVATE 
${SOLUTION_ROOT_DIR}/3rdparty/spdlog/include/)
# 依赖库目录
target_link_directories(${PROJECT_NAME} 
PRIVATE 
${SOLUTION_ROOT_DIR}/librarys/${VS_PLATFORM}/
)






