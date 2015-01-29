// 28 january 2015
package testsrv

import (
	"time"
	"github.com/andlabs/irksome/iface"
)

type message struct {
	ty		iface.MessageType
	server	*Server
	raw		[]byte
	time		time.Time
	channel	*channel
	err		error
	reason	string
	nick		string
	prevnick	string
	initnicks	[]string
}

func (m *message) Type() iface.MessageType {
	return m.ty
}

func (m *message) Server() iface.Server {
	return m.server
}

func (m *message) Raw() []byte {
	return m.raw
}

func (m *message) Time() time.Time {
	return m.time
}

func (m *message) Channel() iface.Channel {
	return m.channel
}

func (m *message) Err() error {
	return m.err
}

func (m *message) Reason() string {
	return m.reason
}

func (m *message) Nick() string {
	return m.nick
}

func (m *message) PrevNick() string {
	return m.prevnick
}

func (m *message) InitialNicks() []string {
	return m.initnicks
}
