cmake_minimum_required(VERSION 3.16)

project(Coinlog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)

# Ищем Qt6 Widgets
find_package(Qt6 REQUIRED COMPONENTS Widgets Sql)

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
    transaction.h
    databasemanager.h databasemanager.cpp
    analytics.h analytics.cpp
    categorymanager.h categorymanager.cpp
    dataexchangeui.h dataexchangeui.cpp )

# Линкуем Qt Widgets
target_link_libraries(${PROJECT_NAME}
    PRIVATE Qt6::Widgets
            Qt6::Sql
)
