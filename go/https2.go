package main

import (
	"fmt"
	"log"
	"net/http"
)
type String string

type Struct struct{
	Greeting string
	Punct string
	Who string
}

func (s String)ServeHTTP(w http.ResponseWriter, r* http.Request){
	fmt.Fprint(w, s)
}

func (s *Struct)ServeHTTP(w http.ResponseWriter, r* http.Request){
	fmt.Fprint(w, fmt.Sprintf("%v %v %v", s.Greeting, s.Punct, s.Who))
}

func main() {
	// your http.Handle calls here
	http.Handle("/string", String("I am litao, and this is a go server"))
	http.Handle("/struct", &Struct{"Hello", ", " , "Who are you"})
	log.Fatal(http.ListenAndServe("localhost:10000", nil))
}
