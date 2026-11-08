#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0452.h"

s32 func_80002668(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, u8 *thisx) {
    if (limb == 0xC) {
        rot->y += M2C_FIELD(thisx, s16 *, 0x3E6);
    } else if (limb == 0x17) {
        rot->y += M2C_FIELD(thisx, s16 *, 0x3E0);
    }
    return 0;
}
