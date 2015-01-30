// 25 january 2015
package main

import (
	"fmt"
)

// #cgo pkg-config: gtk+-3.0
// #cgo CFLAGS: --std=c99
// #include "irksome.h"
import "C"

//go:generate glib-compile-resources --target zresources.c --generate-source gresources.xml
//go:generate go run tools/ui2cdecl.go mainwin.ui zmainwinui.h MainWindow /irksome/mainwin.ui

var mainWindowLoaded = make(chan struct{})
var quit = make(chan struct{})

func panicf(format string, args ...interface{}) {
	panic(fmt.Errorf(format, args...))
}

func main() {
	startC()
	C.tellUI(C.mLoadMainWindow, nil, C.FALSE, 0)
	<-mainWindowLoaded
	openServer(sTest, "", 0, false)
	<-quit
	println("exiting")
}
