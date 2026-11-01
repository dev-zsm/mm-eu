#include "types.h"
typedef struct { u8 pad[0x58]; f32 unk58; f32 unk5C; f32 unk60; u8 pad64[0xC]; f32 unk70; u8 pad74[0xD0]; void *unk144; u8 pad148[4]; s16 unk14C; } A;
extern f32 D_80A16998;
extern f32 D_80A1699C;
extern u8 D_80A148D0;
void func_80000DC0(A *a) {
    f32 f = D_80A16998;
    a->unk14C = 0xF;
    a->unk58 = f;
    a->unk60 = f;
    a->unk144 = &D_80A148D0;
    a->unk5C = D_80A1699C;
    a->unk70 = 0.0f;
}
