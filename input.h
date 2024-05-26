#include <stdio.h>
#include <stdbool.h>
#include <stdarg.h>

//macro funzione file

#define f_in(f) in(f, NULL)

//macro funzione stringa

#define s_in(s, ...) in(NULL, s, ##__VA_ARGS__)

//tipo stringa

typedef char *str;

//lunghezza stringa

static long long length = 0;

//posizione carattere

static unsigned long long position = 0;

//prototipi delle funzioni

static str input(FILE *, str, va_list);
extern bool v_str(const str, str);
extern str ln(const str);
extern unsigned long long len(const str);
extern void c_str(str, const int, const char);
extern str in(FILE *, str, ...);
extern char c(const str);
extern int i(const str);
extern long l(const str);
extern long long ll(const str);
extern float f(const str);
extern double d(const str);