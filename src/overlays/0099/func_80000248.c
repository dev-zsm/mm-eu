#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0099.h"

s16 func_800FF250(M2C_UNK, M2C_UNK);                /* extern */
M2C_UNK func_800FF30C(u8 *, u8 *);              /* extern */
M2C_UNK func_80137884(s32, M2C_UNK *, f32);     /* extern */
extern M2C_UNK D_6003180;
extern M2C_UNK D_808BCB7C;

void func_80000248(u8 *arg0) {
    func_80137884(arg0 + 0x144, &D_6003180, 0);
    M2C_FIELD(arg0, s16 *, 0x190) = func_800FF250(0x64, 0x32);
    M2C_FIELD(arg0, s16 *, 0x2BE) = 5;
    func_800FF30C(arg0 + 0x24, arg0 + 8);
    M2C_FIELD(arg0, u8 *, 0x28D) = (u8) (M2C_FIELD(arg0, u8 *, 0x28D) & 0xFFFE);
    M2C_FIELD(arg0, M2C_UNK **, 0x188) = &D_808BCB7C;
}
