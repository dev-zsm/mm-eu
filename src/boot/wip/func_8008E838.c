// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct PrintSpec {
    /* 0x00 */ union {
        s64 num;
        struct { s32 hi; s32 lo; } w;
    } n;
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

extern void _Litob(PrintSpec* s, u8 c);
extern void _Ldtob(PrintSpec* s, u8 c);
extern s32 strlen(char* s);

#define VA32(ap) (*(s32*)((*(ap) = (char*)((((u32)*(ap)) + 3 & ~3) + 4)) - 4))
#define VA64(ap) (*(s64*)((*(ap) = (char*)((((u32)*(ap)) + 7 & ~7) + 8)) - 8))

void _Putfld(PrintSpec* s, char** ap, u8 c, char* buf) {
    s32 v;
    char* p;

    s->count = 0;
    s->unk10 = 0;
    s->len = 0;
    s->unk18 = 0;
    s->unk1C = 0;
    s->unk20 = 0;

    switch (c & 0xFF) {
    case 'c':
        buf[s->count++] = VA32(ap);
        break;
    case 'd':
    case 'i':
        if (s->lenmod == 'l') {
            s->n.num = VA32(ap);
        } else if (s->lenmod == 'L') {
            s->n.num = VA64(ap);
        } else {
            s->n.num = VA32(ap);
        }
        if (s->lenmod == 'h') {
            s->n.num = (s16)s->n.num;
        }
        if (s->n.num < 0) {
            buf[s->count++] = '-';
        } else if (s->flags & 2) {
            buf[s->count++] = '+';
        } else if (s->flags & 1) {
            buf[s->count++] = ' ';
        }
    out:
        s->ptr = buf + s->count;
        _Litob(s, c);
        break;
    case 'o':
    case 'u':
    case 'x':
    case 'X':
        if (s->lenmod == 'l') {
            s->n.num = VA32(ap);
        } else if (s->lenmod == 'L') {
            s->n.num = VA64(ap);
        } else {
            s->n.num = VA32(ap);
        }
        if (s->lenmod == 'h') {
            s->n.num = (u16)s->n.num;
        } else if (s->lenmod == 0) {
            s->n.num = (u32)s->n.num;
        }
        if (s->flags & 8) {
            buf[s->count++] = '0';
            if (c == 'x' || c == 'X') {
                buf[s->count++] = c;
            }
        }
        s->ptr = buf + s->count;
        _Litob(s, c);
        break;
    case 'E':
    case 'G':
    case 'e':
    case 'f':
    case 'g':
        if (s->lenmod == 'L') {
            v = (s32)*ap;
            if (v & 1) {
                *ap = (char*)(v + 7);
                *(f64*)s = *(f64*)(v - 23);
            } else if (v & 2) {
                *ap = (char*)(v + 10);
                *(f64*)s = *(f64*)(v - 38);
            } else {
                *ap = (char*)(((v + 7) & ~7) + 8);
                *(f64*)s = *(f64*)(((v + 7) & ~7));
            }
        } else {
            v = (s32)*ap;
            if (v & 1) {
                *ap = (char*)(v + 7);
                *(f64*)s = *(f64*)(v - 23);
            } else if (v & 2) {
                *ap = (char*)(v + 10);
                *(f64*)s = *(f64*)(v - 38);
            } else {
                *ap = (char*)(((v + 7) & ~7) + 8);
                *(f64*)s = *(f64*)(((v + 7) & ~7));
            }
        }
        if (*(u16*)s & 0x8000) {
            buf[s->count++] = '-';
        } else if (s->flags & 2) {
            buf[s->count++] = '+';
        } else if (s->flags & 1) {
            buf[s->count++] = ' ';
        }
        s->ptr = buf + s->count;
        _Ldtob(s, c);
        break;
    case 'n':
        if (s->lenmod == 'h') {
            *(u16*)VA32(ap) = s->total;
        } else if (s->lenmod == 'l') {
            *(s32*)VA32(ap) = s->total;
        } else if (s->lenmod == 'L') {
            {
                s32* a = (s32*)VA32(ap);
                a[0] = 0;
                a[1] = s->total;
            }
        } else {
            *(s32*)VA32(ap) = s->total;
        }
        break;
    case 'p':
        s->n.num = VA32(ap);
        s->ptr = buf + s->count;
        _Litob(s, 'x');
        break;
    case 's':
        s->ptr = (char*)VA32(ap);
        s->len = strlen(s->ptr);
        if (s->prec >= 0) {
            if (s->prec < s->len) {
                s->len = s->prec;
            }
        }
        break;
    case '%':
        buf[s->count++] = '%';
        break;
    default:
        buf[s->count++] = c;
        break;
    }
}
