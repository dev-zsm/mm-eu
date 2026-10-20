// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct Obj {
    u8 pad0[0x24C];
    u8 unk24C;
} Obj;

extern s32 D_80096D00;
extern void func_800813B8(Obj *a, u8 *b);
extern void func_800942F0(void *a, u64 b, s32 c, s32 d, void *e, s32 f);

void func_80081524(Obj *arg0) {
    D_80096D00 = 2;
    arg0->unk24C = 2;
    func_800942F0((u8 *)arg0 + 0x258, 0x15752A, 0, 0, (u8 *)arg0 + 0x60, 0x2A0);
    func_800813B8(arg0, (u8 *)arg0 + 0x40);
}
