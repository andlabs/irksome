// 26 january 2015
package iface

// TODO settle the overloading of definitions of 'message'
// TODO really return Messages and not send them immediately?

// Server represents a server.
type Server interface {
	// Send and Recv return channels that send and receive, respectively, Messages to/from the server.
	// The values of these channels are guaranteed not to change during the lifetime of the Server object, and they shall not be closed during said lifetime.
	Send() chan<- Message
	Recv() <-chan Message

	// Connect establishes the connection to the Server.
	// After Connect, Send and Recv will begin processing messages.
	// A Message of type Connected will be received once the connection has been established.
	// A Message of type Error will be received if the connection fails.
	// Connect may send protocol-specific handshake messages as necessary; the Server object's actual type should define an interface for this (for instance, for establishing the initial username and identifying information about a user).
	// (TODO what happens if already connected)
	Connect()

	// Raw returns a Message that, when sent, issues the given byte sequence directly to the server.
	// TODO hostmasks
	Raw(sequence []byte) Message

	// Join returns a Message that, when sent, ask the server to join a given channel.
	// If the Join succeeds, a Message of type Joined will be received; the value of Channel() on that Message should be used for all future accesses to that channel (until the channel is left or the server is disconnected).
	Join(channel string, password string) Message

	// Query is similar to Join, except that instead of joining a channel, it initiates a private conversation ("query") with a given user.
	// Because some protocols (IRC, for instance) don't have a special state for "querying someone else", Query() requires a line to send to the user at the same time.
	// On success, the received Message type will be QueryStarted instead of Joined, but the semantics are the same.
	Query(nick string, message []byte) Message

	// QueryDo is similar to Query, except the message is sent as an action; see Channel.Do().
	QueryDo(nick string, message []byte) Message

	// Quit returns a Message that, when sent, will lead to being disconnected from the server.
	// You may specify an optional reason.
	Quit(reason []byte) Message

	// TODO Nick()?

	// SetNick returns a Message that, when sent, requests that the server change your nickname to the given nick.
	// If successful, a Message of type YourNickChanged will be received.
	SetNick(newnick string) Message

	// Format takes the given Formatted and returns the byte sequence that it is equivalent to in the given protocol.
	// Formatting styles that are not supported are merely ignored.
	Format(f Formatted) []byte

	// Away returns a Message that, when sent, marks yourself as away.
	Away(reason string) Message

	// Back returns a Message that, when sent, marks yourself as no longer away.
	Back() Message

	// TODO user mode translation
}
