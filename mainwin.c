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
	tellGo(mSendMessage, g_strdup(text), TRUE, 0, 0);
	gtk_entry_set_text(entry, "");
}

static void switchChannel(GtkTreeView *chanlistwidget, GtkTreePath *path, GtkTreeViewColumn *col, gpointer data)
{
	GtkTreeIter iter;

	// TODO remove this
	printf("%s\n", gtk_tree_path_to_string(path));

	// TODO what if nothing is selected?

	// mark the tab as viewed
/*TODO
	gtk_tree_model_get_iter(GTK_TREE_MODEL(chanlist), &iter, path);
	gtk_tree_store_set(chanlist, &iter, 1, &(colors[colorTabDefault]), -1);
*/

	// TODO implement the rest
}

void loadMainWindow(void)
{
	GtkTreeViewColumn *col;

	mainwin = makeMainWindowFromUIFile();

	// window stuff
	// TODO
	g_signal_connect(mainwin->win, "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_widget_show_all(mainwin->win);

	// line stuff
	g_signal_connect(mainwin->line, "activate", G_CALLBACK(enterLine), NULL);

	// channel list and signals
	// TODO require a channel selected?
	setupChannelList(GTK_TREE_VIEW(mainwin->chanlist));
	g_signal_connect(mainwin->chanlist, "row-activated", G_CALLBACK(switchChannel), NULL);
	// TODO make this automatic
	gtk_tree_view_expand_all(GTK_TREE_VIEW(mainwin->chanlist));

	// chat window stuff
	applyChatBackgroundColor(mainwin->chat);

	tellGo(mMainWindowLoaded, NULL, FALSE, 0, 0);
}
