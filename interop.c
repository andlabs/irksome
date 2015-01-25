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
	goUI();
	signalCReady();
	g_main_loop_run(interopMainLoop);
}

typedef struct goMessage goMessage;

struct goMessage {
	int what;
	gpointer arg;
	gboolean free;
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

void tellGo(int what, gpointer arg, gboolean free)
{
	goMessage *gm;

	gm = g_new(goMessage, 1);
	gm->what = what;
	gm->arg = arg;
	gm->free = free;
	gm->where = doGo;
	// TODO evaluate blockingness of the above
	g_main_context_invoke(interopContext, dotell, gm);
}

void tellUI(int what, gpointer arg, gboolean free)
{
	goMessage *gm;

	gm = g_new(goMessage, 1);
	gm->what = what;
	gm->arg = arg;
	gm->free = free;
	gm->where = doUI;
	gdk_threads_add_idle(dotell, gm);
}
