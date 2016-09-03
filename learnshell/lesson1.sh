#! /bin/bash
##是注释

### 1 变量，数组的定义，赋值和使用

a="This is a string"
echo $a
echo "Wrapper for ${a}"
echo 'All literally in this ${a}'

## 加readonly之后，不能赋值
# readonly a
# a="new value for a"

## unset 之后，输出变量不存在
# unset a
# echo $a

##for循环
#for file in `ls`;do
#    echo $file
#done

##获取字符串长度
echo "This is length of a: ${#a}"

##截取字符串
echo "This is [0:4] of a: ${a:0:4}"
echo "This is [4:] of a: ${a:4}"
echo "This is [:10] of a: ${a::10}"

##获取子字符串的index, 下列命令获取了 s 字符在 a中第一次出现的index
echo `expr index "${a}" s`

##数组. 长度不固定，从0开始编号。 类型不限制
array=(1, 2, 3, 4, "hello")
echo ${array[4]}
# 元素赋值
array[4]="world"
echo ${array[4]}

#注意，数组的下标没有限制。也可以不连续
array[100]=100
echo ${array[100]}

#输出数组中所有的值
echo ${array[@]}

#获取数组的长度
echo "length of array is: ${#array[@]}"
#获取某一个元素的长度
echo "length of array[0] is ${#array[0]}"