// 28 january 2015
package testsrv

import (
	"time"
	"errors"
	"github.com/andlabs/irksome/iface"
)

func NewServer() *Server {
	s := new(Server)
	s.c = make(chan iface.Message)
	return s
}

func (s *Server) SetInitNick(nick string) {
	s.initNick = nick
}

// TODO figure out what should happen when reconnecting without disconnecting first
func (s *Server) Connect() {
	go s.runImpl()
	go s.runMessager()
}

func (s *Server) runMessager() {
	s.c <- s.msg(iface.Connected, nil, nil)
	for msg := range s.out {
		m := new(message)
		m.raw = msg
		m.server = s
		m.time = time.Now()
		parts := s.split(msg)
		cmd := parts[0]
		args := parts[1:]
		switch cmd {
		case []byte("error"):
			m.ty = iface.Error
			m.err = errors.New(string(parts[1]))
		}
		s.c <- m
	}
}
