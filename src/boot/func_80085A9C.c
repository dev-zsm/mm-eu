// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x8];
    u16 unk8;
    u16 unkA;
    u16 unkC;
    u8 unkE;
} Struct;

extern void func_80085A78(Struct *s, s32 a1, s32 a2);

void func_80085A9C(Struct *s, s32 a1, s32 a2) {
    func_80085A78(s, a1 << 3, a2 << 3);
}
