package main
import "fmt"

type A struct {
    name string
    id uint32
}

type Bird interface {
    fly()
    jump() (distace uint32)
}

func test() int32{
    a, b := int32 (1), int32 (2)
    // c:=1, d:=2
    b = a
    fmt.Println(b)
    switch b {
        case 1:
            fmt.Println("b==1")
        case 2:
            fmt.Println("b==2")
        default:
            fmt.Println("Nothing")
    }
    return a
}

func isAlpha(c byte) bool{
    switch{
        case  c<='z' && c>='a' || c<='Z' && c>='A':
            return true
        default:
            return false
    }
}

func printA(){
    var a =  A {"T", 10}
    a.name = "Litao"
    a.id = 10
    fmt.Println("name ", a.name)
    fmt.Println("id", a.id)
}

func refOrValue(a *A){
    a.name ="Changed"
    fmt.Println("a.name", a.name)
}

func multiReturn(a A) (name string, id uint32 ){
    name, id = a.name, a.id
    return 
}

func testMap(){
    m:=map[int]string{
        1:"ming",
        2:"fdsh",
    }
    for id, name:= range m{
        fmt.Println("id ", id)
        fmt.Println("name ", name)
    }
    fmt.Printf("type if map: %T, address of map %x", m, &m)
    fmt.Printf("content of map: %v", m)
}

func main(){
    fmt.Println( 1<< (8+1) << 1)
    fmt.Println( 1<<8 + 1<<1 )
    test()
    fmt.Println("The test has been called")
    printA()
    fmt.Println("C isAlpha? ", isAlpha('C'))
    fmt.Println("= isAlpha? ", isAlpha('='))
    a := A{"Origin", 10}
    refOrValue(&a)
    switch a.name{
        case "Origin":
            fmt.Println("By value")
        default:
            fmt.Println("By ref")
    }
    name , id:= multiReturn(a)
    fmt.Println("name ", name, "id ", id)
    a = A{id:100, name:"FHU"}
    testMap()
}

