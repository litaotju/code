package main
import (
    "fmt"
    "strings"
)

func main(){
    // slice of slice
    board := [][]string{
        []string{"_", "_", "_"},
        []string{"_", "_", "_"},
        []string{"_", "_", "_"},        
    }
    board[0][1] = "X"
    board[1][1] = "X"
    board[2][2] = "X"
    board[2][0] = "O"

    printBoard(board)
    
    //slice
    array := []int{1,2,3,4,5,6}
    fmt.Println("array[1:4]",  array[1:4])
    fmt.Println("array[：4]", array[:4])
    fmt.Println("array[1:]", array[1:])

    //make slice
    b := make([]int, 10, 23)
    fmt.Println("make([]int, 10) ", b)
    fmt.Println("capacity of b: ", cap(b))

    //nil slice
    var z []int
    // funt cap for slice
	fmt.Println(z, len(z), cap(z))
	if z == nil {
		fmt.Println("nil!")
	}

    //append
    b = append(b, 11)
    fmt.Println("b after append ", b)
}

func printBoard( board [][]string ){
    // func len for slice 
    for i:=0; i<len(board); i++{
        fmt.Println(strings.Join(board[i], " "))
    }
}