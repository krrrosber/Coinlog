cmake_minimum_required(VERSION 3.16)

project(Coinlog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

# Ищем Qt6 Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Список файлов проекта
set(PROJECT_SOURCES
    main.cpp
    mainwindow.cpp
    mainwindow.h
    mainwindow.ui
)

# Создаём исполняемый файл
qt_add_executable(${PROJECT_NAME} ${PROJECT_SOURCES}
    category.h category.cpp
    transaction.h )

# Линкуем Qt Widgets
target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Widgets)
