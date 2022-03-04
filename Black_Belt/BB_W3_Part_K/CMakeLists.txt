# CMakeList.txt: проект CMake для BB_W1_Part_I; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("BB_W1_Part_K")

set(CMAKE_CXX_STANDARD 20)
file(GLOB execs CONFIGURE_DEPENDS "*.h" "*.cpp")
# Добавьте источник в исполняемый файл этого проекта.
add_executable (BB_W1_Part_K "${execs}")



# TODO: Добавьте тесты и целевые объекты, если это необходимо.
