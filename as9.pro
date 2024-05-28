TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CFLAGS += -std=c89 -Wno-implicit-function-declaration
QMAKE_CC=gcc

SOURCES += \
    as.c \
    asdef.c \
    do9.c \
    eval.c \
    ffwd.c \
    output.c \
    pseudo.c \
    symtab.c \
    util.c

HEADERS += \
    as.h \
    asdef.h \
    decl.h \
    do9.h \
    eval.h \
    ffwd.h \
    output.h \
    pseudo.h \
    symtab.h \
    util.h
