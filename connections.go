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

var addChannel = make(chan *conn)
var channelAdded = make(chan C.gint64)

var parentServers = make(map[iface.Server]C.gint64)

func connections() {
	for {
		select {
		case cc := <-addChannel:
			conns = append(conns, cc)
			n := C.gint64(len(conns) - 1)
			parent := C.gint64(-1)
			if conns[n].channel != nil {
				parent = parentServers[conns[n].server]
			}
_=parent//TODO			C.tellUI(C.mAddChannel, strToArg(cc.name), C.TRUE, n, parent)
			if conns[n].channel == nil {
				parentServers[conns[n].server] = <-channelAdded
			} else {
				<-channelAdded
			}
			// TODO start monitoring
		}
	}
}
