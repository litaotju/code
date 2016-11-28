package main

import "sort"
import "fmt"
type A []int 

// threa functions for the sort.Interface
func (a A) Less(i, j int) bool { return a[i]<a[j]}
func (a A) Swap(i, j int) { a[i], a[j] = a[j], a[i] }
func (a A) Len() int {return len(a) }

func main(){
    a := A{1, 1, 2, 31, 321, 312, 321}
    fmt.Println(a)
    sort.Sort(a)
    fmt.Println("Is sorted ", sort.IsSorted(a))
    fmt.Println(a)    
}