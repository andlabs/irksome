// 25 january 2015

// because cgo...
#ifndef __IRKSOME_H__
#define __IRKSOME_H__

#include <gtk/gtk.h>

// interop.c
extern void goC(void);
extern void tellGo(int, gpointer, gboolean, gint64, gint64);
extern void tellUI(int, gpointer, gboolean, gint64, gint64);
extern char *argToString(gpointer);

// ui.c
extern void goUI(void);
extern void doUI(int, gpointer, gint64, gint64);

// values for the int argument to the tellXxx() and doXxx() functions
enum {
	// sent by UI thread to Go to indicate that the UI thread has finished running and that the program should be exited
	// no argument
	mQuit,

	// sent by Go to UI thread to load the main window
	// no arguments
	mLoadMainWindow,
	// sent in return after window has been loaded and shown
	// no arguments
	mMainWindowLoaded,

	// sent by UI thread to Go to send a message to the current channel
	// pointer argument is string to send
	// no int argument
	mSendMessage,

	// TODO have a sentinel here to prevent invalid messages?
};

// mainwin.c
extern void loadMainWindow(void);

// colors.c
// TODO get marker line colors
enum {
	colorBackground,
	colorMessage,
	colorHighlight,
	colorAction,
	colorServerCommand,
	colorChannelCommand,
	colorYourNick,
	colorTimestamp,
	colorHyperlink,
	colorBacklog,
	colorBackgroundAlt,
	colorTabDefault,
	colorTabChannelMessage,
	colorTabQueryMessage,
	colorTabHighlight,
	colorTabChannelEvent,
	colorTabApplicationEvent,
	nColors,
};
#define nNickColors 8
#define nFormattedColors 16
extern GdkRGBA colors[nColors];
extern GdkRGBA nickColors[nNickColors];
extern GdkRGBA formattedColors[nFormattedColors];
extern void initColors(void);
extern void applyChatBackgroundColor(GtkWidget *);

// texttags.c
extern GtkTextTag *tagNormal;
extern GtkTextTag *tagBold;
extern GtkTextTag *tagItalic;
extern GtkTextTag *tagUnderline;
extern GtkTextTag *tagStrikethrough;
extern GtkTextTag *tagMonospace;
extern GtkTextTag *tagReverse;
extern GtkTextTag *tagFGColors[nFormattedColors];
extern GtkTextTag *tagBGColors[nFormattedColors];
extern GtkTextTagTable *tagtable;
extern void initTextTags(void);

#endif
