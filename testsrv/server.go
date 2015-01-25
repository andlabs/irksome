// 25 january 2015
package testsrv

import (
	"time"
	"sync"
	"strings"
	"github.com/andlabs/irksome/iface"
)

type Server struct {
	c		chan iface.Message
	start		chan bool
	// TODO connection mutex
	nick		string
	nicklock	sync.Mutex
}

func New() *Server {
	s := new(Server)
	s.c = make(chan iface.Message)
	s.start = make(chan bool)
	go s.do()
	return s
}

// TODO respect connection
func (s *Server) do() {
	for {
		select {
		case <-s.start:
			s.c <- s.newmsg(iface.Connected, nil, "connected")
		case mm := <-s.c:
			m := mm.(*message)
			switch parts[0] {
			// commands
			case []byte("join"):
				// TODO
			case []byte("msg"):
				// TODO
			case []byte("quit"):
				s.nicklock.Lock()
				quitraw := []byte{[]byte(s.nick), []byte("quit:")}
				s.nicklock.Unlock()
				quitraw = append(quitraw, bytes[1:]...)
				s.c <- &message{
					server:	s,
					raw:		quitraw,
					ty:		iface.Disconnected,
					time:		time.Now(),
				}
			case []byte("nick"):
				new := string(parts[1])
				if new == "illegal" {
					// TODO
					break
				}
				s.nicklock.Lock()
				s.nick = new
				s.nicklock.Unlock()
				s.c <- s.newmsg(iface.YourNickChanged, nil, "nick", "changed", "successfully")
			// tests
			}
		// TODO other cases
		}
	}
}

func (s *Server) C() chan iface.Message {
	return s.c
}

func (s *Server) Connect() {
	s.start <- true
}

func (s *Server) raw(msg ...string) iface.Message {
	return s.newmsg(iface.Line, nil, msg...)
}

func (s *Server) Raw(msg string) iface.Message {
	return s.raw(strings.Split(msg, " ")...)
}

func (s *Server) Join(channel string, key string) iface.Message {
	return s.raw("join", channel, "key")
}

func (s *Server) Query(nick string, msg string) iface.Message {
	return s.raw("msg", nick, msg)
}

func (s *Server) Quit(reason string) iface.Message {
	return s.raw("quit", reason)
}

func (s *Server) Nick() string {
	s.nicklock.Lock()
	defer s.nicklock.Unlock()
	return s.nick
}

func (s *Server) SetNick(new string) iface.Message {
	return s.raw("nick ", new)
}
