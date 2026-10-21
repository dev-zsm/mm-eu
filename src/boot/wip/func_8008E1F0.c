// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct PrintSpec {
    /* 0x00 */ s32 hi;
    /* 0x04 */ s32 lo;
    /* 0x08 */ char* ptr;
    /* 0x0C */ s32 count;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 len;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 prec;
    /* 0x28 */ s32 width;
    /* 0x2C */ s32 total;
    /* 0x30 */ u32 flags;
    /* 0x34 */ u8 lenmod;
} PrintSpec;

typedef void* (*PrintFn)(void* arg, const char* str, s32 len);

extern char D_800996D0[];
extern char D_800996D4[];
extern u32 D_800996DC[];
extern char D_80098110[];
extern char D_80098134[];

extern void func_8008E838(PrintSpec* s, char** ap, s32 c, char* buf);
extern char* func_8008F340(const char* s, s32 c);

#define VA() ((s32*)(ap = (char*)((((u32)ap + 3) & ~3) + 4)))[-1]

#define ATOI(i, a)                                \
    for (i = 0; *a >= '0' && *a < ':'; a++) {     \
        if (i < 999) {                            \
            i = *a + i * 10 - '0';                \
        }                                         \
    }

#define PROUT(src, _size)                         \
    if (_size > 0) {                              \
        arg = prout(arg, src, _size);             \
        if (arg != NULL) {                        \
            x.total += _size;                     \
        } else {                                  \
            return x.total;                       \
        }                                         \
    }

#define PAD(m, src, extracond)                    \
    if (extracond && (m > 0)) {                   \
        for (j = m; j > 0; j -= i) {              \
            if ((u32)j > 32) {                \
                i = 32;                       \
            } else {                          \
                i = j;                        \
            }                                 \
            PROUT(src, i);                        \
        }                                         \
    }

s32 func_8008E1F0(PrintFn prout, void* arg, const char* fmt, char* ap) {
    struct { char pad[0x18]; char buf[0x2C]; PrintSpec x; } l;
    const u8* s;
    const u8* t;
    u8 c;
    s32 i;
    s32 j;
#define x l.x
#define buf l.buf

    x.total = 0;
    while (1) {
        s = (const u8*)fmt;
        while ((c = *s) != 0 && c != '%') {
            s++;
        }
        PROUT(fmt, s - (const u8*)fmt);
        if (c == 0) {
            return x.total;
        }
        fmt = (const char*)++s;
        x.flags = 0;
        for (; (t = (u8*)func_8008F340(D_800996D4, *s)) != NULL; s++) {
            x.flags |= D_800996DC[t - (u8*)D_800996D4];
        }
        if (*s == '*') {
            x.width = VA();
            if (x.width < 0) {
                x.width = -x.width;
                x.flags |= 4;
            }
            s++;
        } else {
            ATOI(x.width, s);
        }
        if (*s != '.') {
            x.prec = -1;
        } else {
            s++;
            if (*s == '*') {
                x.prec = VA();
                s++;
            } else {
                ATOI(x.prec, s);
            }
        }
        if (func_8008F340(D_800996D0, *s) != NULL) {
            x.lenmod = *s++;
        } else {
            x.lenmod = 0;
        }
        if (x.lenmod == 'l' && *s == 'l') {
            x.lenmod = 'L';
            s++;
        }
        func_8008E838(&x, &ap, *s, buf);
        x.width -= x.count + x.unk10 + x.len + x.unk18 + x.unk1C + x.unk20;
        PAD(x.width, D_80098110, !(x.flags & 4));
        PROUT(buf, x.count);
        PAD(x.unk10, D_80098134, 1);
        PROUT(x.ptr, x.len);
        PAD(x.unk18, D_80098134, 1);
        PROUT(x.ptr + x.len, x.unk1C);
        PAD(x.unk20, D_80098134, 1);
        PAD(x.width, D_80098110, x.flags & 4);
        fmt = (const char*)s + 1;
    }
}
