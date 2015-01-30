// 30 january 2015
#include "irksome.h"

GtkTextTag *tagNormal;
GtkTextTag *tagBold;
GtkTextTag *tagItalic;
GtkTextTag *tagUnderline;
GtkTextTag *tagStrikethrough;
GtkTextTag *tagMonospace;
GtkTextTag *tagReverse;
GtkTextTag *tagFGColors[nFormattedColors];
GtkTextTag *tagBGColors[nFormattedColors];

GtkTextTagTable *tagtable;

static GtkTextTag *xtagWith(char *first, ...)
{
	GtkTextTag *tag;
	va_list ap;

	tag = gtk_text_tag_new(NULL);
	va_start(ap, first);
	g_object_set_valist(tag, first, ap);
	va_end(ap);
	gtk_text_tag_table_add(tagtable, tag);
	return tag;
}

#define tagWith(a, b) xtagWith(a, b, NULL)

// TODO for tagNormal and tagMonospace, see what Konversation uses (in the latter case, for MOTDs)
// TODO verify tagBold, tagItalic, and tagUnderline with real Konversation
void initTextTags(void)
{
	int i;

	tagtable = gtk_text_tag_table_new();
//TODO	tagNormal = tagWith("xxx", xxx);
	tagBold = tagWith("weight", PANGO_WEIGHT_BOLD);
	tagItalic = tagWith("style", PANGO_STYLE_ITALIC);
	tagUnderline = tagWith("underline", PANGO_UNDERLINE_SINGLE);
	tagStrikethrough = tagWith("strikethrough", TRUE);
//TODO	tagMonospace = tagWith("xxx", xxx);
//TODO	tagReverse = tagWith("xxx", xxx);
	for (i = 0; i < nFormattedColors; i++) {
		tagFGColors[i] = tagWith("foreground-rgba", &(formattedColors[i]));
		tagBGColors[i] = tagWith("background-rgba", &(formattedColors[i]));
	}
}
