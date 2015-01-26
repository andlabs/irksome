// 25 january 2015
package iface

// Formatted represents a formatted string.
// See Style for more information.
type Formatted struct {
	Text		string
	Styles	[]Style
}

// Style contains instructions on how to style text.
// Each field in Formatted.Styles represents a starting point; a style is applied until the end of the string or a countering Style, whichever comes first.
// Each instance of Start may only appear once.
// Each element of Styles must be sorted by increasing value of Start.
type Style struct {
	Start		int		// in bytes
	Add		StyleBits	// bits of styles to add
	Remove	StyleBits	// bits of styles to remove (TODO what if bits are set in both?)
	FGColor	int		// if Add & FGColor != 0, foreground color index
	BGColor	int		// if Add & BGColor != 0, background color index
}

// StyleBits represents styles to add or remove.
type StyleBits uint64
const (
	Bold StyleBits = 1 << iota
	Italic
	Underline
	Strikethrough
	Monospace
	Reverse
	FGColor
	BGColor
)
