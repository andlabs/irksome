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
	initnicks	[]string
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

func (m *message) InitialNicks() []string {
	return m.initnicks
}

func (m *message) Formatted() (f iface.Formatted) {
	if m.ty != iface.Line && m.raw[0] != []byte("say") && m.raw[0] != []byte("do") {
		f.Text = string(m.Raw())
		return
	}
	s := ""
	n := 0
	for i := 0; i < len(m.raw[1:]); i++ {
		style := iface.Style{
			Start:	n,
		}
		s = append(s, string(m.raw[i]))
		switch m.raw[i] {
		case []byte("bold"):
			style.Add |= iface.Bold
		case []byte("italic"):
			style.Add |= iface.Italic
		}
		f.Styles = append(f.Styles, style)
		n += len(m.raw[i])
		style.Remove = style.Add
		style.Add = 0
		style.Start = n
		f.Styles = append(f.Styles, style)
		s += " "
		n++
	}
	f.Text = s[:len(s) - 1]
	return f
}

func (m *message) LogLine() string {
	return "[" + m.time.String() + "] " + string(m.Raw())
}
