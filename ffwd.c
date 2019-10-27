#include "ffwd.h"
#include <fcntl.h>
#include "util.h"
#include "asdef.h"

/*
 *      file I/O version of forward ref handler
 */
#define	FILEMODE	0644	/* file creat mode */
#define	UPDATE		2	/* file open mode */
#define	ABS		0	/* absolute seek */

static int	Forward =0;		/* temp file's file descriptor	*/
static char	Fwd_name[] = { "Fwd_refs" } ;

/*
 *      fwdinit --- initialize forward ref file
 */
void fwdinit()
{
    Forward = creat(Fwd_name,FILEMODE);
    if(Forward <0)
        fatal("Can't create temp file");
    close(Forward); /* close and reopen for reads and writes */
    Forward = open(Fwd_name,UPDATE);
    if(Forward <0)
        fatal("Forward ref file has gone.");
#ifndef DEBUG
    unlink(Fwd_name);
#endif
}

/*
 *      fwdreinit --- reinitialize forward ref file
 */
void fwdreinit()
{
    F_ref   = 0;
    Ffn     = 0;
    lseek(Forward,0L,ABS);   /* rewind forward refs */
    read(Forward,&Ffn,sizeof(Ffn));
    read(Forward,&F_ref,sizeof(F_ref)); /* read first forward ref into mem */
#ifdef DEBUG
    fprintf(stderr,"First fwd ref: %d,%d\n",Ffn,F_ref);
#endif
}

/*
 *      fwdmark --- mark current file/line as containing a forward ref
 */
void fwdmark()
{
    write(Forward,&Cfn,sizeof(Cfn));
    write(Forward,&Line_num,sizeof(Line_num));
}

/*
 *      fwdnext --- get next forward ref
 */
void fwdnext()
{
    int stat;

    stat = read(Forward,&Ffn,sizeof(Ffn));
#ifdef DEBUG
    fprintf(stderr,"Ffn stat=%d ",stat);
#endif
    stat = read(Forward,&F_ref,sizeof(F_ref));
#ifdef DEBUG
    fprintf(stderr,"F_ref stat=%d  ",stat);
#endif
    if( stat < 2 ){
        F_ref=0;Ffn=0;
    }
#ifdef DEBUG
    fprintf(stderr,"Next Fwd ref: %d,%d\n",Ffn,F_ref);
#endif
}
