#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

M2C_UNK func_8082D1C8(s32, u8 *, s32);            /* extern */
M2C_UNK func_80830B44(s32, u8 *, M2C_UNK *, M2C_UNK); /* extern */
extern M2C_UNK D_8084E690;
extern s32 D_8085B8A4[];

void func_80010840(u8 *arg0, s32 arg1) {
    func_80830B44(arg1, arg0, &D_8084E690, 0);
    func_8082D1C8(arg1, arg0, D_8085B8A4[M2C_FIELD(arg0, u8 *, 0x14F)]);
    M2C_FIELD(arg0, s32 *, 0xA70) = (s32) (M2C_FIELD(arg0, s32 *, 0xA70) | 0x10);
}
