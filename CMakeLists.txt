cmake_minimum_required(VERSION 3.16)
project(FileManager VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_AUTOMOC ON)  # Для автоматической обработки Q_OBJECT
set(CMAKE_AUTORCC ON)  # Для ресурсов Qt
set(CMAKE_AUTOUIC ON)  # Для .ui файлов

# Найти Qt пакеты
find_package(Qt6 COMPONENTS Widgets REQUIRED)
# Если используете Qt5, замените на:
# find_package(Qt5 COMPONENTS Widgets REQUIRED)

# Исходные файлы
set(SOURCE_FILES
        src/main.cpp
        src/ui/windows/MainWindow.cpp
)

# Заголовочные файлы
set(HEADER_FILES
        src/ui/windows/MainWindow.h
)

# UI файлы (если будете использовать Qt Designer)
set(UI_FILES
        #src$/ui/windows/MainWindow.ui  # Раскомментируйте, если создадите UI файл
)

# Создание исполняемого файла
add_executable(${PROJECT_NAME}
        ${SOURCE_FILES}
        ${HEADER_FILES}
)

# Связывание с библиотеками Qt
target_link_libraries(${PROJECT_NAME} PRIVATE
        Qt6::Widgets  # Если Qt5: Qt5::Widgets
)

# Включить каталоги для поиска заголовочных файлов
target_include_directories(${PROJECT_NAME} PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
)