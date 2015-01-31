// 30 january 2015
#include "irksome.h"

// TODO rename to channels

GtkTreeStore *connections;

enum {
	colName,
	colColor,
	colBuffer,
	// TODO scrolling
	colGoID,
	nColumns,
};

static GType coltypes[nColumns];

struct findIterForeachArgs {
	GtkTreeIter *iter;
	gint64 find;
	gboolean found;
};

static gboolean findIterForeach(GtkTreeModel *model, GtkTreePath *path, GtkTreeIter *iter, gpointer data)
{
	struct findIterForeachArgs *args = (struct findIterForeachArgs *) data;
	gint64 test;

	gtk_tree_model_get(model, iter, colGoID, &test, -1);
	if (test == args->find) {
		// this will do the copy as confirmed by Company in irc.gimp.net/#gtk+
		*(args->iter) = *iter;
		args->found = TRUE;
		return TRUE;
	}
	return FALSE;
}

// TODO see if we can only search toplevels with an option
static gboolean findIterForGoID(gint64 goID, GtkTreeIter *iter)
{
	struct findIterForeachArgs args;

	args.iter = iter;
	args.find = goID;
	args.found = FALSE;
	gtk_tree_model_foreach(GTK_TREE_MODEL(connections), findIterForeach, &args);
	return args.found;
}

void initConnections(void)
{
	coltypes[colName] = G_TYPE_STRING;
	coltypes[colColor] = GDK_TYPE_RGBA;
	coltypes[colBuffer] = GTK_TYPE_TEXT_BUFFER;
	// TODO scrolling
	coltypes[colGoID] = G_TYPE_INT64;
	connections = gtk_tree_store_newv(nColumns, coltypes);
}

void setupChannelList(GtkTreeView *chanlist)
{
	GtkCellRenderer *r;
	GtkTreeViewColumn *col;

	gtk_tree_view_set_model(chanlist, GTK_TREE_MODEL(connections));
	r = gtk_cell_renderer_text_new();
	col = gtk_tree_view_column_new_with_attributes(NULL, r,
		"text", colName,
		"foreground-rgba", colColor,
		NULL);
	gtk_tree_view_append_column(chanlist, col);

	// TODO connect signals
}

void addConnection(char *name, gint64 goID, gint64 parentID)
{
	GtkTreeIter iter;
	GtkTreeIter parent;
	GtkTextBuffer *buf;

	// TODO see if goID already exists?
	if (parentID == -1)
		gtk_tree_store_append(connections, &iter, NULL);
	else {
		if (!findIterForGoID(parentID, &parent))
			g_error("attempt to add channel list row %s under nonexistent parent ID %" G_GINT64_FORMAT, name, parentID);
		gtk_tree_store_append(connections, &iter, &parent);
	}

	// the instance here has a refcount of 1
	// every time we swap out text buffers in the GtkTextView, it will add/remove its own reference, so we're good
	buf = gtk_text_buffer_new(tagtable);

	gtk_tree_store_set(connections, &iter,
		colName, name,
		colBuffer, buf,
		colGoID, goID,
		-1);
//TODO	tellGo(mConnectionAdded, NULL, FALSE, 0, 0);
}
