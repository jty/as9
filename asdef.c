#include "asdef.h"

/* global variables */
int     Line_num =0;            /* current line number          */
int     Err_count =0;           /* total number of errors       */
char    Line[MAXBUF] = {0};     /* input line buffer            */
char    Label[MAXLAB] = {0};    /* label on current line        */
char    Op[MAXOP] = {0};        /* opcode mnemonic on current line      */
char    Operand[MAXBUF] = {0};  /* remainder of line after op           */
char    *Optr =0;               /* pointer into current Operand field   */
int     Result =0;              /* result of expression evaluation      */
int     Force_word =0;          /* Result should be a word when set     */
int     Force_byte =0;          /* Result should be a byte when set     */
int     Pc =0;                  /* Program Counter              */
int     Old_pc =0;              /* Program Counter at beginning */

int     Last_sym =0;            /* result of last lookup        */

int     Pass =0;                /* Current pass #               */
int     N_files =0;             /* Number of files to assemble  */
FILE    *Fd =0;                 /* Current input file structure */
int     Cfn =0;                 /* Current file number 1...n    */
int     Ffn =0;                 /* forward ref file #           */
int     F_ref =0;               /* next line with forward ref   */
char    **Argv =0;              /* pointer to file names        */

int     E_total =0;             /* total # bytes for one line   */
int     E_bytes[E_LIMIT] = {0}; /* Emitted held bytes           */
int     E_pc =0;                /* Pc at beginning of collection*/

int     Lflag = 0;              /* listing flag 0=nolist,   1=list   */
int     Bflag = 0;              /* binary  flag 0=nobinary, 1=binary */
int     Oflag = 0;              /* s19     flag 0=noS19,    1=S19    */
int     Cflag = 0;              /* cycles  flag 0=nocycles, 1=cycles */
int     Sflag = 0;              /* symbol  flag 0=nosymbol, 1=symbol */
int     Rflag = 0;              /* crf     flag 0=nocrf,    1=crf    */
/* Warn about comment not starting with comment sign ';' '*'         */
int     Wflag = 1;              /* warning flag 0=none,     1=warning*/

int     P_force = 0;            /* force listing line to include Old_pc */
int     P_total =0;             /* current number of bytes collected    */
int     P_bytes[P_LIMIT] = {0}; /* Bytes collected for listing  */

int     Cycles = 0;             /* # of cycles per instruction  */
long    Ctotal = 0;             /* # of cycles seen so far */
int     N_page = 0;             /* new page flag */
int     Page_num = 2;           /* page number */

struct  nlist *root;            /* root node of the tree */

FILE    *Objfil =0;             /* S19    file's file descriptor*/
FILE    *Binfil =0;             /* Binary file's file descriptor*/
FILE    *Lstfil =0;             /* List   file's file descriptor*/
FILE    *Symfil =0;             /* Symbol file's file descriptor*/
FILE    *Crffil =0;             /* Crf    file's file descriptor*/

char    Obj_name[MAXPATH] = "             ";
char    Bin_name[MAXPATH] = "             ";
char    Lst_name[MAXPATH] = "             ";
char    Sym_name[MAXPATH] = "             ";
char    Crf_name[MAXPATH] = "             ";
