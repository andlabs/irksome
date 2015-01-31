// 25 january 2015
package main

import (
	"runtime"
)

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
func doGo(what C.int, arg C.gpointer, intarg C.gint64, intarg2 C.gint64) {
	switch what {
	case C.mQuit:
		quit <- struct{}{}
	case C.mMainWindowLoaded:
		mainWindowLoaded <- struct{}{}
	case C.mSendMessage:
		sendMessage(C.GoString(C.argToString(arg)))
	}
}

//export signalCReady
func signalCReady() {
	waitCReady <- struct{}{}
}
