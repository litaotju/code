package main

import (
    "fmt"
    "math"
)
// compu accept a func named fn as a param and return a fn(3,4)
func compu(fn func(float64, float64) float64) float64{
    return fn(3, 4)
}

func main(){
    // hypot is func obj
    hypot := func(a, b float64) float64{
        return a*a + b*b
    }

    fmt.Println(hypot(4, 1))
    fmt.Println(compu(math.Pow))
    fmt.Println(compu(hypot))
}