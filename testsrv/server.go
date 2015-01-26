// 25 january 2015
package testsrv

import (
	"fmt"
	"time"
	"sync"
	"strings"
	"github.com/andlabs/irksome/iface"
)

type Server struct {
	in		chan iface.Message
	out		chan iface.Message
	start		chan bool
	// TODO connection mutex
	nick		string
	nicklock	sync.Mutex
	channels	map[string]*channel
	chanlock	sync.Mutex
	queries	map[string]*channel
	qlock	sync.Mutex
}

func New() *Server {
	s := new(Server)
	s.in = make(chan iface.Message)
	s.out = make(chan iface.Message)
	s.start = make(chan bool)
	s.channels = make(map[string]*channel)
	s.queries = make(map[string]*channel)
	go s.do()
	return s
}

// TODO respect connection
func (s *Server) do() {
	for {
		select {
		case <-s.start:
			s.out <- s.newmsg(iface.Connected, nil, "connected")
		case mm := <-s.in:
			m := mm.(*message)
			parts := m.raw
			switch parts[0] {
			// commands
			case []byte("join"):
				s.chanlock.Lock()
				cn := string(parts[1])
				c := s.channels[cn]
				if c == nil {
					if cn == "#illegal" {
						// TODO
						s.chanlock.Unlock()
						break
					}
					c = &channel{
						s:		s,
						name:	cn,
					}
					s.channels[cn] = c
				}
				s.out <- &message{
					server:	s,
					raw:		[][]byte{[]byte("joined"), parts[1]},
					ty:		iface.Joined,
					time:		time.Now(),
					channel:	c,
				}
				s.chanlock.Unlock()
			case []byte("msg"):
				// TODO
			case []byte("quit"):
				s.nicklock.Lock()
				quitraw := []byte{[]byte(s.nick), []byte("quit:")}
				s.nicklock.Unlock()
				quitraw = append(quitraw, bytes[1:]...)
				s.out <- &message{
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
				s.out <- s.newmsg(iface.YourNickChanged, nil, "nick", "changed", "successfully")
			case []byte("say"):
				// TODO
			case []byte("do"):
				// TODO
			case []byte("part"):
				// TODO
			// tests
			}
		// TODO other cases
		}
	}
}

func (s *Server) In() chan<- iface.Message {
	return s.in
}

func (s *Server) Out() <-chan iface.Message {
	return s.out
}

func (s *Server) Connect() {
	s.start <- true
}

func (s *Server) errmsg(c *channel, format string, args ...interface{}) ifac.Message {
	return &message{
		server:	s,
		err:		fmt.Errorf(format, args...),
		ty:		iface.Error,
		time:		time.Now(),
		channel:	c,
	}
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
