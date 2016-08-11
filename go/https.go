package main

import (
    "fmt"
    "net/http"
    "log"
)

// type Handler interface {
//     ServeHTTP(w ResponseWriter, r *Request)
// }

type MyHttpServer struct{}

func (h MyHttpServer) ServeHTTP(w http.ResponseWriter, r* http.Request){
    fmt.Fprint(w, "Hello, this is a go server")
}

func main(){
    var h MyHttpServer
    err := http.ListenAndServe("localhost:10000", h)
    if err != nil{
        log.Fatal(err)
    }
}