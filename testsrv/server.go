// 28 january 2015
package testsrv

import (
	"github.com/andlabs/irksome/iface"
)

type server struct {
	users	map[string]*user
	you		string
	chans	map[string]*channel

	in		chan []byte
	out		chan []byte

	// for the iface.Server interface
	// see iface.go for THAT
	c		chan iface.Message
}

func (s *server) initImpl() {
	s.users = make(map[string]*user)
	s.chans = make(map[string]*channel)
	s.in = make(chan []byte)
	s.out = make(chan []byte)
}

func (s *server) setInitialNick(nick string) {
	s.users[nick] = newUser(nick)
	s.you = nick
}

func (s *server) runImpl() {
	for {
		select {
		case msg := <-s.in:
			s.handle(msg)
		}
	}
}

// a command to the server is a line of the form
// 	cmd arg arg arg ...
// 	cmd arg :arbitrary text treated as a single argument
// it may not have initial spaces or more than one space between arguments

func (s *server) handle(msg []byte) {
	parts := s.split(msg)
	if len(parts) == 0 {		// nothing
		continue
	}
	cmd := parts[0]
	args := parts[1:]
	switch cmd {
	default:
		out <- append([]byte("error :unknown command "), cmd...)
	}
}

func (s *server) split(msg []byte) [][]byte {
	parts := make([][]byte, 0, len(msg) / 4)
	pstart := 0
	// this may look like a bug, but it's not...
	for i := 0; i <= len(msg); i++ {
		// ...because the left side of the || handles the last word!
		if i == len(msg) || msg[i] == ' ' {
			part := msg[pstart:i]
			parts = append(parts, part)
			pstart = i + 1
			continue
		}
		if i == pstart && msg[i] == ':' {
			part := msg[pstart:]
			parts = append(parts, part)
			break
		}
	}
	return parts
}
