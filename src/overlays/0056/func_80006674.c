#include "types.h"

typedef struct { u8 p0[0xA6C]; u32 uA6C; } A;
extern void func_80830B44();
extern u8 D_80853910[];

void func_80006674(s32 a0, A *a) {
    func_80830B44(a0, a, D_80853910, 0);
    a->uA6C |= 0xA0000000;
}
