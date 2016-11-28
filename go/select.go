package main

import (
    "fmt"
)

func fabonacci(c, q chan int){
    x , y := 0, 1
    for{
        select{
            case c <-x: // when channel c can recive an int, eject x
                x, y = y, x+y
            case <-q: // 当 quit 可以弹出一个东西时， 即别人给quit发了一个信号
                fmt.Println("quit")
                return 
        }
    }
}

func main(){
    c := make(chan int, 10)
    q := make(chan int)
    go func(){
        for i:=0; i<10; i++{
            fmt.Println(<-c)
        }
        q <- 0
    }()
    fmt.Println("Ready go")
    fabonacci(c, q)
}