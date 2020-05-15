package main

import (
	"fmt"
	"sync"
)

// 常用数据类型
// 1.
func dataStructTest() {
	// string
	// slice
	// map
	// channel
	// goroutine
}

// golang package list: https://golang.org/pkg/
// 常用包
// strings 字符串处理
//
// Package sync

// - [sync.Map详解](https://juejin.im/post/5d36a7cbf265da1bb47da444)
func syncMapTest() {

	m := sync.Map{}
	// Store sets the value for a key.
	m.Store("key", "value")

	// Load returns the value stored in the map for a key, or nil if no value is present.
	// The ok result indicates whether value was found in the map.
	vaule, ok := m.Load("key")
	if ok {
		fmt.Printf("key:%s\n", vaule)
	}

	// LoadOrStore returns the existing value for the key if present.
	//  Otherwise, it stores and returns the given value. The loaded result is true if the value was loaded, false if stored.
	_, ok = m.LoadOrStore("LoadOrStore", "hello world.")
	if ok {
		fmt.Println("key LoadOrStore exist")
	} else {
		fmt.Printf("key LoadOrStore not exist, add key.\n")
	}

	// Delete deletes the value for a key.
	m.Delete("key")

}

//
func main() {
	syncMapTest()
}
