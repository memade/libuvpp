project(libuvpp)

set(SOURCES_DIR ${CURRENT_SOLUTION_DIR}/src/core/)

set(SOURCES
${SOURCES_DIR}dllmain.cpp
${SOURCES_DIR}libuv.cpp
${SOURCES_DIR}libuv.h
${SOURCES_DIR}libuvpp.def
${SOURCES_DIR}stdafx.h
${SOURCES_DIR}stdafx.cpp
${SOURCES_DIR}config.cpp
${SOURCES_DIR}config.h
${SOURCES_DIR}client.cpp
${SOURCES_DIR}client.h
${SOURCES_DIR}client_http.cpp
${SOURCES_DIR}client_http.h
${SOURCES_DIR}export.cpp
${SOURCES_DIR}export.h
${SOURCES_DIR}server.cpp
${SOURCES_DIR}server.h
${SOURCES_DIR}server_http.cpp
${SOURCES_DIR}server_http.h
${SOURCES_DIR}proxy_tcp.cpp
${SOURCES_DIR}proxy_tcp.h
${SOURCES_DIR}session.cpp
${SOURCES_DIR}session.h
)

add_definitions(-DSHARED_API)
add_library(${PROJECT_NAME} SHARED ${SOURCES})

MSVC_USE_CRT_OPTION(${PROJECT_NAME})

# 指定专用库头文件目录
target_include_directories(${PROJECT_NAME} PRIVATE
${SOURCES_DIR}
${CURRENT_SOLUTION_DIR}/include
${SOLUTION_ROOT_DIR}/3rdparty
${SOLUTION_ROOT_DIR}/include
${SOLUTION_ROOT_DIR}/3rdparty/spdlog/include
${SOLUTION_ROOT_DIR}/3rdparty/uv-cpp/uv/include
${SOLUTION_ROOT_DIR}/3rdparty/libuv-1.44.2/include
${SOLUTION_ROOT_DIR}/3rdparty/http-parser
)

# 依赖库目录
target_link_directories(${PROJECT_NAME} PRIVATE
${SOLUTION_ROOT_DIR}/librarys/3rdparty/$(Platform)
${SOLUTION_ROOT_DIR}/librarys/shared/$(Platform)
#${SOLUTION_ROOT_DIR}/librarys/openssl/3.1.0-beta1/$(Platform)
)

# MSVC 预编译头设置
MSVC_USE_PCH(${PROJECT_NAME} 
${SOURCES_DIR}stdafx.h 
${SOURCES_DIR}stdafx.cpp)





