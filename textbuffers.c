// 30 january 2015
#include "irksome.h"

typedef struct goTextBuffer goTextBuffer;

struct goTextBuffer {
	GtkTextBuffer *buf;
	// TODO scroll positions
};

static GArray *bufs = NULL;

void createTextBuffer(void)
{
	GtkTextBuffer *buf;
	goTextBuffer g;

	buf = gtk_text_buffer_new(tagtable);
	// we will always have the initial reference
	// when we switch buffers, switching will either add an extra ref or remove that extra ref, so we're good

	if (bufs == NULL)
		bufs = g_array_sized_new(FALSE, TRUE, sizeof (goTextBuffer), 50);
	g.buf = buf;
	g_array_append_val(bufs, g);

	tellGo(mTextBufferCreated, NULL, FALSE, (gint64) (bufs->len - 1), 0);
}
