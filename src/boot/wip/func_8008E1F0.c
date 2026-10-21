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

s32 func_8008E1F0(PrintFn prout, void* arg, const char* fmt, char* ap) {
    struct { char pad[0x10]; char buf[0x2C]; PrintSpec spec; } loc;
    char* s2;
    s32 c;
    s32 n;
    char* p;
    s32 s1;
    s32 s0;
    s32 w;

    loc.spec.total = 0;
    for (;;) {
        s2 = fmt;
        c = *s2;
        if (c != 0 && '%' != c) {
            do {
                s2++;
                c = *s2;
            } while (c != 0 && '%' != c);
        }
        n = s2 - fmt;
        if (n > 0) {
            arg = prout(arg, fmt, n);
            if (arg == NULL) {
                return loc.spec.total;
            }
            loc.spec.total += n;
        }
        s2++;
        if (c == 0) {
            return loc.spec.total;
        }

        loc.spec.flags = 0;
        c = *s2;
        p = func_8008F340(D_800996D4, c);
        while (p != NULL) {
            loc.spec.flags |= D_800996DC[p - D_800996D4];
            s2++;
            p = func_8008F340(D_800996D4, *s2);
        }

        c = *s2;
        if ('*' == c) {
            w = *(s32*)(((u32)ap + 3) & ~3);
            ap = (char*)((((u32)ap + 3) & ~3) + 4);
            s2++;
            loc.spec.width = w;
            if (w < 0) {
                loc.spec.width = -w;
                loc.spec.flags |= 4;
            }
            c = *s2;
        } else {
            loc.spec.width = 0;
            if (c >= '0' && c < ':') {
                do {
                    if (loc.spec.width < 999) {
                        loc.spec.width = c + loc.spec.width * 10 - '0';
                    }
                    s2++;
                    c = *s2;
                } while (c >= '0' && c < ':');
            }
        }

        if ('.' == c) {
            if (s2[1] == '*') {
                s2++;
                w = *(s32*)(((u32)ap + 3) & ~3);
                ap = (char*)((((u32)ap + 3) & ~3) + 4);
                loc.spec.prec = w;
                s2++;
                c = *s2;
            } else {
                s2++;
                loc.spec.prec = 0;
                c = *s2;
                if (c >= '0' && c < ':') {
                    do {
                        if (loc.spec.prec < 999) {
                            loc.spec.prec = c + loc.spec.prec * 10 - '0';
                        }
                        s2++;
                        c = *s2;
                    } while (c >= '0' && c < ':');
                }
            }
        } else {
            loc.spec.prec = -1;
        }

        p = func_8008F340(D_800996D0, c);
        if (p != NULL) {
            loc.spec.lenmod = *s2;
            s2++;
        } else {
            loc.spec.lenmod = 0;
        }
        if (loc.spec.lenmod == 'l' && *s2 == 'l') {
            loc.spec.lenmod = 'L';
            s2++;
        }

        func_8008E838(&loc.spec, &ap, *s2, loc.buf);

        loc.spec.width = loc.spec.width - loc.spec.count - loc.spec.unk10 - loc.spec.len - loc.spec.unk18 - loc.spec.unk1C - loc.spec.unk20;

        if (!(loc.spec.flags & 4)) {
            if (loc.spec.width > 0) {
                s1 = loc.spec.width;
                do {
                    s0 = (s1 < 0x21) ? s1 : 0x20;
                    arg = prout(arg, D_80098110, s0);
                    if (arg == NULL) {
                        return loc.spec.total;
                    }
                    loc.spec.total += s0;
                    s1 -= s0;
                } while (s1 > 0);
            }
        }

        if (loc.spec.count > 0) {
            arg = prout(arg, loc.buf, loc.spec.count);
            if (arg == NULL) {
                return loc.spec.total;
            }
            loc.spec.total += loc.spec.count;
        }

        if (loc.spec.unk10 > 0) {
            s1 = loc.spec.unk10;
            do {
                s0 = (s1 < 0x21) ? s1 : 0x20;
                arg = prout(arg, D_80098134, s0);
                if (arg == NULL) {
                    return loc.spec.total;
                }
                loc.spec.total += s0;
                s1 -= s0;
            } while (s1 > 0);
        }

        if (loc.spec.len > 0) {
            arg = prout(arg, loc.spec.ptr, loc.spec.len);
            if (arg == NULL) {
                return loc.spec.total;
            }
            loc.spec.total += loc.spec.len;
        }

        if (loc.spec.unk18 > 0) {
            s1 = loc.spec.unk18;
            do {
                s0 = (s1 < 0x21) ? s1 : 0x20;
                arg = prout(arg, D_80098134, s0);
                if (arg == NULL) {
                    return loc.spec.total;
                }
                loc.spec.total += s0;
                s1 -= s0;
            } while (s1 > 0);
        }

        if (loc.spec.unk1C > 0) {
            arg = prout(arg, loc.spec.ptr + loc.spec.len, loc.spec.unk1C);
            if (arg == NULL) {
                return loc.spec.total;
            }
            loc.spec.total += loc.spec.unk1C;
        }

        if (loc.spec.unk20 > 0) {
            s1 = loc.spec.unk20;
            do {
                s0 = (s1 < 0x21) ? s1 : 0x20;
                arg = prout(arg, D_80098134, s0);
                if (arg == NULL) {
                    return loc.spec.total;
                }
                loc.spec.total += s0;
                s1 -= s0;
            } while (s1 > 0);
        }

        if (loc.spec.flags & 4) {
            if (loc.spec.width > 0) {
                s1 = loc.spec.width;
                do {
                    s0 = (s1 < 0x21) ? s1 : 0x20;
                    arg = prout(arg, D_80098110, s0);
                    if (arg == NULL) {
                        return loc.spec.total;
                    }
                    loc.spec.total += s0;
                    s1 -= s0;
                } while (s1 > 0);
            }
        }

        fmt = s2 + 1;
    }
}
