// 25 january 2015
#include "irksome.h"

#include "zmainwinui.h"

static MainWindow *mainwin;

// TODO implement memory
// TODO make the strdup unnecessary
static void enterLine(GtkEntry *entry, gpointer data)
{
	const char *text;

	text = gtk_entry_get_text(entry);
	tellGo(mSendMessage, g_strdup(text), TRUE);
	gtk_entry_set_text(entry, "");
}

void loadMainWindow(void)
{
	mainwin = makeMainWindowFromUIFile();

	// window stuff
	// TODO
	g_signal_connect(mainwin->win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(mainwin->win);

	// line stuff
	g_signal_connect(mainwin->line, "activate", G_CALLBACK(enterLine), NULL);

	tellGo(mMainWindowLoaded, NULL, FALSE);
}
