#ifndef SYMTAB_H
# define SYMTAB_H
int install(char    *str, int     val);
int update(char    *str, int     val);
struct nlist *lookup(char    *name);
struct oper *mne_look(char    *str);
#endif
