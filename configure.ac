dnl **************************************************************************
dnl Version info
dnl **************************************************************************

m4_define([major_version], [1])
m4_define([minor_version], [0])
m4_define([micro_version], [0])
m4_define([sound_applet_version], [major_version.minor_version.micro_version])

dnl **************************************************************************
dnl Bug report
dnl **************************************************************************

m4_define([sound_applet_bug_report],
          [https://github.com/muktupavels/sound-applet/issues])

dnl **************************************************************************
dnl Initialize autoconf
dnl **************************************************************************

AC_INIT([sound-applet], sound_applet_version, [sound_applet_bug_report])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

dnl **************************************************************************
dnl Set release policy
dnl **************************************************************************

AX_IS_RELEASE([git-directory])

dnl **************************************************************************
dnl Enable debug
dnl **************************************************************************

AX_CHECK_ENABLE_DEBUG([yes])

dnl **************************************************************************
dnl Add warning flags
dnl **************************************************************************

AX_COMPILER_FLAGS([WARN_CFLAGS], [WARN_LDFLAGS])

dnl **************************************************************************
dnl Initialize automake
dnl **************************************************************************

AM_INIT_AUTOMAKE([1.13 no-dist-gzip dist-xz subdir-objects tar-ustar -Wno-portability])
AM_MAINTAINER_MODE([enable])
AM_SILENT_RULES([yes])

dnl **************************************************************************
dnl Initialize libtool
dnl **************************************************************************

LT_INIT([disable-static])
LT_LIB_M

dnl **************************************************************************
dnl Check for required programs
dnl **************************************************************************

AC_PROG_CC
AC_PATH_PROG([GLIB_MKENUMS], [glib-mkenums])

dnl **************************************************************************
dnl Internationalization
dnl **************************************************************************

GETTEXT_PACKAGE=lv.id.muktupavels.sound-applet
AC_SUBST([GETTEXT_PACKAGE])
AC_DEFINE_UNQUOTED([GETTEXT_PACKAGE], ["$GETTEXT_PACKAGE"],
                   [Define the gettext package to be used])

dnl **************************************************************************
dnl Check for required packages
dnl **************************************************************************

GTK_REQUIRED=3.22.0
CANBERRA_REQUIRED=0.13
GLIB_REQUIRED=2.44.0

PKG_CHECK_MODULES([SOUND_APPLET], [
  gtk+-3.0 >= $GTK_REQUIRED
  libcanberra-gtk3 >= $CANBERRA_REQUIRED
  glib-2.0 >= $GLIB_REQUIRED
])

dnl **************************************************************************
dnl libgnome-volume-control
dnl **************************************************************************

PKG_CHECK_MODULES([GVC], [
  gio-2.0
  gobject-2.0
  libpulse
  libpulse-mainloop-glib
])

PKG_CHECK_EXISTS([alsa], [found_alsa="yes"], [found_alsa="no"])

AS_IF([test "x$found_alsa" = "xyes"], [
  AC_DEFINE([HAVE_ALSA], [1], [Define to 1 if alsa is available])
  PKG_CHECK_MODULES([ALSA], [alsa])
])

AM_CONDITIONAL(HAVE_ALSA, [test "x$found_alsa" = "xyes"])

dnl **************************************************************************
dnl Process .in files
dnl **************************************************************************

AC_CONFIG_FILES([
  Makefile
  gvc/Makefile
  src/Makefile
])

AC_OUTPUT

dnl **************************************************************************
dnl Show summary
dnl **************************************************************************

echo ""
echo "  Sound Applet $VERSION"
echo "  `echo Sound Applet $VERSION | sed "s/./=/g"`"
echo ""
echo "  srcdir ......................: ${srcdir}"
echo ""
echo "  compiler ....................: ${CC}"
echo "  cflags ......................: ${CFLAGS}"
echo ""
echo "  prefix ......................: ${prefix}"
echo "  exec_prefix .................: ${exec_prefix}"
echo "  libdir ......................: ${libdir}"
echo "  sysconfdir ..................: ${sysconfdir}"
echo "  libexecdir ..................: ${libexecdir}"
echo ""
