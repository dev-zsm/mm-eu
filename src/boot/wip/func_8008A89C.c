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

s32 __osGetSR(void);
void __osSetSR(s32 a);
void func_8008A780(s32 a, s32 b);
void func_8008A800(void);
s32 __osSiRawReadIo(s32 a, s32 *b);
void osUnmapTLBAll(void);
void osInvalICache(s32 a, s32 b);
void __osSetFpcCsr(s32 a);
void osMapTLBRdb(void);
s32 __osGetCause(void);
s32 __osSiRawWriteIo(s32 a, s32 b);
void __osSetWatchLo(s32 a);
typedef struct {
    s32 hi;
    s32 lo;
} Pair8;

Pair8 __ll_mul(s32 a, s32 b, s32 c, s32 d);
Pair8 __ull_div(s32 a, s32 b, s32 c, s32 d);
void bzero(u8 *p, s32 n);

void func_8008A89C(void) {
    s32 sp2C;
    s32 s0;
    Pair8 sp20;

    D_8009D340 = 1;
    s0 = __osGetSR();
    __osSetSR(s0 | 0x20000000);
    __osSetFpcCsr(0x01000800);
    __osSetWatchLo(0x04900000);
    if (__osSiRawReadIo(0x1FC007FC, &sp2C) != 0) {
        do {
        } while (__osSiRawReadIo(0x1FC007FC, &sp2C) != 0);
    }
    if (__osSiRawWriteIo(0x1FC007FC, sp2C | 8) != 0) {
        do {
        } while (__osSiRawWriteIo(0x1FC007FC, sp2C | 8) != 0);
    }
    *(Block16 *)0x80000000 = *(Block16 *)0x80088CA0;
    *(Block16 *)0x80000080 = *(Block16 *)0x80088CA0;
    *(Block16 *)0x80000100 = *(Block16 *)0x80088CA0;
    *(Block16 *)0x80000180 = *(Block16 *)0x80088CA0;
    func_8008A780(0x80000000, 0x190);
    osInvalICache(0x80000000, 0x190);
    func_8008A800();
    osUnmapTLBAll();
    osMapTLBRdb();
    sp20 = __ll_mul(D_80098040, D_80098044, 0, 3);
    *(Pair8 *)&D_80098040 = __ull_div(sp20.hi, sp20.lo, 0, 4);
    if (D_8000030C == 0) {
        bzero(D_8000031C, 0x40);
    }
    if (D_80000300 == 0) {
        D_80098048 = 0x02F5B2D2;
    } else if (D_80000300 == 2) {
        D_80098048 = 0x02E6025C;
    } else {
        D_80098048 = 0x02E6D354;
    }
    if (__osGetCause() & 0x1000) {
        for (;;) {}
    }
    *(s32 *)0xA4500008 = 1;
    *(s32 *)0xA4500010 = 0x3FFF;
    *(s32 *)0xA4500014 = 0xF;
}
