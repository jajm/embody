AC_PREREQ([2.67])
LT_PREREQ([2.2])

AC_INIT([embody], [1.1.0], [jajm@jajm.org])
LT_INIT()

AC_SUBST(LIBTOOL_CURRENT, 1)
AC_SUBST(LIBTOOL_REVISION, 0)
AC_SUBST(LIBTOOL_AGE, 0)

AC_CHECK_HEADERS([stdio.h stdlib.h stddef.h string.h stdint.h])

AC_CHECK_HEADERS([libtap13/tap.h], AC_SUBST(HAVE_LIBTAP13_TAP_H, yes))
AC_CHECK_LIB(tap13, tap_ok, AC_SUBST(HAVE_LIBTAP13, yes))

AS_IF([test "x$HAVE_LIBTAP13" = "xyes" && test "x$HAVE_LIBTAP13_TAP_H" = "xyes"],
	AC_SUBST(BUILD_TESTS, yes))

AC_CONFIG_FILES([
	Makefile
	src/Makefile
	include/Makefile
	t/Makefile
	embody.pc
	config.mk
])

AC_OUTPUT

if test "$BUILD_TESTS" != "yes"; then
	echo ""
	echo "Tests won't be built: libtap13 is missing."
fi
