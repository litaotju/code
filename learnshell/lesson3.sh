#! /bin/bash

### 3.运算符

## 3.1 算术运算符
## 本身没有数学运算符，但是可以通过 expr awk 等命令来实现
## 注意，在这里面 运算符两边必须有空格。 expr 2+3 是不对的，只能是 expr 2 + 3
sum=`expr 2 + 3`
echo "2+3=$sum"

r=`expr 5 % 3`
echo "5%3=$r"

echo "sum==r? `expr sum == r`"

a=10
b=20

## 条件判断语句
if [ $a == $b ]
then
    echo "a == b is true"
else
    echo "a == b is false"
fi

## 3.2 关系运算符
## 关系运算符只能用在数字之间，不支持字符串
## 六个关系运算符 -eq, -ne, -lt, -gt, -le, -ge
echo "a=$a, b=$b"

if [ $a -eq $b ]
then
    echo "a equal to b"
else
    echo "a is not equal to b"
fi

if [ $a -lt $b ]
then
    echo "a less than b"
else
    echo "a is not less than b"
fi

if [ $a -le $b ]
then
    echo "a is less equal than b"
else
    echo "a is not less equal than b"
fi


## 3.3 布尔运算符
## ! 非运算， -o or运算， -a and运算
if [ ! $a -eq $b ]
then
    echo "!false is always be true"
fi

a=10
b=10
c=20

if [ $a -eq $b -a $a -eq $c ]
then
    echo "a==b and a==c"
else
    echo "a==b==c is not true"
fi


## 3.4 逻辑运算符
## && ||, 与c语言中的含义相同




