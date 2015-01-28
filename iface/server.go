// 26 january 2015
package iface

// TODO settle the overloading of definitions of 'message'
// TODO flooding/multiline messages (for slack) (see first TODO)
// TODO state thread safety of entire package
// TODO echo back of own lines (IRC doesn't; do other protocols?) needs to be documented (for IRC, server must fake it)

// Server represents a server.
type Server interface {
	// C returns a channel that will receive Messages from the Server.
	// The value returned by C is guaranteed not to change during the lifetime of the Server object, and it shall not be closed during said lifetime.
	C() <-chan Message

	// Connect establishes the connection to the Server.
	// After Connect, C will begin sending messages.
	// A Message of type Connected will be sent once the connection has been established.
	// A Message of type Error will be sent if the connection fails.
	// Connect may send protocol-specific handshake messages as necessary; the Server object's actual type should define an interface for this (for instance, for establishing the initial username and identifying information about a user).
	// (TODO what happens if already connected)
	Connect()

	// Raw issues the given byte sequence directly to the server.
	// TODO hostmasks
	// TODO holding on
	Raw(sequence []byte)

	// Join asks the server to join a given channel.
	// If the Join succeeds, a Message of type Joined will be snet; the value of Channel() on that Message should be used for all future accesses to that channel (until the channel is left or the server is disconnected).
	Join(channel string, password string)

	// Query is similar to Join, except that instead of joining a channel, it initiates a private conversation ("query") with a given user.
	// Because some protocols (IRC, for instance) don't have a special state for "querying someone else", Query() requires a line to send to the user at the same time.
	// On success, the Message type will be QueryStarted instead of Joined, but the semantics are the same.
	// TODO holding on
	Query(nick string, message []byte)

	// QueryDo is similar to Query, except the message is sent as an action; see Channel.Do().
	// TODO holding on
	QueryDo(nick string, message []byte)

	// Quit issues a request to be disconnected from the server.
	// You may specify an optional reason.
	// TODO holding on
	Quit(reason []byte)

	// TODO Nick()?

	// SetNick requests that the server change your nickname to the given nick.
	// If successful, a Message of type NickChanged will be sent.
	SetNick(newnick string)

	// Format takes the given Formatted and returns the byte sequence that it is equivalent to in the given protocol.
	// Formatting styles that are not supported are merely ignored.
	Format(f Formatted) []byte

	// Away marks yourself as away.
	// TODO use a []byte as usual?
	Away(reason string)

	// Back marks yourself as no longer away.
	Back()

	// TODO user mode translation
}
