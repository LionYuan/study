package main

import "fmt"

// Why Interface
// 1. writing generic algorithm （泛型编程）
// 2. hiding implementation detail （隐藏具体实现）
// 3. providing interception points

// MyInterface interface 定义
type MyInterface interface {
	Print()
}

// TestFunc interface 作为函数参数传递
func TestFunc(x MyInterface) {
	x.Print()
}

// TestTypeAssertion Type Assertion
func TestTypeAssertion(x MyInterface) {
	if pc, ok := x.(MyStruct); ok {
		fmt.Printf("x type:%v\n", pc)
		return
	}
	fmt.Println("unknown type.")
}

// MyStruct 定义结构体
type MyStruct struct {
	name string
}

// Print 实现 interface 方法
func (me MyStruct) Print() {
	fmt.Println(me.name, " hello interface")
}

func main() {
	// interface 作为函数参数传递
	var me MyStruct
	TestFunc(me)

	// 结构体赋值给interface
	var i MyInterface
	i = MyStruct{"my struct"}
	i.Print()
	TestTypeAssertion(i)
}
