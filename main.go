// 25 january 2015
package main

var quit = make(chan struct{})

func main() {
	startC()
	<-quit
	println("exiting")
}
