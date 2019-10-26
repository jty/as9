TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

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
    pseudo9.h \
    symtab.h \
    table9.h \
    util.h
