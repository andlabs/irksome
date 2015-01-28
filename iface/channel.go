// 28 january 2015
package iface

// Channel represents both channels and private message queries.
// The lifetime of a Channel is until you leave, are kicked, or disconnected; a Server shall send the same Channel instance for a channel between joining and leaving/being kicked/disconnecting.
type Channel interface {
	Name() string
	Server() Server
	IsQuery() bool

	// Say sends the given message to the channel.
	Say(what []byte)

	// Do sends the given message to the channel as an action.
	// For instance, IRC actions are typically prefixed by /me when entered in a client.
	Do(what []byte)

	// Leave leaves a channel.
	// After Leave, use of this Channel instance for the same channel is invalid.
	// An optional reason may be specified.
	// TODO unsuccessful leaves?
	Leave(reason []byte)

	// TODO kicks
}

// CurrentChannel is a Channel instance that states that a server message should be printed in the currently viewed channel, regardless of what that channel should be.
// For example, /whois results and notices in IRC should use this special Channel.
// Attempts to call methods on CurrentChannel will result in a panic.
var CurrentChannel currentChannel

//go:generate go run ../tools/panicimplgen.go . iface Channel CurrentChannel currentChannel zcurrentchannel.go
type currentChannel struct{}
