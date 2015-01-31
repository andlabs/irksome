// 28 january 2015
package main

import (
	"github.com/andlabs/irksome/iface"
	"github.com/andlabs/irksome/testsrv"
)

var servers []iface.Server
var channels [][]iface.Channel
var currentServer, currentChannel int

const (
	sTest = iota
	sIRC
	sSlack
)

func openServer(ty int, addr string, port int, tls bool) {
	var s iface.Server

	switch ty {
	case sTest:
		srv := testsrv.NewServer()
		srv.SetInitNick("andlabs")
		s = srv
	default:
		panicf("unrecognized server type %d", ty)
	}
	// TODO add server to UI here
	servers = append(servers, s)
	s.Connect()
	go listen(s)
}

func listen(s iface.Server) {
	for m := range s.C() {
		println(string(m.Raw()))
	}
}
