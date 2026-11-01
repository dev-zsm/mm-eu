#include "types.h"
typedef struct { u8 pad0[4]; s32 unk4; } S;
typedef struct { u8 pad0[0x23]; u8 b[7]; u8 pad2A[0xFE0]; s16 unk100A; } T;
extern T D_801E6EF0;
extern s32 D_801C7D00[];
extern s32 D_801C7D10[];
s16 Sram_CalcChecksum(T *, s32);
void func_800FEA90(s32, T *, s32);
void func_801473C0(S *, s32, s32);
void func_80147818(S *a0, s32 a1) {
    s32 *p;
    s32 *q;
    D_801E6EF0.b[0] = 0;
    D_801E6EF0.b[1] = 0;
    D_801E6EF0.b[2] = 0;
    D_801E6EF0.b[3] = 0;
    D_801E6EF0.b[4] = 0;
    D_801E6EF0.b[5] = 0;
    D_801E6EF0.b[6] = 0;
    D_801E6EF0.unk100A = 0;
    D_801E6EF0.unk100A = Sram_CalcChecksum(&D_801E6EF0, 0x3CA0);
    func_800FEA90(a0->unk4, &D_801E6EF0, 0x3CA0);
    p = &D_801C7D00[a1 * 2];
    q = &D_801C7D10[a1 * 2];
    func_801473C0(a0, p[0], q[0]);
    func_801473C0(a0, p[1], q[0]);
    D_801E6EF0.b[0] = 1;
    D_801E6EF0.b[1] = 0x5A;
    D_801E6EF0.b[2] = 0x45;
    D_801E6EF0.b[3] = 0x4C;
    D_801E6EF0.b[4] = 0x44;
    D_801E6EF0.b[5] = 0x41;
    D_801E6EF0.b[6] = 0x33;
}
