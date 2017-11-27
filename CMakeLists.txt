cmake_minimum_required (VERSION 2.8)

project (demo2)
set(CMAKE_INSTALL_PREFIX /home/saicoc/code/cmake_learn)
# 加入一个配置头文件， 用于处理cmake 对源码的设置

configure_file(
        "${PROJECT_SOURCE_DIR}/config.h.in"
        "${PROJECT_SOURCE_DIR}/config.h"
)

# 是否使用自己的MAthFunction库
option(USE_MYMATH "Use provided math implementation" OFF)

if (USE_MYMATH)
    include_directories("${PROJECT_SOURCE_DIR}/math")
    add_subdirectory(math)
    set (EXTRA_LIBS ${EXTRA_LIBS} MathFunc)

endif (USE_MYMATH)


# 查找当前目录下所有源文件
aux_source_directory(. DIRSRCS)

# 添加mxnet库
include_directories(/home/saicoco/libs/incubator-mxnet/include)
link_directories(/home/saicoco/libs/incubator-mxnet/lib)
#link_libraries(/home/saicoco/libs/incubator-mxnet/lib/libmxnet.a)
link_libraries(/home/saicoco/libs/incubator-mxnet/lib/libmxnet.so)

# 添加opencv库
set(OpenCV_DIR /home/saicoco/anaconda2)
find_package(OpenCV 3 REQUIRED)

#include_directories(/home/saicoco/anaconda2/include)
#link_directories(/home/saicoco/anaconda2/lib)


# 指定生成目标
add_executable(Demo5 ${DIRSRCS} predictor.cpp)


# 添加链接库
target_link_libraries(Demo5 ${EXTRA_LIBS} ${OpenCV_LIBS})

# 指定安装路径

install(TARGETS Demo5 DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/config.h" DESTINATION include)


## 启用测试
#enable_testing()
#
## 测试程序是否成功执行
#add_test(test_run Demo5 5 2)
#
## 测试帮助信息是否可以正常提示
#add_test(test_usage Demo5)
#set_tests_properties (test_usage
#        PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")
## 测试 5 的平方
#add_test (test_5_2 Demo5 5 2)
#set_tests_properties (test_5_2
#        PROPERTIES PASS_REGULAR_EXPRESSION "is 25")
## 测试 10 的 5 次方
#add_test (test_10_5 Demo5 10 5)
#set_tests_properties (test_10_5
#        PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")
## 测试 2 的 10 次方
#add_test (test_2_10 Demo5 2 10)
#set_tests_properties (test_2_10
#        PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")

# 构建一个CPack安装包
include(InstallRequiredSystemLibraries)
#set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt" )
include(CPack)