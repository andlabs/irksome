// 28 january 2015
package testsrv

import (
	"time"
	"bytes"
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
//TODO		args := parts[1:]
		switch {
		case bytes.Equal(cmd, []byte("error")):
			m.ty = iface.Error
			m.err = errors.New(string(parts[1]))
		}
		s.c <- m
	}
}

func (s *Server) msg(ty iface.MessageType, c *channel, raw []byte) *message {
	return &message{
		ty:		ty,
		server:	s,
		raw:		raw,
		time:		time.Now(),
		channel:	c,
	}
}

func (s *Server) C() <-chan iface.Message {
	return s.c
}

// TODO holding on to msg
func (s *Server) Raw(msg []byte) {
	s.in <- msg
}

func (s *Server) Join(channel string, password string) {
	// TODO
}

// TODO holding on
func (s *Server) Query(nick string, msg []byte) {
	// TODO
}

// TODO holding on
func (s *Server) QueryDo(nick string, msg []byte) {
	// TODO
}

// TODO holding on
func (s *Server) Quit(reason []byte) {
	// TODO
}

func (s *Server) SetNick(nick string) {
	// TODO
}

func (s *Server) Away(reason string) {
	// TODO
}

func (s *Server) Back() {
	// TODO
}
