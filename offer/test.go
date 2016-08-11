package main

import "fmt"
import "math"

func sort(a [] int32, n int32){
    var i int32 = 0
    var j int32  = 0
    for i=0; i<n-1; i++ {
        for j=0; j<n-i-1; j++ {
            if a[j] > a[j+1]{
                temp := a[j]
                a[j] = a[j+1]
                a[j+1] = temp
            }
        }
    }
}

func main(){
    var array = []int32 {1,10, 32, 12, 3}
    sort(array, 5)
    for  _, x := range array{
        fmt.Println(x)
    }
    fmt.Println("\n", math.Pi)
}