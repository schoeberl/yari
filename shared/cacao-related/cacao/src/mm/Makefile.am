## src/mm/Makefile.am
##
## Copyright (C) 1996-2005, 2006, 2007 R. Grafl, A. Krall, C. Kruegel,
## C. Oates, R. Obermaisser, M. Platter, M. Probst, S. Ring,
## E. Steiner, C. Thalinger, D. Thuernbeck, P. Tomsich, C. Ullrich,
## J. Wenninger, Institut f. Computersprachen - TU Wien
##
## This file is part of CACAO.
##
## This program is free software; you can redistribute it and/or
## modify it under the terms of the GNU General Public License as
## published by the Free Software Foundation; either version 2, or (at
## your option) any later version.
##
## This program is distributed in the hope that it will be useful, but
## WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
## General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program; if not, write to the Free Software
## Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
## 02110-1301, USA.
##
## $Id: Makefile.am 7289 2007-02-06 08:47:05Z twisti $

## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/vm/jit/$(ARCH_DIR) -I$(top_srcdir)/src/vm/jit/$(ARCH_DIR)/$(OS_DIR) -I$(top_builddir)/src

LIBS =

DIST_SUBDIRS = \
	boehm-gc \
	cacao-gc

if DISABLE_GC
GC_FILE = \
	nogc.c
endif

if ENABLE_GC_BOEHM
SUBDIRS = \
	boehm-gc

GC_FILE = \
	boehm.c

GC_LIB = \
	$(top_builddir)/src/mm/boehm-gc/libgc.la
endif

if ENABLE_GC_CACAO
SUBDIRS = \
	cacao-gc

GC_LIB = \
	$(top_builddir)/src/mm/cacao-gc/libgc.la
endif

noinst_LTLIBRARIES = \
	libmm.la

libmm_la_SOURCES = \
	$(GC_FILE) \
	gc-common.h \
	memory.c \
	memory.h

libmm_la_LIBADD = \
	$(GC_LIB)


## Local variables:
## mode: Makefile
## indent-tabs-mode: t
## c-basic-offset: 4
## tab-width: 8
## compile-command: "automake --add-missing"
## End:
