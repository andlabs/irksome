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
	GtkWidget *win;

	switch (what) {
	case mMakeTestWindow:
		win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
		gtk_window_set_title(GTK_WINDOW(win), "irksome");
		g_signal_connect(win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
		gtk_widget_show_all(win);
		tellGo(mTestWindowMade, NULL, FALSE);
		break;
	}
}
