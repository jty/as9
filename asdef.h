/*
 *      machine independent definitions and global variables
 */
#ifndef ASDEF_H
# define ASDEF_H 1
#include <stdio.h>

typedef int bool;

#define YES     1
#define NO      0
#define ERR     (-1)

#define MAXBUF  256     /* Line buffer */
#define MAXOP   10      /* longest mnemonic */
#define MAXLAB  80      /* Label */
#define MAXPATH 256
#define E_LIMIT 32
#define P_LIMIT 64

/*      Character Constants     */
#define NEWLINE '\n'
#define TAB     '\t'
#define BLANK   ' '
#define EOS     '\0'

/*      Opcode Classes          */
#define INH     0       /* Inherent                     */
#define GEN     1       /* General Addressing           */
#define IMM     2       /* Immediate only               */
#define REL     3       /* Short Relative               */
#define P2REL   4       /* Long Relative                */
#define P1REL   5       /* Long Relative (LBRA and LBSR)*/
#define NOIMM   6       /* General except for Immediate */
#define P2GEN   7       /* Page 2 General               */
#define P3GEN   8       /* Page 3 General               */
#define RTOR    9       /* Register To Register         */
#define INDEXED 10      /* Indexed only                 */
#define RLIST   11      /* Register List                */
#define P2NOIMM 12      /* Page 2 No Immediate          */
#define P2INH   13      /* Page 2 Inherent              */
#define P3INH   14      /* Page 3 Inherent              */
#define GRP2    15      /* Group 2 (Read/Modify/Write)  */
#define LONGIMM 16      /* Immediate mode takes 2 bytes */
#define BTB     17      /* Bit test and branch          */
#define SETCLR  18      /* Bit set or clear             */
#define CPD     19      /* compare d               6811 */
#define XLIMM   20      /* LONGIMM for X           6811 */
#define XNOIMM  21      /* NOIMM for X             6811 */
#define YLIMM   22      /* LONGIMM for Y           6811 */
#define YNOIMM  23      /* NOIMM for Y             6811 */
#define FAKE    24      /* convenience mnemonics   6804 */
#define APOST   25      /* A accum after opcode    6804 */
#define BPM     26      /* branch reg plus/minus   6804 */
#define CLRX    27      /* mvi x,0                 6804 */
#define CLRY    28      /* mvi y,0                 6804 */
#define LDX     29      /* mvi x,expr              6804 */
#define LDY     30      /* mvi y,expr              6804 */
#define MVI     31      /* mvi                     6804 */
#define EXT     32      /* extended                6804 */
#define BIT     33      /* bit manipulation        6301 */
#define SYS     34      /* syscalls (really swi)        */
#define PSEUDO  35      /* Pseudo ops                   */

/* global variables */
extern int     Line_num ;            /* current line number          */
extern int     Err_count ;           /* total number of errors       */
extern char    Line[MAXBUF] ;     /* input line buffer            */
extern char    Label[MAXLAB];    /* label on current line        */
extern char    Op[MAXOP];        /* opcode mnemonic on current line      */
extern char    Operand[MAXBUF];  /* remainder of line after op           */
extern char    *Optr;               /* pointer into current Operand field   */
extern int     Result;              /* result of expression evaluation      */
extern int     Force_word;          /* Result should be a word when set     */
extern int     Force_byte;          /* Result should be a byte when set     */
extern int     Pc;                  /* Program Counter              */
extern int     Old_pc;              /* Program Counter at beginning */

extern int     Last_sym;            /* result of last lookup        */

extern int     Pass;                /* Current pass #               */
extern int     N_files;             /* Number of files to assemble  */
extern FILE    *Fd;                 /* Current input file structure */
extern int     Cfn;                 /* Current file number 1...n    */
extern int     Ffn;                 /* forward ref file #           */
extern int     F_ref;               /* next line with forward ref   */
extern char    **Argv;              /* poextern inter to file names        */

extern int     E_total;             /* total # bytes for one line   */
extern int     E_bytes[E_LIMIT]; /* Emitted held bytes           */
extern int     E_pc;                /* Pc at beginning of collection*/

extern int     Lflag ;              /* listing flag 0=nolist,   1=list   */
extern int     Bflag ;              /* binary  flag 0=nobinary, 1=binary */
extern int     Oflag ;              /* s19     flag 0=noS19,    1=S19    */
extern int     Cflag ;              /* cycles  flag 0=nocycles, 1=cycles */
extern int     Sflag ;              /* symbol  flag 0=nosymbol, 1=symbol */
extern int     Rflag ;              /* crf     flag 0=nocrf,    1=crf    */
/* Warn about comment not starting with comment sign ';' '*'         */
extern int     Wflag ;              /* warning flag 0=none,     1=warning*/

extern int     P_force ;            /* force listing line to include Old_pc */
extern int     P_total ;             /* current number of bytes collected    */
extern int     P_bytes[P_LIMIT]; /* Bytes collected for listing  */

extern int     Cycles ;             /* # of cycles per instruction  */
extern long    Ctotal ;             /* # of cycles seen so far */
extern int     N_page ;             /* new page flag */
extern int     Page_num ;           /* page number */

struct link { /* linked list to hold line numbers */
    int L_num; /* line number */
    struct link *next; /* pointer to next node */
};

struct nlist { /* basic symbol table entry */
    char    *name;
    int     def;
    struct nlist *Lnext ; /* left node of the tree leaf */
    struct nlist *Rnext; /* right node of the tree leaf */
    struct link *L_list; /* pointer to linked list of line numbers */
};

struct oper {   /* an entry in the mnemonic table */
    char    *mnemonic;      /* its name */
    char    class;          /* its class */
    int     opcode;         /* its base opcode */
    char    cycles;         /* its base # of cycles */
};

extern struct  nlist *root;            /* root node of the tree */

extern FILE    *Objfil ;             /* S19    file's file descriptor*/
extern FILE    *Binfil ;             /* Binary file's file descriptor*/
extern FILE    *Lstfil ;             /* List   file's file descriptor*/
extern FILE    *Symfil ;             /* Symbol file's file descriptor*/
extern FILE    *Crffil ;             /* Crf    file's file descriptor*/

extern char    Obj_name[MAXPATH];
extern char    Bin_name[MAXPATH];
extern char    Lst_name[MAXPATH];
extern char    Sym_name[MAXPATH];
extern char    Crf_name[MAXPATH];
#endif
