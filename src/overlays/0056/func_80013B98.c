#include "types.h"

typedef struct { u8 pad0[0x13C]; void *unk13C; u8 pad1[0xA6C - 0x140]; u32 unkA6C; } A;
extern void func_80830B44();
extern u8 D_80853794[];

void func_80013B98(void *a0, A *a1) {
    func_80830B44(a0, a1, D_80853794, 0);
    a1->unk13C = 0;
    a1->unkA6C |= 0x20000000;
}
