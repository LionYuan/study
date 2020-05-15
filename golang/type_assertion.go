package main

import "fmt"

func test(a interface{}) {
	// 1. 直接断言。
	// 如果断言失败一般会导致panic的发生。所以为了防止panic的发生，我们需要在断言前进行一定的判断
	// panic here
	//fmt.Println(a.(bool))

	// 2. 在断言前进行一定的判断
	// 如果断言失败，那么ok的值将会是false,但是如果断言成功ok的值将会是true,同时value将会得到所期待的正确的值
	v, ok := a.(string)
	if ok {
		fmt.Printf("value is tring:%s\n", v)
		return
	}
	fmt.Println("value is not string")
}

func returnString() string {
	return "i am string"
}

func test1() {
	var i interface{}
	i = returnString()
	switch t := i.(type) {
	default:
		fmt.Printf("unexpected type %T", i) // %T prints whatever type t has
	case bool:
		fmt.Printf("boolean %t\n", i) // t has type bool
	case int:
		fmt.Printf("integer %d\n", i) // t has type int
	case *bool:
		fmt.Printf("pointer to boolean %t\n", i) // t has type *bool
	case *int:
		fmt.Printf("pointer to integer %d\n", *t) // t has type *int
	case string:
		fmt.Printf("string: %s, %s\n", i, t)
	}

}

func main() {
	test("hello world.")
	test1()
}
