cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 17)
project(sound_processor)

set(exe_name ${PROJECT_NAME})

# ��������� �������� ����������, �.�. ����������, ���������� ��� cpp-�����, ����� main.cpp
add_library(corelib OBJECT CommandsReader.cpp ExceptionsHierarchy.cpp MixConvertor.cpp MuteConvertor.cpp WaveReader.cpp Writer.cpp
        ReverseConvertor.cpp)

# ��������� ����������� ���� �������� ���������: ��� main.cpp + �������� ����������
add_executable(${exe_name} main.cpp)
target_link_libraries(${exe_name} corelib)