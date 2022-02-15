set(Target ${This})

message("")
message(STATUS "Start building : " ${Target})

# 设置包含路径
include_directories(${ROOT_DIR}/src/include)

# 添加当前文件夹下所有文件为源文件
aux_source_directory(./SayHello SAY_HELLO)


set(SRCS
        ${SAY_HELLO}
   )

find_package(CURL REQUIRED)

if(CURL_FOUND)
        include_directories(${CURL_INCLUDE_DIR})
        message(STATUS "Curl Found: ${CURL_VERSION_STRING} ${CURL_LIBRARIES} ${CURL_LINK_LIBRARIES}!")
else(CURL_FOUND)
        message(FATAL_ERROR "Could not find the CURL library and development files.")
endif()

# 生成动态库
add_library(${Target} SHARED ${SRCS})

target_link_libraries(${Target} ${CURL_LIBRARIES} stdc++fs)

# 定义导出宏
target_compile_definitions(${Target}
                                PRIVATE
                                LIBRARY_EXPORT)
                                
# 安装生成的动态库
set(CMAKE_INSTALL_PREFIX ${ROOT_DIR}/install)

install(TARGETS ${Target}
        EXPORT ${Target}Tagets
        RUNTIME DESTINATION ${CMAKE_INSTALL_PREFIX}/bin
        LIBRARY DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        ARCHIVE DESTINATION ${CMAKE_INSTALL_PREFIX}/lib
        )

# 安装头文件
install(DIRECTORY ${ROOT_DIR}/src/include DESTINATION ${CMAKE_INSTALL_PREFIX})

# 将目标文件可导出文件
install(EXPORT ${Target}Tagets DESTINATION ${ROOT_DIR}/cmake)

# 生成 ${Target}Config.cmake
configure_file(${ROOT_DIR}/config/${Target}Config.cmake.in ${ROOT_DIR}/cmake/${Target}Config.cmake)
install(FILES ${ROOT_DIR}/cmake/${Target}Config.cmake DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake)

message(STATUS "Stop building : " ${Target} "\n")