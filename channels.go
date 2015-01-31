// 30 january 2015
package main

import (
	"github.com/andlabs/irksome/iface"
)

// #include "irksome.h"
import "C"

type channel struct {
	name	string
	server	iface.Server
	channel	iface.Channel
}

var chans = make([]*channel, 0, 50)

var addChannel = make(chan *channel)
var channelAdded = make(chan C.gint64)

var parentServers = make(map[iface.Server]C.gint64)

func doChannels() {
	for {
		select {
		case cc := <-addChannel:
			chans = append(chans, cc)
			n := C.gint64(len(chans) - 1)
			parent := C.gint64(-1)
			if chans[n].channel != nil {
				parent = parentServers[chans[n].server]
			}
_=parent//TODO			C.tellUI(C.mAddChannel, strToArg(cc.name), C.TRUE, n, parent)
			if chans[n].channel == nil {
				parentServers[chans[n].server] = <-channelAdded
			} else {
				<-channelAdded
			}
			// TODO start monitoring
		}
	}
}
