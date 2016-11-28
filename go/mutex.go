package main

import (
    "fmt"
    "sync"
    "time"
)

type SafeCounter struct{
    v map[string]int
    mutex sync.Mutex 
}

func (c *SafeCounter)Inc(key string){
    c.mutex.Lock()
    c.v[key] += 1
    c.mutex.Unlock()
}

func (c *SafeCounter)Value(key string) int{
    c.mutex.Lock()
    defer c.mutex.Unlock()
    return c.v[key]
}

func main(){
    counter := SafeCounter{ v: make(map[string]int) }
    for i:=0 ; i<100 ; i++{
        go counter.Inc("somekey")
    }
    fmt.Println(counter.Value("somekey"))
    time.Sleep(2 * time.Second)
    fmt.Println(counter.Value("somekey"))
}