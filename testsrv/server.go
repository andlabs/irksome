// 25 january 2015
package testsrv

import (
	"time"
	"sync"
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
			s.c <- &message{
				server:	s,
				raw:		[]byte("connected"),
				ty:		iface.Connected,
				time:		time.Now(),
			}
		case mm := <-s.c:
			m := mm.(*message)
			parts := bytes.Split(m.raw, []byte(" "))
			switch parts[0] {
			// commands
			case []byte("join"):
				// TODO
			case []byte("msg"):
				// TODO
			case []byte("quit"):
				s.nicklock.Lock()
				s.c <- &message{
					server:	s,
					// TODO spaces
					raw:		append([]byte(s.nick + " quit: "), parts[1:]...)
					ty:		iface.Disconnected,
					time:		time.Now(),
				}
				s.nicklock.Unlock()
			case []byte("nick"):
				new := string(parts[1])
				if new == "illegal" {
					// TODO
					break
				}
				s.nicklock.Lock()
				s.nick = new
				s.nicklock.Unlock()
				s.c <- &message{
					server:	s,
					raw:		[]byte("nick changed successfully"),
					ty:		iface.YourNickChanged,
					time:		time.Now(),
				}
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

func (s *Server) Raw(msg string) iface.Message {
	return &message{
		server:	s,
		raw:		[]byte(msg),
		ty:		iface.Line,
		time:		time.Now(),
	}
}

func (s *Server) Join(channel string, key string) iface.Message {
	return s.Raw("join " + channel + " key")
}

func (s *Server) Query(nick string, msg string) iface.Message {
	return s.Raw("msg " + nick + " " + msg)
}

func (s *Server) Quit(reason string) iface.Message {
	return s.Raw("quit " + reason)
}

func (s *Server) Nick() string {
	s.nicklock.Lock()
	defer s.nicklock.Unlock()
	return s.nick
}

func (s *Server) SetNick(new string) iface.Message {
	return s.Raw("nick " + new)
}
