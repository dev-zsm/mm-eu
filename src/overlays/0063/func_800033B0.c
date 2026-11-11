#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0063.h"

M2C_UNK func_8012AD58(s16, M2C_UNK);                /* extern */
M2C_UNK func_8012ADA0(s16, M2C_UNK);                /* extern */
M2C_UNK func_8012AE28(s16, M2C_UNK, M2C_UNK, M2C_UNK, s32); /* extern */
s16 func_8012AF4C(s32, M2C_UNK);                    /* extern */
M2C_UNK func_8012AF70(s16);                         /* extern */
M2C_UNK func_8013F090(f32, M2C_UNK, M2C_UNK, M2C_UNK); /* extern */
extern M2C_UNK D_8086C908;

void func_800033B0(u8 *arg0, u8 *arg1) {
    M2C_FIELD(arg0, s16 *, 0x1C) = 1;
    func_8012AF70(M2C_FIELD(arg0, s16 *, 0x2B4));
    M2C_FIELD(arg0, s16 *, 0x2B4) = func_8012AF4C(((s32 *)(arg1 + 0x800))[M2C_FIELD(arg1, s16 *, 0x810)], 3);
    func_8012AD58(M2C_FIELD(arg0, s16 *, 0x2B4), 0x4E20);
    func_8012AE28(M2C_FIELD(arg0, s16 *, 0x2B4), 0x11, 0, 0, 0);
    func_8012ADA0(M2C_FIELD(arg0, s16 *, 0x2B4), 0xC);
    func_8013F090(M2C_FIELD(arg0, f32 *, 0x94), 0xFF, 0x14, 0x96);
    M2C_FIELD(arg0, M2C_UNK **, 0x2A8) = &D_8086C908;
}
