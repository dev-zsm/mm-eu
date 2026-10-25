#include "types.h"

typedef struct {
    u8 pad0[0x454];
    s16 unk454;
    s16 unk456;
    s16 unk458;
    s16 unk45A;
    s16 unk45C;
} D_801EB7E0_Type;

extern D_801EB7E0_Type *D_801EB7E0;

void func_8016B3F0(s32 a0, s16 a1, u8 a2, u8 a3, u8 a4, u8 a5) {
    D_801EB7E0->unk454 = a1;
    D_801EB7E0->unk456 = a2;
    D_801EB7E0->unk458 = a3;
    D_801EB7E0->unk45A = a4;
    D_801EB7E0->unk45C = a5;
}
