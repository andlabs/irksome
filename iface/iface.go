// 23 january 2015
package iface

// Server describes a server.
type Server interface {
	// C returns a channel of messages.
	// You may send or receive from this channel.
	// C shall not change during the lifetime of the Server object.
	C() chan *Message

	// Connect establishes a connection to the server.
	// After Connect, C will start processing messages.
	// C will also send a message when disconnected.
	// Connection errors will be sent across C.
	Connect()

	// Raw returns a Message that will result in the raw text being sent to the server when sent to C.
	Raw(message string) Message

	// Join returns a Message that, when sent to C, will result in that channel being joined.
	// key contains the channel password, if any.
	Join(channel string, key string) Message

	// Quit returns a Message that, when sent to C, will result in the connection to the server being closed.
	// You can specify an optional reason.
	Quit(reason string) Message

	// TODO nickname management
}

// Message represents messages.
type Message interface {
	Type() MessageType
	Server() Server
	Raw() []byte
	Time() time.Time

	// Err will be non-nil if Type is Error.
	// If Type is Disconnected, Err will be non-nil if an error led to the disconnect.
	Err() error

	// Channel returns the Channel that the Message belongs to, or nil if the message belongs to the server but not any channel.
	// It shall be nil for Error, Connected, and Disconnected messages.
	// If the message is of type Joined, use the returned value to initialize any of your own data structures for handling the Channel.
	// When sending a Message, this should return the destination Channel, or should be nil for the server itself.
	// Note that private messages count as channels; see Channel for details.
	Channel() Channel

	// The remainder of these only apply to Line messages.

	// Formatted returns a Formatted that represents the line with all protocol-specific formatting marks processed.
	Formatted() Formatted

	// LogLine returns a LogLine that represents the line as it should appear in chat logs.
	LogLine() []byte
}

// CurrentChannel represents the currently visible channel in the UI.
// This is used for Message.Channel() to indicate that the message should be displayed in the current channel.
// This should never be issued in a message to send.
// Calling methods on CurrentChannel will panic.
var CurrentChannel = currentChannel

// MessageType represents a message type.
type MessageType uint
const (
	Error MessageType = iota
	Line
	Connected
	Disconnected
	Joined
)

// Channel represents a channel.
type Channel interface {
	Name() string
	Server() Server

	// Members returns a list of usernames in the channel.
	// If the returned list has length zero, the Channel object represents a private message.
	// In that case, Name() returns the username.
	Members() []string

	// Say returns a Message that, when sent to Server().C(), says the line in the channel as a normal line.
	Say(what string) Message

	// Do returns a Message that, when sent to Server().C(), says the line in the channel as an action line.
	// For instance, IRC clients typically denote actions with "/me".
	Do(what string) Message

	// Leave returns a Message that, when sent to Server().C(), leaves the channel.
	// An optional reason may be specified.
	Leave(reason string) Message
}
