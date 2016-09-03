#! /bin/bash

#显示变量
read name
echo "hello $name"

#转义
echo "\" Test escape \""

#转义
echo -e "new line \n"
echo "Test new line"

#输出至文件
echo "redirect to file" > "testfile.txt"

#显示命令执行结果
echo `date`


