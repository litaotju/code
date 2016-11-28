package main

import (
    "os"
    "fmt"
    "math"
    "math/cmplx"
)

//this is wrong 
// short declearation can only been used in the function 
// x :=1

var c  = make(chan int, 10)
var a string
func f(){
    a = "Hello world"
    c <- 1
}

func main(){
    defer fmt.Printf("Defer run")
    go f()
    <- c
    fmt.Println(a)
    fmt.Println(math.Pi)
    fmt.Println(add(11, 12))
    var x complex128 = cmplx.Sqrt(1+2i)
    fmt.Fprint(os.Stdout, x)

    var i int
	var f float64
	var b bool
	var s string
	fmt.Printf("%v %v %v %q\n", i, f, b, s)
    const consV = "Const String"
    fmt.Println(consV)
    ii := 100
    var p *int
    p = &ii
    mod(p)
    fmt.Println("After mod:", ii)
}

func add(a, b int) int{
    return a+b
}

func mod( p *int){
    *p = *p +1
}