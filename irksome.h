// 25 january 2015

// because cgo...
#ifndef __IRKSOME_H__
#define __IRKSOME_H__

#include <gtk/gtk.h>

// interop.c
extern void goC(void);
extern void tellGo(int, gpointer, gboolean);
extern void tellUI(int, gpointer, gboolean);
extern char *argToString(gpointer);

// ui.c
extern void goUI(void);
extern void doUI(int, gpointer);

// values for the int argument to the tellXxx() and doXxx() functions
enum {
	// sent by UI thread to Go to indicate that the UI thread has finished running and that the program should be exited
	// no argument
	mQuit,

	// sent by Go to UI thread to load the main window
	// no argument
	mLoadMainWindow,
	// sent in return after window has been loaded and shown
	// no argument
	mMainWindowLoaded,

	// sent by UI thread to Go to send a message to the current channel
	// argument is string to send
	mSendMessage,

	// TODO have a sentinel here to prevent invalid messages?
};

// mainwin.c
extern void loadMainWindow(void);

#endif
