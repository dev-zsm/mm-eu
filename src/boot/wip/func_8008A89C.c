// FLAGS: -O1 -g0 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} Block16;

extern s32 D_8009D340;
extern s32 D_80000000;
extern s32 D_80000004;
extern s32 D_80000008;
extern s32 D_8000000C;
extern s32 D_8000030C;
extern s32 D_80000300;
extern u8 D_8000031C[];
extern s32 D_80098040;
extern s32 D_80098044;
extern s32 D_80098048;
extern s32 D_A4500008;
extern s32 D_A4500010;
extern s32 D_A4500014;
extern Block16 func_80088CA0;

s32 func_8008A760(void);
void func_8008A770(s32 a);
void func_8008A780(s32 a, s32 b);
void func_8008A800(void);
s32 func_8008B080(s32 a, s32 *b);
void func_8008EF80(void);
void func_8008F410(s32 a, s32 b);
void func_80092E80(s32 a);
void func_80093DA0(void);
s32 func_80093F30(void);
s32 func_800953C0(s32 a, s32 b);
void func_800969C0(s32 a);
typedef struct {
    s32 hi;
    s32 lo;
} Pair8;

Pair8 func_80088B48(s32 a, s32 b, s32 c, s32 d);
Pair8 func_80088A48(s32 a, s32 b, s32 c, s32 d);
void func_800897D0(u8 *p, s32 n);

void func_8008A89C(void) {
    s32 sp2C;
    s32 s0;
    Pair8 sp20;

    D_8009D340 = 1;
    s0 = func_8008A760();
    func_8008A770(s0 | 0x20000000);
    func_80092E80(0x01000800);
    func_800969C0(0x04900000);
    if (func_8008B080(0x1FC007FC, &sp2C) != 0) {
        do {
        } while (func_8008B080(0x1FC007FC, &sp2C) != 0);
    }
    if (func_800953C0(0x1FC007FC, sp2C | 8) != 0) {
        do {
        } while (func_800953C0(0x1FC007FC, sp2C | 8) != 0);
    }
    *(Block16 *)0x80000000 = *(Block16 *)0x80088CA0;
    *(Block16 *)0x80000080 = *(Block16 *)0x80088CA0;
    *(Block16 *)0x80000100 = *(Block16 *)0x80088CA0;
    *(Block16 *)0x80000180 = *(Block16 *)0x80088CA0;
    func_8008A780(0x80000000, 0x190);
    func_8008F410(0x80000000, 0x190);
    func_8008A800();
    func_8008EF80();
    func_80093DA0();
    sp20 = func_80088B48(D_80098040, D_80098044, 0, 3);
    *(Pair8 *)&D_80098040 = func_80088A48(sp20.hi, sp20.lo, 0, 4);
    if (D_8000030C == 0) {
        func_800897D0(D_8000031C, 0x40);
    }
    if (D_80000300 == 0) {
        D_80098048 = 0x02F5B2D2;
    } else if (D_80000300 == 2) {
        D_80098048 = 0x02E6025C;
    } else {
        D_80098048 = 0x02E6D354;
    }
    if (func_80093F30() & 0x1000) {
        for (;;) {}
    }
    *(s32 *)0xA4500008 = 1;
    *(s32 *)0xA4500010 = 0x3FFF;
    *(s32 *)0xA4500014 = 0xF;
}
