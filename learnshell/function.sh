#! /bin/bash

function sum()
{
    # 在函数里面 $1 $2表示第一个 第二个参数
    return $(($1+$2))
}


## 调用时的形式为： function_name arg1 arg2
sum $1 $2

## 上一个函数的返回值用 $? 表示
echo "$1 + $2 = $?"

