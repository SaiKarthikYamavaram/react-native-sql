cmake_minimum_required(VERSION 3.9.0)
set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_CXX_STANDARD 11)


set (PACKAGE_NAME "react-native-sql")

add_library(
        cpp
        SHARED
        ../node_modules/react-native/ReactCommon/jsi/jsi/jsi.cpp
        ../cpp/react-native-sql.cpp
        ../cpp/react-native-sql.h
        cpp-adapter.cpp
        ${INCLUDE_JSI_CPP} # only on older RN versions

        )

# Specifies a path to native header files.
include_directories(
        ../node_modules/react-native/React
        ../node_modules/react-native/React/Base
        ../node_modules/react-native/ReactCommon/jsi
        ../cpp

)

target_link_libraries(
        ${PACKAGE_NAME}
        android
)
