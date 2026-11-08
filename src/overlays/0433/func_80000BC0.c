#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0433.h"
extern u8 D_600B738[];
void func_80ACB1B8(u8 *a, s32 b);

s32 func_80000BC0(s32 play, s32 limb, u32 *dl, s32 pos, s32 rot, u8 *thisx) {
    if (limb == 0xF) {
        func_80ACB1B8(thisx, play);
        *dl = (u32)D_600B738;
    }
    return 0;
}
