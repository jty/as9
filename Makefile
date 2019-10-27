

SRCH=   \
as.h    \
#

SRCC=   \
as.c    \
do9.c   \
eval.c  \
ffwd.c  \
output.c        \
pseudo.c        \
symtab.c        \
util.c          \
asdef.c 
#
# Set CFLAGS as '-std=c89' on Mac OSX to avoid warnings
# Set CFLAGS as '-std=c89 -DDEBUG-g' to debug compiler operation (lot of output)
#
# Set EXE=.exe in Windows
EXE=

all: as9$(EXE) as9debug$(EXE)


as9$(EXE) : $(SRCC) $(SRCH)
	$(CC) $(CFLAGS)  $(SRCC) -o $@

as9debug$(EXE) : $(SRCC) $(SRCH)
	$(CC) $(CFLAGS) -DDEBUG -g $(SRCC) -o $@

clean:
	rm -rf as9$(EXE) as9debug$(EXE) as9.dSYM as9debug.dSYM 
