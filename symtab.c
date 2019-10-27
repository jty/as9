#include "symtab.h"
#include <string.h>
#include "asdef.h"
#include "pseudo.h"
#include "util.h"

/*
 *
 *      install --- add a symbol to the table
 */

struct oper table[] = {
/*
  MNE     CLASS   BASE    CYCLES */
{"abx",  INH,    58,    3},
{"adca", GEN,    137,	2},
{"adcb", GEN,    201,	2},
{"adda", GEN,    139,   2},
{"addb", GEN,    203,	2},
{"addd", LONGIMM,195,   4},
{"anda", GEN,    132,	2},
{"andb", GEN,    196,	2},
{"andcc",IMM,    28,    3},
{"asl",  GRP2,   8,	    4},
{"asla", INH,    72,	2},
{"aslb", INH,    88,	2},
{"asr",  GRP2,   7,	    4},
{"asra", INH,    71,	2},
{"asrb", INH,    87,	2},
{"bcc",  REL,    36,	3},
{"bcs",  REL,    37,	3},
{"beq",  REL,    39,	3},
{"bge",  REL,    44,	3},
{"bgt",  REL,    46,	3},
{"bhi",  REL,    34,	3},
{"bhs",  REL,    36,	3},
{"bita", GEN,    133,	2},
{"bitb", GEN,    197,	2},
{"ble",  REL,    47,	3},
{"blo",  REL,    37,	3},
{"bls",  REL,    35,	3},
{"blt",  REL,    45,	3},
{"bmi",  REL,    43,	3},
{"bne",  REL,    38,	3},
{"bpl",  REL,    42,	3},
{"bra",  REL,    32,	3},
{"brn",  REL,    33,	3},
{"bsr",  REL,    141,   7},
{"bvc",  REL,    40,    3},
{"bvs",  REL,    41,	3},
{"clr",  GRP2,   15,	4},
{"clra", INH,    79,	2},
{"clrb", INH,    95,	2},
{"cmpa", GEN,    129,	2},
{"cmpb", GEN,    193,	2},
{"cmpd", P2GEN,  131,   5},
{"cmps", P3GEN,  140,   5},
{"cmpu", P3GEN,  131,   5},
{"cmpx", LONGIMM,140,   4},
{"cmpy", P2GEN,  140,   5},
{"com",  GRP2,   3,     4},
{"coma", INH,    67,	2},
{"comb", INH,    83,	2},
{"cpx",  LONGIMM,140,   4},      /* for compatibility with old code */
{"cwai", IMM,    60,   20},
{"daa",  INH,    25,	2},
{"dec",  GRP2,   10,	4},
{"deca", INH,    74,	2},
{"decb", INH,    90,	2},
{"eora", GEN,    136,	2},
{"eorb", GEN,    200,	2},
{"exg",  RTOR,   30,    8},
{"inc",  GRP2,   12,	4},
{"inca", INH,    76,	2},
{"incb", INH,    92,	2},
{"jmp",  GRP2,   14,    1},
{"jsr",  NOIMM,  141,   5},
{"lbcc", P2REL,  36,	6},
{"lbcs", P2REL,  37,	6},
{"lbeq", P2REL,  39,	6},
{"lbge", P2REL,  44,	6},
{"lbgt", P2REL,  46,	6},
{"lbhi", P2REL,  34,	6},
{"lbhs", P2REL,  36,	6},
{"lble", P2REL,  47,	6},
{"lblo", P2REL,  37,	6},
{"lbls", P2REL,  35,	6},
{"lblt", P2REL,  45,	6},
{"lbmi", P2REL,  43,	6},
{"lbne", P2REL,  38,	6},
{"lbpl", P2REL,  42,	6},
{"lbra", P1REL,  22,    5},
{"lbrn", P2REL,  33,    5},
{"lbsr", P1REL,  23,    9},
{"lbvc", P2REL,  40,	6},
{"lbvs", P2REL,  41,	6},
{"lda",  GEN,    134,	2},
{"ldb",  GEN,    198,	2},
{"ldd",  LONGIMM,204,   3},
{"lds",  P2GEN,  206,   4},
{"ldu",  LONGIMM,206,   3},
{"ldx",  LONGIMM,142,   3},
{"ldy",  P2GEN,  142,   4},
{"leas", INDEXED,50,    2},
{"leau", INDEXED,51,    2},
{"leax", INDEXED,48,    2},
{"leay", INDEXED,49,    2},
{"lsl",  GRP2,   8,	    4},
{"lsla", INH,    72,	2},
{"lslb", INH,    88,	2},
{"lsr",  GRP2,   4,	    4},
{"lsra", INH,    68,	2},
{"lsrb", INH,    84,	2},
{"mul",  INH,    61,   11},
{"neg",  GRP2,   0,	    4},
{"nega", INH,    64,	2},
{"negb", INH,    80,	2},
{"nop",  INH,    18,	2},
{"ora",  GEN,    138,	2},
{"orb",  GEN,    202,	2},
{"orcc", IMM,    26,    3},
{"pshs", RLIST,  52,    5},
{"pshu", RLIST,  54,    5},
{"puls", RLIST,  53,    5},
{"pulu", RLIST,  55,    5},
{"rol",  GRP2,   9,	    4},
{"rola", INH,    73,	2},
{"rolb", INH,    89,	2},
{"ror",  GRP2,   6,     4},
{"rora", INH,    70,	2},
{"rorb", INH,    86,	2},
{"rti",  INH,    59,   15},
{"rts",  INH,    57,    5},
{"sbca", GEN,    130,	2},
{"sbcb", GEN,    194,	2},
{"sex",  INH,    29,	2},
{"sta",  NOIMM,  135,   2},
{"stb",  NOIMM,  199,   2},
{"std",  NOIMM,  205,   3},
{"sts",  P2NOIMM,207,   4},
{"stu",  NOIMM,  207,   3},
{"stx",  NOIMM,  143,   3},
{"sty",  P2NOIMM,143,   4},
{"suba", GEN,    128,	2},
{"subb", GEN,    192,	2},
{"subd", LONGIMM,131,   4},
{"swi",  INH,    63,   19},
{"swi2", P2INH,  63,   20},
{"swi3", P3INH,  63,   20},
{"sync", INH,    19,    4},
{"sys",  SYS,    0,    19},
{"tfr",  RTOR,   31,    6},
{"tst",  GRP2,   13,	4},
{"tsta", INH,    77,	2},
{"tstb", INH,    93,    2}
};

