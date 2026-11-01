#include "types.h"
typedef struct { u8 pad[0x58]; f32 unk58; f32 unk5C; f32 unk60; } A;
extern f32 D_8091B280;
extern f32 D_8091B284;
void func_8000079C(A *a0) { f32 t = D_8091B280; f32 u = D_8091B284; a0->unk60 = t; a0->unk58 = t; a0->unk5C = u; }
