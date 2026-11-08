#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0360.h"
extern struct { u8 pad0[0xF37]; u8 fF37; } D_801E6EF0;
extern u8 D_80A5495C[];
void func_801A6A90(s32 a);
void func_801A10E8(s32 a, s32 b);

void func_80000B00(u8 *a) {
    func_801A6A90(0x6F);
    func_801A10E8(0, 5);
    D_801E6EF0.fF37 |= 1;
    D_801E6EF0.fF37 &= 0xFD;
    M2C_FIELD(a, void **, 0x1D4) = D_80A5495C;
}
