// 25 january 2015
package main

import (
	"runtime"
)

// #cgo pkg-config: gtk+-3.0
// #include "irksome.h"
import "C"

var waitCReady = make(chan struct{})

func startC() {
	go interop()
	// C.goC() in interop() actually does the work
	<-waitCReady
	close(waitCReady)
}

func interop() {
	// this part is critical
	runtime.LockOSThread()
	// after that, the following function does the real work
	C.goC()
}

//export doGo
func doGo(what C.int, arg C.gpointer) {
	switch what {
	case C.mQuit:
		quit <- struct{}{}
	}
}

//export signalCReady
func signalCReady() {
	waitCReady <- struct{}{}
}
