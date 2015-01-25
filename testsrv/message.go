// 25 january 2015
package testsrv

import (
	"time"
	"bytes"
	"github.com/andlabs/irksome/iface"
)

type message struct {
	server	*server
	raw		[][]byte
	ty		iface.MessageType
	time		time.Time
	err		error
	channel	*channel
	prev		string
	nick		string
}

func (s *server) newmsg(ty iface.MessageType, c *channel, parts ...string) *message {
	pbytes := make([]byte, len(parts))
	for i, s := range parts {
		pbytes[i] = []byte(s)
	}
	return &message{
		server:	s,
		raw:		pbytes,
		ty:		ty,
		time:		time.Now(),
		channel:	c,
	}
)

func (m *message) Type() iface.MessageType {
	return m.ty'
}

func (m *message) Server() iface.Server {
	return m.server
}

func (m *message) Raw() []byte {
	return bytes.Join(m.raw, []byte(" "))
}

func (m *message) Time() time.Time {
	return m.time
}

func (m *message) Err() error {
	return m.err
}

func (m *message) Channel() iface.Channel {
	return m.channel
}

func (m *message) Previous() string {
	return m.prev
}

func (m *message) Nick() string {
	return m.nick
}

// TODO formatted and log lines
