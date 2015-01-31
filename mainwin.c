// 25 january 2015
#include "irksome.h"

#include "zmainwinui.h"

static MainWindow *mainwin;
static GtkTreeStore *chanlist;

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
	gtk_tree_model_get_iter(GTK_TREE_MODEL(chanlist), &iter, path);
	gtk_tree_store_set(chanlist, &iter, 1, &(colors[colorTabDefault]), -1);

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
	chanlist = gtk_tree_store_new(2, G_TYPE_STRING, GDK_TYPE_RGBA);
	gtk_tree_view_set_model(GTK_TREE_VIEW(mainwin->chanlist), GTK_TREE_MODEL(chanlist));
	col = gtk_tree_view_column_new_with_attributes(NULL,
		gtk_cell_renderer_text_new(),
		"text", 0,
		"foreground-rgba", 1,
		NULL);
	gtk_tree_view_append_column(GTK_TREE_VIEW(mainwin->chanlist), col);
	g_signal_connect(mainwin->chanlist, "row-activated", G_CALLBACK(switchChannel), NULL);
	{	// TODO
		GtkTreeIter first, second;
		GtkTreeIter iter;

		gtk_tree_store_insert(chanlist, &first, NULL, 0);
		gtk_tree_store_set(chanlist, &first, 0, "first", 1, &colors[colorTabDefault], -1);
		gtk_tree_store_insert(chanlist, &iter, &first, 0);
		gtk_tree_store_set(chanlist, &iter, 0, "#channel", 1, &colors[colorTabChannelMessage], -1);
		gtk_tree_store_insert(chanlist, &iter, &first, 1);
		gtk_tree_store_set(chanlist, &iter, 0, "#chan2", 1, &colors[colorTabQueryMessage], -1);
		gtk_tree_store_insert(chanlist, &iter, &first, 2);
		gtk_tree_store_set(chanlist, &iter, 0, "username", 1, &colors[colorTabHighlight], -1);
		gtk_tree_store_insert(chanlist, &second, NULL, 1);
		gtk_tree_store_set(chanlist, &second, 0, "second", 1, &colors[colorTabApplicationEvent], -1);
	}
	// TODO make this automatic
	gtk_tree_view_expand_all(GTK_TREE_VIEW(mainwin->chanlist));

	// chat window stuff
	applyChatBackgroundColor(mainwin->chat);

	tellGo(mMainWindowLoaded, NULL, FALSE, 0, 0);
}
