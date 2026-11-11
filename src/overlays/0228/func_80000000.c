#include "types.h"
#include "m2c_compat.h"

M2C_UNK func_800E1134(s32, u8 *, u8 *, M2C_UNK *); /* extern */
M2C_UNK func_800E72F0(u8 *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_80968BDC(u8 *);                      /* extern */
extern M2C_UNK D_8096A520;
extern M2C_UNK D_8096A54C;
extern M2C_UNK D_8096A554;

void func_80000000(u8 *arg0, s32 arg1) {
    M2C_FIELD(arg0, s32 *, 4) = (s32) (M2C_FIELD(arg0, s32 *, 4) & ~1);
    func_800E1134(arg1, arg0 + 0x160, arg0, &D_8096A520);
    func_800E72F0(arg0 + 0xA0, &D_8096A554, &D_8096A54C);
    M2C_FIELD(arg0, s8 *, 0xD0) = 0xFF;
    M2C_FIELD(arg0, s8 *, 0x149) = (s8) M2C_FIELD(arg0, s16 *, 0x1C);
    M2C_FIELD(arg0, u8 *, 0xD0) = 0xFF;
    func_80968BDC(arg0);
}
