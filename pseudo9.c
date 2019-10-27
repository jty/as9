/*
 *      pseudo --- pseudo op processing
 */
#include "asdef.h"
#include "pseudo.h"

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
