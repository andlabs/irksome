// 25 january 2015
#include "irksome.h"
#include "_cgo_export.h"

static GThread *interopThread;
static GMainContext *interopContext;
static GMainLoop *interopMainLoop;

void goC(void)
{
	interopThread = g_thread_self();
	interopContext = g_main_context_new();
	interopMainLoop = g_main_loop_new(interopContext, TRUE);
	initColors();
	initTextTags();
	initChannels();
	goUI();
	signalCReady();
	g_main_loop_run(interopMainLoop);
}

typedef struct goMessage goMessage;

struct goMessage {
	int what;
	gpointer arg;
	gboolean free;
	gint64 intarg;
	gint64 intarg2;
	void (*where)(int, gpointer);
};

static gboolean dotell(gpointer data)
{
	goMessage *gm = (goMessage *) data;

	(*(gm->where))(gm->what, gm->arg);
	if (gm->free)
		g_free(gm->arg);
	g_free(gm);
	return FALSE;		// do not repeat
}

void tellGo(int what, gpointer arg, gboolean free, gint64 intarg, gint64 intarg2)
{
	goMessage *gm;

	gm = g_new(goMessage, 1);
	gm->what = what;
	gm->arg = arg;
	gm->free = free;
	gm->intarg = intarg;
	gm->intarg2 = intarg2;
	gm->where = doGo;
	// TODO evaluate blockingness of the above
	g_main_context_invoke(interopContext, dotell, gm);
}

void tellUI(int what, gpointer arg, gboolean free, gint64 intarg, gint64 intarg2)
{
	goMessage *gm;

	gm = g_new(goMessage, 1);
	gm->what = what;
	gm->arg = arg;
	gm->free = free;
	gm->intarg = intarg;
	gm->intarg2 = intarg2;
	gm->where = doUI;
	gdk_threads_add_idle(dotell, gm);
}

// cgo helpers

char *argToString(gpointer arg)
{
	return (char *) arg;
}

// TODO see if g_free() is compatible with free()
gpointer goStrToArg(char *gostr)
{
	char *gallocdup;

	gallocdup = g_strdup(gostr);
	free(gostr);
	return (gpointer) gallocdup;
}
