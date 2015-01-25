// 25 january 2015
#include "irksome.h"

#include "zmainwinui.h"

static MainWindow *mainwin;

void loadMainWindow(void)
{
	mainwin = makeMainWindowFromUIFile();
	// TODO
	g_signal_connect(mainwin->win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(mainwin->win);
	tellGo(mMainWindowLoaded, NULL, FALSE);
}
