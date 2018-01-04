# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html
#CmakeLists.txt翻译:对于更多Android Studio使用CMake的文档信息，请
#阅读documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

#指定CMake编译器的最低版本3.4.1
cmake_minimum_required(VERSION 3.4.1)

#设置生成的so动态库最后输出的路径
#它将会把生成的so库按照你在 build.gradle 指定的 abi分别放置在 jniLibs下
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/../jniLibs/${ANDROID_ABI})

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.
#CmakeLists.txt翻译:创建一个类库的name,设置这个类库为STATIC
#或者SHARED类型，并且设置c或者c++的源代码的的相对路径。
#你可以定义多个类库，同事CMake会为你构建。
#Gradle可以自动将shared类库打包到你的APK中。

# CMake根据指定的源文件生成库文件
add_library(
            # Sets the name of the library
            #设置类库的名字
             native-lib

             # Sets the library as a shared library.
             #生成的库的类型[SHARED|STATIC|MODULE]
             #SHARED库会被动态链接，在运行时被加载
             #STATIC库是在链接其它目标的时候使用
             SHARED

             # Provides a relative path to your source file(s).
             #指定路径下的源文件代码，可以为这个类库指定多个.cpp文件
             src/main/cpp/c01.c
             src/main/cpp/c02.c
             src/main/cpp/native-lib.cpp
             src/main/cpp/compute/Operate.c
             src/main/cpp/compute/Operate.h
             )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.
#CmakeLists.txt翻译:搜索指定构建库并将变量作为存储路径。
#因为Cmake构建工具默认包含了系统类库，你仅仅需要指定你想要添加的公共NDK类库的name.
#CMake构建工具会在完成构建之前校验指定的类库name是否存在

# 将NDK log类库的位置存储到变量 log-lib中
#可以在构建脚本的其他地方使用这个变量 ${log-lib}
find_library( # Sets the name of the path variable.
              log-lib

              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.
#CmakeLists.txt翻译:指定类库 CMake构建工具会连接到你的目标类库中。
#你可以连接到多个类库中，例如：在这个CmakeLists.txt的构建脚本中定义的类库，
#预构建的第三方类库或者系统类库。

#为生成的目标类库指定需要的库文件
target_link_libraries(
                       # Specifies the target library.
                       #生成的目标库文件
                       native-lib

                       # Links the target library to the log library
                       # included in the NDK.
                       #需要在目标库文件中使用的库，表示可以在native-lib中使用log-lib库的内容
                       ${log-lib} )