# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.10.2)

#设置工程名字
project("jnidemo")


#add_library target_include_directories  需要成对出现
add_library( # Sets the name of the library.
        native-lib
        # Sets the library as a shared library.
        SHARED
        # Provides a relative path to your source file(s).
        src/main/cpp/native-lib.cpp)
target_include_directories(
        native-lib
        PRIVATE
        ${CMAKE_SOURCE_DIR}/src/main/cpp/include
)


# 添加第三方库
add_library(HancNetSDK
        # 设置引入的函数库类型为静态库
        SHARED
        # 表示引入第三方静态库
        IMPORTED)
# 配置第三方库链接
set_target_properties(
        HancNetSDK
        PROPERTIES
        IMPORTED_LOCATION
        ${CMAKE_SOURCE_DIR}/src/main/jniLibs/${ANDROID_ABI}/libHancNetSDK.so)


find_library( # Sets the name of the path variable.
        log-lib
        # Specifies the name of the NDK library that
        # you want CMake to locate.
        log)


target_link_libraries( # Specifies the target library.
        native-lib
        HancNetSDK
        # Links the target library to the log library
        # included in the NDK.
        ${log-lib})