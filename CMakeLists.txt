cmake_minimum_required(VERSION 3.5)

project(QtGlDemo LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui OpenGL OpenGLWidgets Widgets)

qt_add_executable(QtGlDemo
    main.cpp
    main_window.cpp
    main_window.h
    shaders/shaders.qrc
    views/gl_widget.h
    views/gl_widget.cpp
    views/left_view.h
    views/left_view.cpp
    views/bottom_view.h
    views/bottom_view.cpp
)

target_link_libraries(QtGlDemo PUBLIC
    Qt::Core
    Qt::Gui
    Qt::OpenGL
    Qt::OpenGLWidgets
    Qt::Widgets
    OpenGL32
)

set_target_properties(QtGlDemo PROPERTIES
    WIN32_EXECUTABLE TRUE
)

install(TARGETS QtGlDemo
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
