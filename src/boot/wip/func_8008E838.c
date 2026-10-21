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

extern void func_80095120(PrintSpec* s, u8 c);
extern void func_80094480(PrintSpec* s, u8 c);
extern s32 func_8008F380(char* s);

void func_8008E838(PrintSpec* s, char** ap, u8 c, char* buf) {
    s32 v;
    s32* a;
    f64 f;

    s->count = 0;
    s->unk10 = 0;
    s->len = 0;
    s->unk18 = 0;
    s->unk1C = 0;
    s->unk20 = 0;

    if (c < 0x26) {
        buf[s->count] = c;
        s->count++;
        return;
    }

    switch (c) {
    case 'c':
        a = (s32*)(((u32)*ap + 3) & ~3);
        *ap = (char*)(a + 1);
        buf[s->count] = *a;
        s->count++;
        return;
    case 'd':
    case 'i':
        if (s->lenmod == 'l') {
            a = (s32*)(((u32)*ap + 3) & ~3);
            *ap = (char*)(a + 1);
            s->hi = *a >> 31;
            s->lo = *a;
        } else if (s->lenmod == 'L') {
            a = (s32*)(((u32)*ap + 7) & ~7);
            *ap = (char*)(a + 2);
            s->lo = a[1];
            s->hi = a[0];
        } else {
            a = (s32*)(((u32)*ap + 3) & ~3);
            *ap = (char*)(a + 1);
            s->hi = *a >> 31;
            s->lo = *a;
        }
        if (s->lenmod == 'h') {
            s->lo = (s16)s->lo;
            s->hi = s->lo >> 31;
        }
        if (s->hi > 0) {
            goto flags;
        }
        if (s->hi < 0) {
            buf[s->count] = '-';
            s->count++;
            goto out;
        }
    flags:
        if (s->flags & 2) {
            buf[s->count] = '+';
            s->count++;
        } else if (s->flags & 1) {
            buf[s->count] = ' ';
            s->count++;
        }
    out:
        s->ptr = buf + s->count;
        func_80095120(s, c);
        return;
    case 'o':
    case 'u':
    case 'x':
    case 'X':
        if (s->lenmod == 'l') {
            a = (s32*)(((u32)*ap + 3) & ~3);
            *ap = (char*)(a + 1);
            s->hi = *a >> 31;
            s->lo = *a;
        } else if (s->lenmod == 'L') {
            a = (s32*)(((u32)*ap + 7) & ~7);
            *ap = (char*)(a + 2);
            s->lo = a[1];
            s->hi = a[0];
        } else {
            a = (s32*)(((u32)*ap + 3) & ~3);
            *ap = (char*)(a + 1);
            s->hi = *a >> 31;
            s->lo = *a;
        }
        if (s->lenmod == 'h') {
            s->lo &= 0xFFFF;
            s->hi = 0;
        } else if (s->lenmod == 0) {
            s->hi = 0;
        }
        if (s->flags & 8) {
            buf[s->count] = '0';
            s->count++;
            if (c == 'x') {
                buf[s->count] = c;
                s->count++;
            } else if (c == 'X') {
                buf[s->count] = c;
                s->count++;
            }
        }
        s->ptr = buf + s->count;
        func_80095120(s, c);
        return;
    case 'E':
    case 'G':
    case 'e':
    case 'f':
    case 'g':
        if (s->lenmod == 'L') {
            v = (s32)*ap;
            if (v & 1) {
                *ap = (char*)(v + 7);
                f = *(f64*)(v - 23);
            } else if (v & 2) {
                *ap = (char*)(v + 10);
                f = *(f64*)(v - 38);
            } else {
                *ap = (char*)(((v + 7) & ~7) + 8);
                f = *(f64*)(((v + 7) & ~7));
            }
        } else {
            v = (s32)*ap;
            if (v & 1) {
                *ap = (char*)(v + 7);
                f = *(f64*)(v - 23);
            } else if (v & 2) {
                *ap = (char*)(v + 10);
                f = *(f64*)(v - 38);
            } else {
                *ap = (char*)(((v + 7) & ~7) + 8);
                f = *(f64*)(((v + 7) & ~7));
            }
        }
        *(f64*)s = f;
        if (*(u16*)s & 0x8000) {
            buf[s->count] = '-';
            s->count++;
        } else if (s->flags & 2) {
            buf[s->count] = '+';
            s->count++;
        } else if (s->flags & 1) {
            buf[s->count] = ' ';
            s->count++;
        }
        s->ptr = buf + s->count;
        func_80094480(s, c);
        return;
    case 'n':
        if (s->lenmod == 'h') {
            a = (s32*)(((u32)*ap + 3) & ~3);
            *ap = (char*)(a + 1);
            *(u16*)*a = s->total;
        } else if (s->lenmod == 'l') {
            a = (s32*)(((u32)*ap + 3) & ~3);
            *ap = (char*)(a + 1);
            *(s32*)*a = s->total;
        } else if (s->lenmod == 'L') {
            a = (s32*)(((u32)*ap + 3) & ~3);
            *ap = (char*)(a + 1);
            ((s32*)*a)[0] = 0;
            ((s32*)*a)[1] = s->total;
        } else {
            a = (s32*)(((u32)*ap + 3) & ~3);
            *ap = (char*)(a + 1);
            *(s32*)*a = s->total;
        }
        return;
    case 'p':
        a = (s32*)(((u32)*ap + 3) & ~3);
        *ap = (char*)(a + 1);
        s->hi = *a >> 31;
        s->ptr = buf + s->count;
        s->lo = *a;
        func_80095120(s, 'x');
        return;
    case 's':
        a = (s32*)(((u32)*ap + 3) & ~3);
        *ap = (char*)(a + 1);
        s->ptr = (char*)*a;
        s->len = func_8008F380(s->ptr);
        if (s->prec >= 0) {
            if (s->prec < s->len) {
                s->len = s->prec;
            }
        }
        return;
    default:
        break;
    }

    buf[s->count] = c;
    s->count++;
}
