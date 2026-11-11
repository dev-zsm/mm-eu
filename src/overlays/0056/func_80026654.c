#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_800BA9E4(s32, s32, M2C_UNK, f32, f32, f32, s32, s32, s32, s32); /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_80853704;

void func_80026654(u8 *arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_80853704, 0);
    M2C_FIELD(arg0, s16 *, 0xAE8) = 0x28;
    func_800BA9E4(arg1 + 0x1CA0, arg1, 0x49, 0.0f, 0.0f, 0.0f, 0, 0, 0, 0x10);
}
