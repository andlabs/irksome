// 25 january 2015
package testsrv

import (
	"github.com/andlabs/irksome/iface"
)

type channel struct {
	s		*server
	name	string
	query	bool
}

func (c *channel) Name() string {
	return c.name
}

func (c *channel) Server() iface.Server {
	return c.s
}

func (c *channel) IsQuery() bool {
	return c.query
}

func (c *channel) Say(what string) iface.Message {
	return c.s.newmsg(iface.Line, c, "say", what)
}

func (c *channel) Do(what string) iface.Message {
	return c.s.newmsg(iface.Line, c, "do", what)
}

func (c *channel) Leave(reason string) iface.Message {
	return c.s.newmsg(iface.Line, c, "part", what)
}