struct oper pseudo[] = {
{"bsz",  PSEUDO, ZMB,    0},
{"end",  PSEUDO, NULL_OP,0},
{"equ",  PSEUDO, EQU,    0},
{"fcb",  PSEUDO, FCB,    0},
{"fcc",  PSEUDO, FCC,    0},
{"fdb",  PSEUDO, FDB,    0},
{"fill", PSEUDO, FILL,   0},
{"nam",  PSEUDO, NULL_OP,0},
{"name", PSEUDO, NULL_OP,0},
{"opt",  PSEUDO, OPT,    0},
{"org",  PSEUDO, ORG,    0},
{"pag",  PSEUDO, PAGE,   0},
{"page", PSEUDO, PAGE,   0},
{"rmb",  PSEUDO, RMB,    0},
{"set",  PSEUDO, SET,    0},
{"spc",  PSEUDO, NULL_OP,0},
{"ttl",  PSEUDO, NULL_OP,0},
{"zmb",  PSEUDO, ZMB,    0}
};


int install_or_update(
        char    *str,
        int     val,
        int is_update
        )
{
    struct link *lp;
    struct nlist *np,*p,*backp;
    int     i;

    if( !alpha(*str) ){
        error("Illegal Symbol Name");
        return(NO);
    }
    if( (np = lookup(str)) != NULL ){
        if (is_update) {
            np->def = val;
#ifdef DEBUG
            fprintf(stderr,"Updating %s as %d\n", str, val);
#endif
            return(YES);
        } else {
            if( Pass==2 ){
                if( np->def == val )
                    return(YES);
                else{
                    error("Phasing Error");
                    return(NO);
                }
            }
            error("Symbol Redefined");
            return(NO);
        }
    }
    /* enter new symbol */
#ifdef DEBUG
    fprintf(stderr,"Installing %s as %d\n",str,val);
#endif
    np = (struct nlist *) alloc(sizeof(struct nlist));
    if( np == (struct nlist *)ERR ){
        error("Symbol table full");
        return(NO);
    }
    np->name = alloc(strlen(str)+1);
    if( np->name == (char *)ERR ){
        error("Symbol table full");
        return(NO);
    }
    strcpy(np->name,str);
    np->def = val;
    np->Lnext = NULL;
    np->Rnext = NULL;
    lp = (struct link *) alloc(sizeof(struct link));
    np->L_list = lp;
    lp->L_num = Line_num;
    lp->next = NULL;
    p = root;
    backp = NULL;
    while (p != NULL)
    {
        backp = p;
        i = strcmp (str,p->name);
        if (i<0)
            p=p->Lnext;
        else p=p->Rnext;
    }
    if (backp == NULL)
        root = np;
    else if (strcmp(str,backp->name)<0)
        backp->Lnext = np;
    else backp->Rnext = np;
    return (YES);
}

/*
 *      lookup --- find string in symbol table
 */
struct nlist *
        lookup(
        char    *name)
{
    struct nlist *np;
    int     i;

    np = root;
    while (np != NULL)
    {
        i = strcmp(name,np->name);
        if (i == 0)
        {
            Last_sym = np->def;
            return (np);
        }
        else if (i < 0)
            np = np->Lnext;
        else np = np->Rnext;
    }
    Last_sym = 0;
    if (Pass == 2)
        errors( "symbol Undefined on pass 2", name );
    return (NULL);
}


#define NMNE (sizeof(table)/ sizeof(struct oper))
#define NPSE (sizeof(pseudo)/ sizeof(struct oper))
/*
 *      mne_look --- mnemonic lookup
 *
 *      Return pointer to an oper structure if found.
 *      Searches both the machine mnemonic table and the pseudo table.
 */
struct oper *
        mne_look(
        char    *str)
{
    struct oper *low,*high,*mid;
    int     cond;

    /* Search machine mnemonics first */
    low =  &table[0];
    high = &table[ NMNE-1 ];
    while (low <= high){
        mid = low + (high-low)/2;
        if( ( cond = strcmp(str,mid->mnemonic)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return(mid);
    }

    /* Check for pseudo ops */
    low =  &pseudo[0];
    high = &pseudo[ NPSE-1 ];
    while (low <= high){
        mid = low + (high-low)/2;
        if( ( cond = strcmp(str,mid->mnemonic)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return(mid);
    }

    return(NULL);
}

int install(char *str, int val) {
    return install_or_update(str, val, 0);
}

int update(char *str, int val) {
    return install_or_update(str, val, 1);
}
