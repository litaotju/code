#! /bin/bash

###2. 特殊变量

## $n 表示第n个脚本参数， 如果不存在则为空。但是引用不会报错
echo "script file name: $0"
echo "first argument is: $1"
echo "second argument is: $2"

## $# 表示脚本参数的个数， $@ 表示所有的参数
echo "The argument count is: $#, all arguments is: $@"

## $$当前进程号， $!上一个成功运行的进程号
echo "The current pid is: $$, last successfully pid is: $!"
echo "The last exit value is: $?"