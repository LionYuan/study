package main

import "fmt"

func main() {
	send := make(chan string, 1)
	// send msg
	send <- "hello world."

	var s string
	select {
	case s = <-send:
		fmt.Printf("get string:%s\n", s)
	default:
		fmt.Println("unknown type.")
	}

	fmt.Println("end")
}
