// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct {
    u32 unk0;
    s32 unk4;
    s32 unk8;
    u8 pad0C[0x44];
    s32 unk50;
    u8 pad54[0x8];
    s32 unk5C;
    s32 unk60;
    u8 pad64;
    u8 unk65;
} SomeStruct;
typedef struct {
    s32 unk0;
    s32 unk4;
    u16 unk8;
    u8 padA[0x4];
    u8 unkE[0x10];
} Packet;
typedef union {
    u16 w;
    struct {
        u8 hi;
        u8 lo;
    } b;
} U16B;
typedef struct {
    s32 a;
    u16 b;
    U16B c;
    s32 pad;
} Res;
s32 func_8008D0B0(SomeStruct *a0);
s32 func_8008D184(SomeStruct *a0, u16 *a1, s32 a2, s32 a3);
s32 func_80090DE0(s32 a0, s32 a1, u16 a2, void *a3);
void func_80091460(void *a0, void *a1, s32 a2);
s32 func_8008B560(s32 a0, s32 a1);
s32 func_80092DA0(SomeStruct *a0, u8 a1);
s32 func_80092EA0(SomeStruct *a0, s32 a1, Packet *a2) {
    u16 sp58[0x80];
    u8 sp48[0x10];
    u8 sp44[0x4];
    Res r;
    U16B cur;
    register s32 s2;
    register u8 s0;
    register s32 ret;

    if (a1 >= a0->unk50 || a1 < 0) {
        return 5;
    }
    if (!(a0->unk0 & 1)) {
        return 5;
    }
    ret = func_8008D0B0(a0);
    if (ret != 0) {
        return ret;
    }
    if (a0->unk65 != 0) {
        ret = func_80092DA0(a0, 0);
        if (ret != 0) {
            return ret;
        }
    }
    ret = func_80090DE0(a0->unk4, a0->unk8, a0->unk5C + a1, &r);
    if (ret != 0) {
        return ret;
    }
    if (r.b == 0 || r.a == 0) {
        return 5;
    }
    cur = r.c;
    s2 = 0;
    s0 = 0xFF;
    for (;;) {
        if (cur.w < a0->unk60) {
            break;
        }
        if (s0 != cur.b.hi) {
            s0 = cur.b.hi;
            ret = func_8008D184(a0, sp58, 0, s0);
            if (ret != 0) {
                return ret;
            }
        }
        s2 += 1;
        cur = *(U16B *)&sp58[cur.b.lo];
    }
    if (cur.w != 1) {
        return 3;
    }
    a2->unk0 = s2 << 8;
    a2->unk8 = r.b;
    a2->unk4 = r.a;
    func_80091460(sp48, a2->unkE, 0x10);
    func_80091460(sp44, &a2->unk8 + 1, 4);
    return func_8008B560(a0->unk4, a0->unk8);
}
