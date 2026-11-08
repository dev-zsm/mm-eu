// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0195.h"

M2C_UNK func_800B8C4C(u8 *, M2C_UNK);             /* extern */
M2C_UNK func_809592D0(u8 *);                      /* extern */
M2C_UNK func_80959A7C(u8 *, u8 *);              /* extern */
s32 func_80959B84(u8 *);                          /* extern */
s32 func_80959BE0(u8 *, u8 *);                  /* extern */

s32 func_80001088(Actor *thisx, PlayState *play) {
    if (M2C_FIELD(thisx, s16 *, 0x52A) == 0) {
        func_80959A7C(thisx, play);
    }
    if (func_80959B84(thisx) != 0) {
        return 0;
    }
    if (M2C_FIELD(play, u8 *, 0x1CA2) != 0) {
        M2C_FIELD(thisx, s16 *, 0x526) = 8;
        if (M2C_FIELD(thisx, s16 *, 0x52A) == 0) {
            func_800B8C4C(thisx, 0x389E);
            func_800B8C4C(thisx, 0x6867);
        }
        func_809592D0(thisx);
        M2C_FIELD(thisx, u16 *, 0x5C2) = (u16) (M2C_FIELD(thisx, u16 *, 0x5C2) | 1);
        return 0;
    }
    return func_80959BE0(thisx, play);
}
