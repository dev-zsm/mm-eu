#include "types.h"
typedef struct { u8 pad0[4]; s32 unk4; } S;
extern u8 D_801E6EF0[];
extern s32 D_801C7D00[];
extern s32 D_801C7D10[];
void func_800897D0(s32, s32);
s32 SysFlashrom_Read(s32, s32, s32);
void func_800FEA90(void *, s32, s32);
void func_801473C0(S *, s32, s32);
void func_80147918(S *a0, s32 a1, s32 a2) {
    s32 *p;
    s32 *q;
    func_800897D0(a0->unk4, 0x4000);
    p = &D_801C7D00[a1 * 2];
    q = &D_801C7D10[a1 * 2];
    if (SysFlashrom_Read(a0->unk4, p[0], q[0]) != 0) {
        SysFlashrom_Read(a0->unk4, p[1], q[1]);
    }
    func_800FEA90(D_801E6EF0, a0->unk4, 0x3CA0);
    p = &D_801C7D00[a2 * 2];
    q = &D_801C7D10[a2 * 2];
    func_801473C0(a0, p[0], q[0]);
    func_801473C0(a0, p[1], q[0]);
}
