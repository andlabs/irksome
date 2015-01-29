// 28 january 2015
package testsrv

import (
	"github.com/andlabs/irksome/iface"
)

type channel struct {
	name	string
	server	*server
	isQuery	bool
}

func (c *channel) Name() string {
	return c.name
}

func (c *channel) Server() iface.Server {
	return c.server
}

func (c *channel) IsQuery() bool {
	return c.isQuery
}

func (c *channel) Say(what []byte) {
	// TODO
}

func (c *channel) Do(what []byte) {
	// TODO
}

func (c *channel) Leave(reason []byte) {
	// TODO
}
