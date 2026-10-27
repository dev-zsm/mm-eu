#include "types.h"
s64 func_800905C0(void);
void SysFlashrom_WriteAsync(s32, s32, s32, void *);
typedef struct { u8 pad0[4]; s32 unk4; u8 pad8[4]; s16 unkC; u8 padE[2]; s32 unk10; s32 unk14; s64 unk18; } S;
void func_80147524(S *a0) {
    SysFlashrom_WriteAsync(a0->unk4, a0->unk10, a0->unk14, a0);
    a0->unk18 = func_800905C0();
    a0->unkC = 2;
}
