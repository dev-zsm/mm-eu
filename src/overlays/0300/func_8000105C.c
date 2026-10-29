#include "types.h"

extern u8 D_80A03810[];
extern s16 D_80A03F3C[];

void func_8000105C(u8 *a0) {
    *(u8 **)(a0 + 0x4A0) = D_80A03810;
    *(s16 *)(a0 + 0x4DC) = D_80A03F3C[*(s32 *)(a0 + 0x4A8)];
    *(f32 *)(a0 + 0x70) = 0.0f;
}
