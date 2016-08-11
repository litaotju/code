package main

import (
    "fmt"
)

func adder (sum int) func(int) int{
    // sum := 0
    //返回一个函数，这个函数和sum的值绑定在一起，称之为闭包
    return func(x int) int{
        return sum+x
    }
}

func main(){
    neg, pos := adder(-100), adder(100)
    fmt.Println( neg(1) ) // -100+1
    fmt.Println( pos(1) ) // 100 +1
}