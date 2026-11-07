#include "types.h"
typedef struct { u8 pad0[0x68]; f32 unk68; u8 pad1[0xF4]; void *unk15C; } A;
extern u8 D_80BEFBFC[];
void func_800006FC(A *a) {
    a->unk15C = D_80BEFBFC;
    a->unk68 = 30.0f;
}
