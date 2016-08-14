package main

import "fmt"

func isAnagram(s string, t string) bool {
    if len(s) != len(t){
        return false
    }
    freqs, freqt := make([]int, 26), make([]int, 26)
    for i:=0; i<len(s); i++{
        freqs[ s[i]-'a' ] ++
        freqt[ t[i]-'a' ] ++
    } 
    for i:=0; i<26; i++{
        if freqs[i] !=freqt[i]{
            return false
        }
    }
    return true
}

func reverseString(s string) string {
    if len(s)<=1 {
        return s
    }
    for i, j:= 0, len(s)-1; i<j; i, j=i+1, j-1{
        s[i], s[j] = s[j], s[i]
    }
    return s
}

func main(){
    a := "angam"
    b := "gaanm"
    if !isAnagram(a, b){
        fmt.Println("Error")
    }
    fmt.Println( reverseString(a) )
}