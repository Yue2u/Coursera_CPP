# CMakeList.txt: проект CMake для BB_W1_Part_I; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project (BB_W5_Part_Q)


set(CMAKE_CXX_STANDARD 20)


find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS})


file(GLOB execs CONFIGURE_DEPENDS "*.h" "*.cpp" "*.pb.cc" ".pb.h")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (BB_W5_Part_Q "${execs}")
target_link_libraries(BB_W5_Part_Q ${PROTOBUF_LIBRARY})



