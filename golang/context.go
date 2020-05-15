package main

import (
	"context"
	"log"
	"os"
	"time"
)

// go服务器中，对于每个请求的request都是在单独的goroutine中进行的，处理一个request也可能设计多个goroutine之间的交互，
// 使用context可以使开发者方便的在这些goroutine里传递request相关的数据、取消goroutine的signal或截止日期。

// Context结构
// Done 方法在Context被取消或超时时返回一个close的channel,close的channel可以作为广播通知，告诉给context相关的函数要停止当前工作然后返回。
// 当一个父operation启动一个goroutine用于子operation，这些子operation不能够取消父operation。下面描述的WithCancel函数提供一种方式可以取消新创建的Context.
// Context可以安全的被多个goroutine使用。开发者可以把一个Context传递给任意多个goroutine然后cancel这个context的时候就能够通知到所有的goroutine。

// Err 方法返回context为什么被取消。

// Deadline 返回context何时会超时。

// Value返回context相关的数据。

var logg *log.Logger

func someHandler() {
	// Context 的继承
	// 1. WithCancel函数，传递一个父Context作为参数，返回子Context，以及一个取消函数用来取消Context。
	ctx, cancel := context.WithCancel(context.Background())

	// 3. WithTimeout和WithDeadline基本上一样，这个表示是超时自动取消，是多少时间后自动取消Context的意思。
	context.WithTimeout(ctx, 3*time.Second)

	// 2. WithDeadline函数，和WithCancel差不多，它会多传递一个截止时间参数，意味着到了这个时间点，会自动取消Context，
	// 当然我们也可以不等到这个时候，可以提前通过取消函数进行取消。

	// 4. WithValue函数和取消Context无关，它是为了生成一个绑定了一个键值对数据的Context，这个绑定的数据可以通过Context.Value方法访问到，
	// 这是我们实际用经常要用到的技巧，一般我们想要通过上下文来传递数据时，可以通过这个方法，如我们需要tarce追踪系统调用栈的时候。
	context.WithValue(ctx, "hello", "world")
	context.WithValue(ctx, 1, 1)

	go doStuff(ctx)

	//10秒后取消doStuff
	time.Sleep(10 * time.Second)

	cancel()

}

//每1秒work一下，同时会判断ctx是否被取消了，如果是就退出
func doStuff(ctx context.Context) {
	for {
		time.Sleep(1 * time.Second)
		// select 用法
		select {
		case <-ctx.Done():
			logg.Printf("done")
			return
		default:
			logg.Printf("work")
		}
	}
}

func main() {
	logg = log.New(os.Stdout, "", log.Ltime)
	someHandler()
	logg.Printf("down")
}
