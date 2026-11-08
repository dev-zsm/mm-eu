// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0143.h"

void func_800BA9E4(u8 *, u8 *, s32, s32, f32, f32, s32, s32, s32, s32);

void func_80000154(u8 *arg0, u8 *arg1, s32 arg2) {
    func_800BA9E4(arg1 + 0x1CA0, arg1, 0x164, M2C_FIELD(arg0, s32 *, 0x24), M2C_FIELD(arg0, f32 *, 0x28),
                  M2C_FIELD(arg0, f32 *, 0x2C), 0, 0, 0, 2);
}
