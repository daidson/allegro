# Autoversion makefile
# (C) 2015, Ruben Carlo Benante
# data: 2015-10-07
# Versao para Allegro

# Usage:
# * From linux propmt:
# 	- Normal C program (ex1.c)
# 		$ make ex1.x
# 	_ Aspipo program (ex1.c)
# 		$ make ex1.x obj=libaspipo-yx64.o
# * From vim command:
# 	- Normal C program (ex1.c)
# 		:make
# 	- Aspipo program (ex1.c)
# 		:make obj=libaspipo-ux64.o
#

.PHONY: clean
.PRECIOUS: %.o
SHELL=/bin/bash -o pipefail

MAJOR = 0
MINOR = 1
BUILD = $(shell date +"%g%m%d.%H%M%S")
DEFSYM = $(subst .,_,$(BUILD))
VERSION = "\"$(MAJOR).$(MINOR).$(BUILD)\""
CC = gcc
CFLAGS = -Wall -g -O0 -std=gnu99
#-ansi -pedantic-errors -c -Ofast - Wextra
CPPFLAGS = -DVERSION=$(VERSION) -DBUILD="\"$(BUILD)""
LDLIBS = -Wl,--defsym,BUILD_$
