package main

import (
    "fmt"
    "time"
)

func f(s string){
    for i:=0; i<5; i++{
        time.Sleep(100 * time.Millisecond)
        fmt.Println(s)
    }
}

// 无缓冲的 channel
func sum(a []int, c chan int){
    var sum int
    for _, value := range a{
        sum += value
    }
    c <- sum
}

//带缓冲的channel
func fabonacci(c chan int, n int){
    x , y := 0, 1
    for i:=0; i<n; i++{
        c<-x
        x, y = y, x+y
    }
    close(c)
}

func main (){
    // go f("Hello")
    // f("World")
    a := []int{1, 2, 3, 4,5,6,7,8,9, 10}
    c := make(chan int)
    // 分半分别求和， 结果依次放入 channel
    go sum( a[: len(a)/2], c )
    go sum( a[len(a)/2: ], c)
    x, y := <-c, <-c
    fmt.Println(x, y, x+y)

    fc := make(chan int, 10)
    //填满channel fc
    go fabonacci(fc, cap(fc))
    //消费 fc
    for num := range fc{
        fmt.Println(num)
    } 
}