#include "types.h"
typedef struct { u16 unk0; u16 pad; s32 unk4; s32 unk8; } S;
extern s32 D_801ED320;
extern u8 *func_80100304(s32);
extern void AnimatedMat_SetColor(s32, s32, u8 *, u8 *);
void AnimatedMat_DrawColor(s32 a0, s32 a1, S *a2) {
    s32 pad; // unused local, only to match the stack layout
    u8 *p = func_80100304(a2->unk4);
    u8 *q = 0;
    s32 i = D_801ED320 % a2->unk0;
    p += i * 5;
    if (a2->unk8 != 0) { q = func_80100304(a2->unk8) + i * 4; } else { q = 0; }
    AnimatedMat_SetColor(a0, a1, p, q);
}
