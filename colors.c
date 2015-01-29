// 29 january 2015
#include "irksome.h"

// TODO verify these against Konversation's source and configuration defaults

static const char *colorStrings[nColors] = {
	[colorBackground] = "#FFFFFF",
	[colorMessage] = "#000000",
	[colorHighlight] = "#FF0000",
	[colorAction] = "#0000FF",
	[colorServerCommand] = "#91640A",
	[colorChannelCommand] = "#960096",
	[colorYourNick] = "#000001",
	[colorTimestamp] = "#709070",
	[colorHyperlink] = "#0000FF",
	[colorBacklog] = "#AAAAAA",
	[colorBackgroundAlt] = "#EDF4F9",
	[colorTabDefault] = "#000000",		// TODO especially this one
	[colorTabChannelMessage] = "#008000",
	[colorTabQueryMessage] = "#800000",
	[colorTabHighlight] = "#FF0000",
	[colorTabChannelEvent] = "#008000",
	[colorTabApplicationEvent] = "#C3C300",
};

GdkRGBA colors[nColors];

static const char *nickColorStrings[nNickColors] = {
	"#E90E7F",	"#8E55E9",	"#B30E0E",	"#18B33C",
	"#58ADB3",	"#9E54B3",	"#B39875",	"#3176B3",
};

GdkRGBA nickColors[nNickColors];

static const char *formattedColorStrings[nFormattedColors] = {
	"#FFFFFF",	"#000000",	"#000080",	"#008000",
	"#FF0000",	"#A52A2A",	"#800080",	"#FF8000",
	"#808000",	"#00FF00",	"#008080",	"#00FFFF",
	"#0000FF",	"#FFC0CB",	"#A0A0A0",	"#C0C0C0",
};

GdkRGBA formattedColors[nFormattedColors];

void initColors(void)
{
	int i;
	GdkRGBA rgba;
	GError *err = NULL;

	for (i = 0; i < nColors; i++) {
		// TODO verify that missing values are NULL and then check for them
		// TODO standardize "(no reason specified)" error text
		if (gdk_rgba_parse(&rgba, colorStrings[i]) == FALSE)
			g_error("error parsing color %d (no reason specified)", i);
		colors[i] = rgba;
	}
	for (i = 0; i < nNickColors; i++) {
		if (gdk_rgba_parse(&rgba, nickColorStrings[i]) == FALSE)
			g_error("error parsing nick color %d (no reason specified)", i);
		nickColors[i] = rgba;
	}
	for (i = 0; i < nFormattedColors; i++) {
		if (gdk_rgba_parse(&rgba, formattedColorStrings[i]) == FALSE)
			g_error("error parsing formatted color %d (no reason specified)", i);
		formattedColors[i] = rgba;
	}
}
