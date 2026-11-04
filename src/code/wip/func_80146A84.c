// FLAGS: -O2 -g0 -mips2
#include "types.h"
typedef struct { u8 pad0[4]; void *unk4; } S;
extern u8 D_801EAE2F;
extern u16 D_801EE370;
extern u8 D_801EE372;
extern u16 D_801E6EFC;
extern u8 D_801E6EF0[];
extern void func_80147818();
extern void func_800897D0(void *, s32);
extern void func_800FEA90(void *, void *, s32);
void Sram_EraseSave(s32 a0, S *a1, s32 a2) {
    u8 *p = (u8 *)(a0 + a2);
    if (D_801EAE2F != 0) {
        if (p[0x2446A] != 0) {
            func_80147818(a1, a2, a2, a0);
            p[0x2446A] = 0;
        }
        func_800897D0(a1->unk4, 0x4000);
        func_800FEA90(D_801E6EF0, a1->unk4, 0x100C);
    }
    D_801E6EFC = D_801EE370;
    D_801EAE2F = D_801EE372;
}
