#include "types.h"

typedef struct { s32 x, y, z; } V;
typedef struct { u8 pad0[0x1E0]; V unk1E0; V unk1EC; u8 pad1[0x20C - 0x1F8]; void (*unk20C)(); } A;

void func_800008A8(A *a0) {
    a0->unk20C(a0);
    a0->unk1EC = a0->unk1E0;
}
