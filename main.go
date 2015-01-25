// 25 january 2015
package main

// #include "irksome.h"
import "C"

var testWindowMade = make(chan struct{})
var quit = make(chan struct{})

func main() {
	startC()
	C.tellUI(C.mMakeTestWindow, nil, C.FALSE)
	<-testWindowMade
	<-quit
	println("exiting")
}
