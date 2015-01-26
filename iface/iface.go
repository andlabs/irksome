// 23 january 2015
package iface

// Server describes a server.
type Server interface {
	// In returns a channel of messages to send to the server.
	// You may send to this channel.
	// In shall not change during the lifetime of the Server object.
	In() chan<- Message

	// Out returns a channel of messages to receive from the server.
	// You may receive from this channel.
	// Out shall not change during the lifetime of the Server object.
	// (TODO rename In and Out?)
	Out() <-chan Message

	// Connect establishes a connection to the server.
	// After Connect, In will start processing messages.
	// Out will also send a message when disconnected.
	// Connection errors will be sent across Out.
	// TODO what if allready connected?
	Connect()

	// Raw returns a Message that will result in the raw text being sent to the server when sent to In.
	Raw(message string) Message

	// Join returns a Message that, when sent to In, will result in that channel being joined.
	// key contains the channel password, if any.
	Join(channel string, key string) Message

	// Query returns a Message that, when sent to In, will result in the given nickname receiving the given line in a private message.
	// It is analogous to Join, and if the send succeeded, will return a QueryStarted message containing the Channel to use for future communications.
	Query(nick string, message string) Message

	// Quit returns a Message that, when sent to In, will result in the connection to the server being closed.
	// You can specify an optional reason.
	Quit(reason string) Message

	// Nick returns the current nickname.
	// It automatically responds to server-side nickname changes.
	Nick() string

	// SetNick returns a Message that, when sent to In, sets the current nickname.
	SetNick(nick string) Message
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

	// Previous returns the old nickname if the message type is either YourNickChanged or OtherNickChanged.
	Previous() string

	// Nick returns the new nickname if the message type is either YourNickChanged or OtherNickChanged.
	// Nick returns the nickname of the person who joined or left if the message type is OtherJoined or OtherLeft.
	// Nick returns the nickname of the person in the query session if the message type is QueryStarted.
	Nick() string

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
	YourNickChanged
	OtherNickChanged
	OtherJoined
	OtherLeft				// applies to both parts and disconnects (TODO)
	QueryStarted
)

// Channel represents a channel.
type Channel interface {
	Name() string
	Server() Server

	// Members returns a list of nicknames in the channel.
	// If the returned list has length zero, the Channel object represents a private message.
	// In that case, Name() returns the nickname of the person you are talking to.
	Members() []string

	// Say returns a Message that, when sent to Server().C(), says the line in the channel as a normal line.
	Say(what string) Message

	// Do returns a Message that, when sent to Server().In(), says the line in the channel as an action line.
	// For instance, IRC clients typically denote actions with "/me".
	Do(what string) Message

	// Leave returns a Message that, when sent to Server().In(), leaves the channel.
	// An optional reason may be specified.
	Leave(reason string) Message
}
