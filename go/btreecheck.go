package main
import "fmt"
import "golang.org/x/tour/tree"

// Walk 步进 tree t 将所有的值从 tree 发送到 channel ch。
func Walk(t *tree.Tree, ch chan int){
	if t != nil{
		ch <- t.Value
		//fmt.Println(t.Value)
		Walk(t.Left, ch)
		Walk(t.Right, ch)
	}
	return
}

// Same 检测树 t1 和 t2 是否含有相同的值。
func Same(t1, t2 *tree.Tree) bool{
	ch1 := make( chan int)
	ch2 := make( chan int)
	go Walk(t1, ch1)
	go Walk(t2, ch2)
	for {
		x, ok1 := <-ch1
		y, ok2 := <-ch2
		if ok1==false || ok2==false{
		if ok1!=ok2{
			fmt.Println("not same length")
			return false
		}
			return true
		}
		if x!=y{
			fmt.Println("Not same value")
			return false
		}
	}
}

func main() {
	tree1 := tree.New(10)
	tree2 := tree1
	fmt.Println( Same(tree1, tree2) )
}
