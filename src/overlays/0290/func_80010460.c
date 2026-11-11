#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0290.h"

M2C_UNK func_800B3B14(u8 *, f32, M2C_UNK *, M2C_UNK); /* extern */
M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
extern M2C_UNK D_800B3F30;
extern M2C_UNK D_809E9B8C;
extern M2C_UNK D_809ECBD4;

void func_80010460(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, M2C_UNK **, 0x144) = &D_809E9B8C;
    M2C_FIELD(arg0, f32 *, 0x74) = -0.75f;
    func_800B3B14(arg0 + 0xBC, 0, &D_800B3F30, 0x42200000);
    func_800E1134(arg1, arg0 + 0x1820, arg0, &D_809ECBD4);
    M2C_FIELD(arg0, s8 *, 0xB7) = 5;
    M2C_FIELD(arg0, s8 *, 0x14E) = 0;
}
