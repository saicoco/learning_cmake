
# 查找当前目录下所有源文件， 并保存子DIR_LIB_SRCS变量中
aux_source_directory(. DIR_LIB_SRCS)

# 生成链接库
add_library(MathFunc ${DIR_LIB_SRCS})

# 指定MathFunc库的安装路径
install(TARGETS MathFunc DESTINATION bin)
install(FILES math_func.h DESTINATION include)




