// 25 january 2015
#include "irksome.h"

static gpointer uithread(gpointer data)
{
	gtk_init(NULL, NULL);
	gtk_main();
	tellGo(mQuit, NULL, FALSE, 0, 0);
	// TODO what to return?
}

void goUI(void)
{
	g_thread_new("ui", uithread, NULL);
}

void doUI(int what, gpointer arg, gint64 intarg, gint64 intarg2)
{
	switch (what) {
	case mLoadMainWindow:
		loadMainWindow();
		break;
	case mCreateTextBuffer:
		createTextBuffer();
		break;
	}
}
