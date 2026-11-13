#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_801378E0(s32, M2C_UNK *, u8 *);      /* extern */
extern M2C_UNK D_6000184;
extern M2C_UNK D_808C2458;
extern M2C_UNK D_808C2BFC;
extern u8 D_808C2ECC;
extern f32 D_808C2F28;
extern f32 D_808C2F2C;

void func_80000FB0(u8 *arg0) {
    func_801378E0(arg0 + 0x144, &D_6000184, arg0);
    M2C_FIELD(arg0, M2C_UNK **, 0x13C) = &D_808C2BFC;
    M2C_FIELD(arg0, f32 *, 0x58) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x5C) = (f32) D_808C2F28;
    M2C_FIELD(arg0, f32 *, 0x60) = 0.0f;
    M2C_FIELD(arg0, f32 *, 0x264) = 1.0f;
    M2C_FIELD(arg0, f32 *, 0x268) = (f32) D_808C2F2C;
    M2C_FIELD(arg0, u8 *, 0xB7) = (u8) D_808C2ECC;
    M2C_FIELD(arg0, M2C_UNK **, 0x248) = &D_808C2458;
}
