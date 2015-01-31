// 30 january 2015
package main

import (
	"github.com/andlabs/irksome/iface"
)

// #include "irksome.h"
import "C"

type conn struct {
	name	string
	server	iface.Server
	channel	iface.Channel
}

var conns = make([]*conn, 0, 50)

var newChannel = make(chan *conn)
var chanelCreated = make(chan struct{})

func connections() {
	for {
		select {
		case cc := <-newConnChan:
			conns = append(conns, cc)
//TODO			C.tellUI(C.mCreateChannel, strToArg(cc.name), C.TRUE, C.gint64(len(conns) - 1)
			<-channelCreated
		}
	}
}
