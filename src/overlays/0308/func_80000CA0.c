#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0308.h"

s32 func_80000CA0(s32 play, s32 limb, s32 dl, s32 pos, Vec3s *rot, u8 *thisx) {
    if (limb == 3 && M2C_FIELD(thisx, s16 *, 0x1F0) == 1) {
        rot->z += M2C_FIELD(thisx, s16 *, 0x1F2);
    }
    return 0;
}
