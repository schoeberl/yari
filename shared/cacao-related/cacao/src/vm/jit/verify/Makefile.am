## src/vm/jit/verify/Makefile.am
##
## Copyright (C) 1996-2005, 2006 R. Grafl, A. Krall, C. Kruegel,
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
## Contact: cacao@cacaojvm.org
##
## Authors: Christian Thalinger
##
## Changes: Edwin Steiner
##
## $Id: Makefile.am 6275 2007-01-03 22:39:14Z edwin $

## Process this file with automake to produce Makefile.in

AM_CPPFLAGS = -I$(top_srcdir)/src -I$(top_srcdir)/src/vm/jit/$(ARCH_DIR) -I$(top_srcdir)/src/vm/jit/$(ARCH_DIR)/$(OS_DIR)

LIBS =

noinst_LTLIBRARIES = libverify.la

libverify_la_SOURCES = \
	typecheck.c \
	typecheck.h \
	typecheck-common.c \
	typecheck-common.h \
	typecheck-builtins.inc \
	typecheck-fields.inc \
	typecheck-invoke.inc \
	typecheck-multianewarray.inc \
	typecheck-stackbased.c \
	typecheck-typeinferer.c \
	typecheck-typeinferer.h \
	typecheck-stackbased-gen.inc \
	typecheck-variablesbased-gen.inc \
	typecheck-typeinferer-gen.inc \
	typeinfo.c \
	typeinfo.h


## Local variables:
## mode: Makefile
## indent-tabs-mode: t
## c-basic-offset: 4
## tab-width: 8
## compile-command: "automake --add-missing"
## End:
