#include "types.h"

typedef struct { u8 pad0[0x2A8]; void *unk2A8; u8 unk2AC; u8 pad2AD[0xAB]; s16 unk358; } A;
extern void func_8098B264();
extern u8 D_8098B3A8[];

void func_800003A8(A *a) {
    func_8098B264(a, 1);
    a->unk358 = 4;
    a->unk2AC = 0;
    a->unk2A8 = D_8098B3A8;
}
