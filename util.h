#ifndef UTIL_H
# define UTIL_H
void fatal(char    *str);
void error(char    *str);
void errors(char *msg, char *str);
void warn(char    *str);
int delim(char    c);
char *skip_white(char    *ptr);
void eword(int     wd);
void emit(int byte);
void f_record(void);
void hexout(int     byte);
void binout(int     byte);
void print_line(void);
int any(char    c,	char    *str);
char mapdn(char c);
int lobyte(int i);
int hibyte(int i);
int head( char *str1, char *str2);
int alpha(char c);
int alphan(char c);
int white(char c);
void *alloc(int nbytes);

#endif
