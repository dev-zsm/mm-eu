#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0455.h"

M2C_UNK func_800B701C(u8 *, u8 *, M2C_UNK);     /* extern */
M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_8016A87C(u8 *, s16, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK D_80AED36C;
extern M2C_UNK D_80AF3824;
extern M2C_UNK D_80AF3830;

void func_800032C0(u8 *arg0, u8 *arg1) {
    u8 *temp_v0;
    u8 *sp24;
    s16 temp_v1;

    temp_v0 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    sp24 = temp_v0;
    func_800B8C4C(arg0, 0x394F);
    func_8016A87C(arg1, M2C_FIELD(arg0, s16 *, 0x1AC), &D_80AF3824, &D_80AF3830);
    M2C_FIELD(arg0, s16 *, 0x37A) = -0x1F00;
    M2C_FIELD(arg0, s16 *, 0x37C) = -0x4000;
    M2C_FIELD(arg0, s16 *, 0x19C) = 0x46;
    M2C_FIELD(arg0, f32 *, 0x38C) = 680.0f;
    M2C_FIELD(arg0, f32 *, 0x390) = 370.0f;
    M2C_FIELD(arg0, f32 *, 0x394) = -1600.0f;
    M2C_FIELD(temp_v0, f32 *, 0x24) = 250.0f;
    M2C_FIELD(temp_v0, f32 *, 0x2C) = -1560.0f;
    M2C_FIELD(temp_v0, s16 *, 0xBE) = (s16) (M2C_FIELD(arg0, s16 *, 0x92) + 0x8000);
    temp_v1 = M2C_FIELD(temp_v0, s16 *, 0xBE);
    M2C_FIELD(temp_v0, s16 *, 0x32) = temp_v1;
    M2C_FIELD(temp_v0, s16 *, 0xAD4) = temp_v1;
    func_800B701C(arg1, arg0, 0x83);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_80AED36C;
}
