# $Id$ $Revision$
## Process this file with automake to produce Makefile.in

CDT_VERSION="5:0:0"

pdfdir = $(pkgdatadir)/doc/pdf
pkgextraincludedir = $(pkgincludedir)
pkgconfigdir = $(libdir)/pkgconfig

AM_CPPFLAGS = -I$(top_srcdir)

pkginclude_HEADERS = cdt.h
noinst_HEADERS = dthdr.h
noinst_LTLIBRARIES = libcdt_C.la
lib_LTLIBRARIES = libcdt.la
man_MANS = cdt.3
pdf_DATA = cdt.3.pdf
pkgconfig_DATA = libcdt.pc

libcdt_C_la_SOURCES = dtclose.c dtdisc.c dtextract.c dtflatten.c \
	dthash.c dtlist.c dtmethod.c dtopen.c dtrenew.c dtrestore.c dtsize.c \
	dtstat.c dtstrhash.c dttree.c dtview.c dtwalk.c

libcdt_la_LDFLAGS = -version-info $(CDT_VERSION) -no-undefined
libcdt_la_SOURCES = $(libcdt_C_la_SOURCES)

cdt.3.pdf: cdt.3.ps
	@PS2PDF@ $< $@

cdt.3.ps: $(srcdir)/cdt.3
	@GROFF@ -Tps -man $< >$@

EXTRA_DIST = $(man_MANS) $(pdf_DATA) cdt.vcxproj*

DISTCLEANFILES = $(pdf_DATA) cdt.3.ps
