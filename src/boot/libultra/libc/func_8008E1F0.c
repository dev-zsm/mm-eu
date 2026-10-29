// FLAGS: -O2 -g0 -mips2
// COMPILER: ido53
#include "types.h"

typedef struct {
    s64 ll;
    char *s;
    s32 n0;
    s32 nz0;
    s32 n1;
    s32 nz1;
    s32 n2;
    s32 nz2;
    s32 prec;
    s32 width;
    u32 nchar;
    u32 flags;
    u8 qual;
} Pft;

typedef char *va_list;
typedef void *(*PrintfCb)(void *, const char *, u32);

extern char D_80098110[];
extern char D_80098134[];
extern char D_800996D0[];
extern char D_800996D4[];
extern s32 D_800996DC[];

extern char *strchr();
extern void _Putfld();

// matching: PUT/PAD/ATOI/VAI are macros in the original sources; MAX_PAD is unsigned in the clamp
#define MAX_PAD 32
#define PUT(s, n)                                   \
    if ((n) > 0) {                                  \
        arg = pfn(arg, (s), (n));               \
        if (arg != 0) {                               \
            x.nchar += (n);                         \
        } else {                                    \
            return x.nchar;                         \
        }                                           \
    }
#define PAD(s, n)                                          \
    if ((n) > 0) {                                         \
        s32 i, j = (n);                                    \
        while (j > 0) {                                    \
            i = (j > (u32)MAX_PAD) ? MAX_PAD : j;               \
            PUT(s, i);                                     \
            j -= i;                                        \
        }                                                  \
    }
#define VAI(ap) (*(s32 *)((((ap) = (char *)((((s32)(ap) + 3) & ~3) + 4)) - 4)))
#define ISDIGIT(c) ((c) >= '0' && (c) <= '9')
#define ATOI(i, s)                          \
    for (; ISDIGIT(*s); ++s) {              \
        if ((i) < 999) {                    \
            (i) = (i) * 10 + *s - '0';      \
        }                                   \
    }

s32 _Printf(PrintfCb pfn, void *arg, const char *fmt, va_list ap) {

    Pft x;

    x.nchar = 0;
    for (;;) {
        const char *s;
        char c;
        const char *t;
        char ac[0x20];

        s = fmt;
        while ((c = *s) != 0 && c != '%') {
            s++;
        }
        PUT(fmt, s - fmt);
        if (c == 0) {
            return x.nchar;
        }
        s++;
        x.flags = 0;
        for (; (t = strchr(D_800996D4, *s)) != 0; s++) {
            x.flags |= D_800996DC[t - D_800996D4];
        }
        if (*s == '*') {
            x.width = VAI(ap);
            s++;
            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= 4;
            }
        } else {
            x.width = 0;
            ATOI(x.width, s);
        }
        if (*s != '.') {
            x.prec = -1;
        } else {
            s++;
            if (*s == '*') {
                x.prec = VAI(ap);
                s++;
            } else {
                x.prec = 0;
                ATOI(x.prec, s);
            }
        }
        x.qual = strchr(D_800996D0, *s) ? *s++ : 0;
        if (x.qual == 'l' && *s == 'l') {
            x.qual = 'L';
            s++;
        }
        _Putfld(&x, &ap, *s, ac);
        x.width -= x.n0 + x.nz0 + x.n1 + x.nz1 + x.n2 + x.nz2;
        if (!(x.flags & 4)) {
            PAD(D_80098110, x.width);
        }
        PUT(ac, x.n0);
        PAD(D_80098134, x.nz0);
        PUT(x.s, x.n1);
        PAD(D_80098134, x.nz1);
        PUT(x.s + x.n1, x.n2);
        PAD(D_80098134, x.nz2);
        if (x.flags & 4) {
            PAD(D_80098110, x.width);
        }
        fmt = s + 1;
    }
}
