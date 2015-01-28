// 28 january 2015
package testsrv

import (
	"github.com/andlabs/irksome/iface"
)

// TODO everything

func (s *Server) Format(f iface.Formatted) []byte {
	return []byte(f.Text)
}

func (m *message) Formatted() iface.Formatted {
	return iface.Formatted{
		Text:		string(m.raw),
	}
}

func (m *message) LogLine() []byte {
	return m.raw
}
