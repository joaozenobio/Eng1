cmake_minimum_required(VERSION 3.22)
project(Eng1)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)
include_directories(src/lib)
include_directories(test)
include_directories(test/functional/lib)

add_executable(Eng1
        src/lib/Flow.h
        src/lib/FlowImplementation.cpp
        src/lib/FlowImplementation.h
        src/lib/Model.h
        src/lib/ModelImplementation.cpp
        src/lib/ModelImplementation.h
        src/lib/System.h
        src/lib/SystemImplementation.cpp
        src/lib/SystemImplementation.h
        src/main.cpp
        test/functional/FunctionalTests.cpp
        test/functional/FunctionalTests.h
        test/functional/main.cpp)
