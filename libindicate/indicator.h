
#ifndef INDICATE_INDICATOR_H_INCLUDED__
#define INDICATE_INDICATOR_H_INCLUDED__ 1

#include <glib.h>
#include <glib-object.h>

/* Boilerplate */
#define INDICATE_TYPE_INDICATOR (indicate_indicator_get_type ())
#define INDICATE_INDICATOR(object) (G_TYPE_CHECK_INSTANCE_CAST ((object), INDICATE_TYPE_INDICATOR, IndicateIndicator))
#define INDICATE_IS_INDICATOR(object) (G_TYPE_CHECK_INSTANCE_TYPE((object), INDICATE_TYPE_INDICATOR))
#define INDICATE_INDICATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_CAST((klass), INDICATE_TYPE_INDICATOR, IndicateIndicatorClass))
#define INDICATE_IS_INDICATOR_CLASS(klass) (G_TYPE_CHECK_CLASS_TYPE((klass), INDICATE_TYPE_INDICATOR))
#define INDICATE_INDICATOR_GET_CLASS(object) (G_TYPE_INSTANCE_GET_CLASS((object), INDICATE_TYPE_INDICATOR, IndicateIndicatorClass))

/* This is a signal that signals to the indicator that the user
 * has done an action where they'd like this indicator to be
 * displayed. */
#define INDICATE_INDICATOR_SIGNAL_HIDE  "hide"
#define INDICATE_INDICATOR_SIGNAL_SHOW  "show"
#define INDICATE_INDICATOR_SIGNAL_DISPLAY  "user-display"

typedef struct _IndicateIndicator IndicateIndicator;
typedef struct _IndicateIndicatorClass IndicateIndicatorClass;

#include "server.h"

struct _IndicateIndicator {
	GObject parent;

	guint id;
	gboolean is_visible;
	IndicateServer * server;
};

struct _IndicateIndicatorClass {
	GObjectClass parent_class;

	void (*hide) (IndicateIndicator * indicator, gpointer data);
	void (*show) (IndicateIndicator * indicator, gpointer data);
	void (*user_display) (IndicateIndicator * indicator, gpointer data);

	const gchar * (*get_type) (IndicateIndicator * indicator);
};

IndicateIndicator * indicate_indicator_new (void);

/* Should these just be GObject properties? */
void indicate_indicator_set_property (IndicateIndicator * indicator, const gchar * property_name, const gchar * property_value);

/* Show and hide this indicator */
void indicate_indicator_show (IndicateIndicator * indicator);
void indicate_indicator_hide (IndicateIndicator * indicator);

gboolean indicate_indicator_is_visible (IndicateIndicator * indicator);

/* Every entry has an ID, here's how to get it */
guint indicate_indicator_get_id (IndicateIndicator * indicator);

/* Every entry has a type.  This should be created by the
 * subclass and exported through this pretty function */
const gchar * indicate_indicator_get_indicator_type (IndicateIndicator * indicator);


#endif /* INDICATE_INDICATOR_H_INCLUDED__ */

