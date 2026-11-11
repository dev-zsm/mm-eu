#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0056.h"

s32 func_80124640(u8 *);                          /* extern */
extern u8 *D_80862264;
extern s32 D_80862268;

s32 func_8000BC50(s32 arg0, u8 *arg1) {
    u32 temp_v0;

    if (!(M2C_FIELD(arg1, s32 *, 0xA6C) & 0x400000) && (((M2C_FIELD(arg1, s16 *, 0) != 0) && (~(M2C_FIELD(D_80862264, u16 *, 0xC) | ~0x4000) == 0)) || ((func_80124640(arg1) != 0) && ((temp_v0 = M2C_FIELD(arg1, u8 *, 0x14B), (temp_v0 != 1)) || (M2C_FIELD(arg1, u16 *, 0x90) & 1)) && ((temp_v0 != 2) || !(M2C_FIELD(arg1, s32 *, 0xA6C) & 0x02000000)) && (D_80862268 != 0)))) {
        return 1;
    }
    return 0;
}
