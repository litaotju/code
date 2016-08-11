package main


import (
    "fmt"
    "strings"
)

func WordCnt(s string) map[string]int{
    freq := make(map[string]int)
    words := strings.Fields(s)
    for _, word := range words{
        _, exist := freq[word]
        if exist{
            freq[word] = freq[word]+1
        }else{
            freq[word] = 1
        }
    }
    return freq
}

func main(){
    s := "A string for string count"
    freq := WordCnt(s)
    fmt.Println(freq)
}