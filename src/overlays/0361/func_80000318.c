#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0361.h"

M2C_UNK func_800B8D94(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_800FFAD8(u8 *, f32, M2C_UNK, s32, f32); /* extern */
M2C_UNK func_80A55794(u8 *, s32);                 /* extern */
extern f32 D_80A55DD0;

void func_80000318(u8 *arg0, s32 arg1) {
    f32 temp_f0;

    func_800B8D94(arg0, 0x2143);
    func_800FFAD8(arg0 + 0x160, M2C_FIELD(arg0, f32 *, 0x164), 0x40000000, M2C_FIELD(arg0, s32 *, 0x16C), D_80A55DD0);
    M2C_FIELD(arg0, f32 *, 0x28) = (f32) (M2C_FIELD(arg0, f32 *, 0x160) + M2C_FIELD(arg0, f32 *, 0xC));
    if (M2C_FIELD(arg0, f32 *, 0x164) == M2C_FIELD(arg0, f32 *, 0x160)) {
        func_80A55794(arg0, arg1);
    }
}
