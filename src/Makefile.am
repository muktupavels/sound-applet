NULL =

bin_PROGRAMS = \
	lv.id.muktupavels.sound-applet \
	$(NULL)

lv_id_muktupavels_sound_applet_CPPFLAGS = \
	-DG_LOG_DOMAIN=\"lv.id.muktupavels.sound-applet\" \
	-DG_LOG_USE_STRUCTURED=1 \
	-I$(top_srcdir)/gvc/gvc \
	-I$(top_srcdir) \
	$(NULL)

lv_id_muktupavels_sound_applet_CFLAGS = \
	$(SOUND_APPLET_CFLAGS) \
	$(WARN_CFLAGS) \
	$(AM_CFLAGS) \
	$(NULL)

lv_id_muktupavels_sound_applet_SOURCES = \
	gf-sound-applet.c \
	gf-sound-applet.h \
	gvc-channel-bar.c \
	gvc-channel-bar.h \
	gvc-stream-status-icon.c \
	gvc-stream-status-icon.h \
	main.c \
	$(NULL)

lv_id_muktupavels_sound_applet_LDFLAGS = \
	$(WARN_LDFLAGS) \
	$(AM_LDFLAGS) \
	$(NULL)

lv_id_muktupavels_sound_applet_LDADD = \
	$(top_builddir)/gvc/libgvc.la \
	$(SOUND_APPLET_LIBS) \
	$(LIBM) \
	$(NULL)

-include $(top_srcdir)/git.mk
