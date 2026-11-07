#include "types.h"
typedef struct { u8 pad0[0x68]; f32 unk68; u8 pad1[0xF0]; void *unk15C; } A;
extern u8 D_80BBA7B8[];
void func_80000368(A *a) {
    a->unk15C = D_80BBA7B8;
    a->unk68 = -23.0f;
}
