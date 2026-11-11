#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0144.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_80137934(s32, M2C_UNK *, M2C_UNK, u8 *); /* extern */
extern M2C_UNK D_60057F4;
extern M2C_UNK D_8090EC78;

void func_80000814(u8 *arg0) {
    func_80137934(arg0 + 0x144, &D_60057F4, 0xC0800000, arg0);
    func_800B8C4C(arg0, 0x39B3);
    M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8090EC78;
    M2C_FIELD(arg0, f32 *, 0x70) = 2.5f;
    M2C_FIELD(arg0, s16 *, 0x32) = (s16) M2C_FIELD(arg0, s16 *, 0xBE);
    M2C_FIELD(arg0, M2C_UNK **, 0x2F0) = &D_8090EC78;
}
