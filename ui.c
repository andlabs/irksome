// 25 january 2015
#include "irksome.h"

static gpointer uithread(gpointer data)
{
	gtk_init(NULL, NULL);
	gtk_main();
	tellGo(mQuit, NULL, FALSE);
	// TODO what to return?
}

void goUI(void)
{
	g_thread_new("ui", uithread, NULL);
}

void doUI(int what, gpointer arg)
{
	// TODO
}
