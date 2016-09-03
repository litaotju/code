#! /bin/bash

## 3_1 字符串和文件测试运算符

file="testfile.txt"
dir="testdir"

## -d 是否为目录
if [ -d $dir ]
then
    echo "$dir is a path"
fi

if [ -d $file ]
then
    echo "$file is a path"
else
    echo "$file is a not a path"
fi

## -f是否为普通文件
if [ -f $file ]
then
    echo "$file is a normal file"
fi

## -r 是否可读
if [ -r $file ]
then
    echo "$file is readable"
fi

## -w 是否可写
if [ -w $file ]
then
    echo "$file is writeable"
fi

## -x是否可执行
if [ -x $file ]
then
    echo "$file is excutable"
else
    echo "$file is not excutable"
fi

## -e 是否存在.不论是文件还是文件夹，还是设备
if [ -e $file ]
then
    echo "$file is exist"
else
    echo "$file is not exist"
fi