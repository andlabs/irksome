// 25 january 2015
package main

// #cgo pkg-config: gtk+-3.0
// #include "irksome.h"
import "C"

//go:generate glib-compile-resources --target zresources.c --generate-source gresources.xml
//go:generate go run tools/ui2cdecl.go mainwin.ui zmainwinui.h MainWindow /irksome/mainwin.ui

var mainWindowLoaded = make(chan struct{})
var quit = make(chan struct{})

func main() {
	startC()
	C.tellUI(C.mLoadMainWindow, nil, C.FALSE)
	<-mainWindowLoaded
	<-quit
	println("exiting")
}
