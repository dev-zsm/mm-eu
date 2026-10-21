// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[2];
    u16 f2;
    u8 pad4[0xC];
    void *f10;
    s32 f14;
} Hdr800955C0;

typedef struct {
    u8 pad0[0xC];
    void *pC;
} Arg800955C0;

extern u16 D_8009FC70;
extern u32 D_8009E980;
extern u32 D_8009E988;
extern s32 D_8009E98C;

Hdr800955C0 *func_80095750(void);
s32 func_80088070(void *a, void **b, s32 c);
void func_8008F5CC(void);
void func_80091DB0(void);
void func_80087CB0(void *a, s32 b, s32 c);
u32 func_8008D460(void);

void func_800955C0(Arg800955C0 *arg) {
    void *p;
    Hdr800955C0 *h;
    u32 *s1;
    u32 *s2;
    s32 *s3;
    u32 prev;
    u32 now;
    u32 diff;
    u32 lo;

    p = 0;
    h = func_80095750();
    D_8009FC70 = h->f2;
    if (h->f2 == 0) {
        D_8009FC70 = 1;
    }
    s1 = (u32 *)&D_8009E980;
    s2 = (u32 *)&D_8009E988;
    s3 = (s32 *)&D_8009E98C;

    while (1) {
        while (1) {
            func_80088070(arg->pC, &p, 1);
            if (*(u16 *)p == 0xD) {
                break;
            }
            if (*(u16 *)p == 0xE) {
                func_8008F5CC();
            }
        }
        func_80091DB0();
        D_8009FC70 = D_8009FC70 - 1;
        if (D_8009FC70 == 0) {
            h = func_80095750();
            if (h->f10 != 0) {
                func_80087CB0(h->f10, h->f14, 0);
            }
            D_8009FC70 = h->f2;
        }
        *s3 = *s3 + 1;
        prev = *s2;
        now = func_8008D460();
        diff = now - prev;
        lo = s1[1] + diff;
        s1[0] = s1[0] + (lo < s1[1]);
        *s2 = now;
        s1[1] = lo;
    }
}
