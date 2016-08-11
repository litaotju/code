package main

import (
    "fmt"
)

func main(){
    m := map[int]string{
        1:"L",
        2:"MM",
        3:"das",
    }
    fmt.Println(m)
    
    m[1] = "KK"
    fmt.Println("After m[1]= \"KK\" ", m)

    m2 := m[2]
    fmt.Println("m[2]: ", m2)

    delete(m, 3)
    fmt.Println("After delete(m, 3)", m) 

    _, ok := m[4]
    fmt.Println("does m[4] exist: ", ok)
}