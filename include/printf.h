#ifndef PRINTF_H
#define PRINTF_H

#include "types.h"
#include "libc.h"

typedef char *va_list;

/* Output callback of _Printf: receives the argument given to _Printf, a piece of text and its length, and returns the
   argument for the next call, or NULL to stop. */
typedef void *(*PrintfCallback)(void *arg, const char *s, u32 n);

/* State of one conversion. The text of a conversion is made of the pieces n0 (prefix, kept in a small buffer), n1,
   n2 (digits, exponent) and the zero padding nz0, nz1, nz2 between them. */
typedef struct {
    /* 0x00 */ s64 ll;
    /* 0x08 */ char *s;
    /* 0x0C */ s32 n0;
    /* 0x10 */ s32 nz0;
    /* 0x14 */ s32 n1;
    /* 0x18 */ s32 nz1;
    /* 0x1C */ s32 n2;
    /* 0x20 */ s32 nz2;
    /* 0x24 */ s32 prec;
    /* 0x28 */ s32 width;
    /* 0x2C */ u32 nchar;
    /* 0x30 */ u32 flags;
    /* 0x34 */ u8 qual;
} Pft;

/* Pft.flags, in the order of the flag characters " +-#0". */
#define FLAGS_SPACE 0x01
#define FLAGS_PLUS 0x02
#define FLAGS_MINUS 0x04
#define FLAGS_HASH 0x08
#define FLAGS_ZERO 0x10

extern char D_80098110[];  /* 32 spaces, padding text */
extern char D_80098134[];  /* 32 zeros, padding text */
extern char D_80098370[];  /* lower-case digits "0123456789abcdef" */
extern char D_80098384[];  /* upper-case digits "0123456789ABCDEF" */
extern char D_800996D0[];  /* length modifiers "hlL" */
extern char D_800996D4[];  /* flag characters " +-#0" */
extern s32 D_800996DC[];   /* FLAGS_* value of each flag character */
extern char D_80099880[];  /* "0", digits of a zero value */

s32 _Printf(PrintfCallback pfn, void *arg, const char *fmt, va_list ap);
void _Putfld(Pft *px, va_list *pap, char code, char *ac);
void _Litob(Pft *px, char code);
void _Ldtob(Pft *px, char code);
s16 _Ldunscale(s16 *pex, Pft *px);
void _Genld(Pft *px, char code, char *p, s16 nsig, s16 xexp);

/* Callback that copies the text to the buffer given as argument and returns the end of the copy. */
void *func_800879D0(void *dst, const void *src, u32 n);

s32 sprintf(char *buf, const char *fmt, ...);
s32 vaprintf(PrintfCallback *pfn, const char *fmt, va_list ap);
s32 aprintf(PrintfCallback *pfn, const char *fmt, ...);

#endif
