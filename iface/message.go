// 28 january 2015
package main

import (
	"time"
)

// TODO get rid of Other distinguishment?
// TODO notices
// TODO action on a type mismatch

// Message represents a message received from the server.
type Message interface {
	Type() MessageType
	Server() Server
	Raw() []byte
	Time() time.Time

	// Channel returns the channel associated with the message.
	// This value is guaranteed to be the same between Join and Left/Disconnected.
	// If the value is nil, this is a server message.
	// If the value is CurrentChannel, this message should be posted to the current channel.
	Channel() Channel

	// If Type is Error, Err stores the error.
	Err() error

	// Reason returns the reason for the message.
	// The type must be Disconnected, OtherDisconnected, Left, OtherLeft, Away, or OtherAway.
	Reason() string

	// Nick returns the nickname of the user who sent the message.
	Nick() string

	// PrevNick returns the former nickname of the user whose nick was changed.
	// The type must be OtherNickChanged.
	PrevNick() string

	// InitialNicks returns the list of initial nicknames in a channel.
	// The type must be Joined.
	InitialNicks() []string

	// Formatted and LogLine return formatted and log-ready versions of a Message, respectively.
	Formatted() Formatted
	LogLine() []byte
}

// MessageType represnets the possible types of Messages.
// Pairs of messages (X, OtherX) mean the message X is sent for you and the message OtherX is sent for other people.
type MessageType uint
const (
	Error MessageType = iota
	Other
	Line
	Action
	Connected
	Disconnected
	OtherDisconnected
	Joined
	OtherJoined
	QueryStarted
	Left
	OtherLeft
	NickChanged
	OtherNickChanged
	Away
	OtherAway
	Back
	OtherBack
)
