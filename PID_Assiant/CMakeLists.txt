cmake_minimum_required(VERSION 3.5)

project(pid_assiant  VERSION 0.1 LANGUAGES CXX)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)

#打开UIC，自动将ui文件转换为.h文件
#保证UI文件和cpp文件在一个文件夹即可，后续不用在工程中再添加ui文件，因为在.cpp中才包含ui_.h
#根据CMAKE官方文档，CMAKE会去包含ui_.h的文件所在文件夹寻找.ui文件，或者去AUTOUIC_SEARCH_PATHS下寻找。
list(APPEND AUTOUIC_SEARCH_PATHS "${CMAKE_CURRENT_SOURCE_DIR}/src/")
message("uic:${AUTOUIC_SEARCH_PATHS}")
set(CMAKE_AUTOUIC ON)  
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#指明Qt库的位置   如果环境变量有Qt，就可以不用
list(APPEND CMAKE_PREFIX_PATH "/opt/Qt/5.15.2/gcc_64")
find_package(Qt5 REQUIRED COMPONENTS Widgets Core Charts Network)

#QTermWidget包
list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
find_package(QtermWidget5)

include_directories(include)
# FILE(GLOB PROJECT_HEADERS "include/*.h")

#headers 
list(APPEND PROJECT_HEADERS
        include/mainwindow.h
        include/robot_master.h
        include/toolpage.h
        include/terminalpage.h
        include/display.h
        include/chart.h
        include/robot.h
        include/types.h
        include/tcp_connect.h
)

#sources 
list(APPEND PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/robot_master.cpp
        src/toolpage.cpp
        src/terminalpage.cpp
        src/display.cpp
        src/chart.cpp
        src/robot.cpp
        src/types.cpp
        src/tcp_connect.cpp
)

#ui_dir
list(APPEND UI_FILES_PATHS
ui/
)

# resource files qrc 
list(APPEND RESOURCE_QRC
    resources/res.qrc
)

#plugin.so
set(PLUGIN_DIR ${CMAKE_CURRENT_BINARY_DIR}/pid_controller_plugin)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/resources/base_local_planner.json ${PLUGIN_DIR}/base_local_planner.json COPYONLY)# 复制 JSON 文件到输出目录
add_library(pid_controller SHARED 
src/pid_controller.cpp 
src/types.cpp
include/pid_controller.h  #头文件也要放进来一起编译，不然运行时会报错
# resources/base_local_planner.json
)
set_target_properties(pid_controller PROPERTIES
    LIBRARY_OUTPUT_DIRECTORY ${PLUGIN_DIR}
)
target_sources(pid_controller PRIVATE
${PLUGIN_DIR}/base_local_planner.json
)
target_link_libraries(pid_controller PRIVATE 
Qt5::Core
Qt5::Widgets
)

# executable
add_executable(pid_assiant
    ${PROJECT_HEADERS}
    ${PROJECT_SOURCES}
    ${RESOURCE_QRC}
)
set_property(TARGET pid_assiant PROPERTY AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/${UI_FILES_PATHS})
target_link_libraries(pid_assiant PRIVATE 
Qt5::Widgets
Qt5::Core
Qt5::Charts
Qt5::Network
qtermwidget5
)

# executable
add_executable(test_sever
include/tcp_connect.h
src/tcp_connect.cpp
src/tcp_sever_test.cpp
)
target_link_libraries(test_sever PRIVATE 
Qt5::Core
Qt5::Network
)

