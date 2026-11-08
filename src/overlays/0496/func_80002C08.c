#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0496.h"
extern u8 D_80B47840[];

s32 func_80002C08(s32 play, s32 limb, u32 *dl, s32 d, s32 e, u8 *thisx) {
    if (M2C_FIELD(thisx, u8 *, 0x293) == 0 || limb == 7 ||
        ((void *)D_80B47840 == M2C_FIELD(thisx, void **, 0x200) && M2C_FIELD(thisx, s16 *, 0x206) >= 2)) {
        *dl = 0;
    }
    return 0;
}
