// 8 february 2015
package main

// TODO success for all of these

// Conn represents a link to a chat server.
// Despite the name, a Conn is responsible for reconnecting if the underlying net.Conn is disconnected for whatever reason; see Connect and Disconnect for details.
type Conn interface {
	// C returns a channel that incoming messages will be received on.
	// The value of C will not change during the lifetime of the Conn object.
	C() <-chan Message

	// Connect establishes an actual connection to the server.
	// Errors are communicated across C.
	// After Connect, a disconnected network connection will result in the Conn automatically reconnecting.
	// It is up to the implementation to provide connect-time parameters.
	Connect()

	// Disconnect disconnects from the currently active connection.
	// It also prevents automatic reconnection (until the next call to Connect).
	// An optional formatted reason for disconnecting may be specified.
	Disconnect(reason Formatted)

	// Raw sends the given raw message to the server.
	// TODO hostmasks
	Raw(message []byte)

	// Join attempts to join the named channel, with an optional password.
	// A successful Join will result in a Joined Message being sent.
	Join(channel string, password string)

	// TODO channel stuff

	// Query attempts to initiate a private conversation ("query") with the given user.
	// Because some protocols do not keep track of active private conversations (they are ad hoc), an initial message to send is required.
	// TODO QueryStarted message?
	// QUeryDo is like Query, but sends the message as an action instead.
	Query(nick string, message Formatted)
	QueryDo(nick string, message Formatted)

	// SetNick asks the server ot change your nick.
	// A NickChanged Message will be sent on success.
	SetNick(newnick string)

	// Away tells the server to mark you as away.
	// An optional formatted reason can be provided. (TODO sync with Disconnect)
	Away(reason Formatted)

	// Back tells the server that you have returned from being away.
	Back()

	// Format takes the given Formatted and returns the equivalent byte sequence in the implementation protocol.
	// Unsupported formatting features are ignored without error.
	Format(what Formatted) []byte

	// TODO user mode translation
}
