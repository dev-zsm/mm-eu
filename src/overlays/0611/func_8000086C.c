#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0611.h"

s32 func_800B7164(u8 *, M2C_UNK);                         /* extern */

s32 func_8000086C(u8 *arg0, u8 *arg1) {
    u8 *sp18;
    u8 *temp_v1;

    temp_v1 = M2C_FIELD(arg1, u8 **, 0x1CCC);
    if (M2C_FIELD(arg0, f32 *, 0x98) < 100.0f) {
        sp18 = temp_v1;
        if ((func_800B7164(arg0, 0x3000) != 0) && (M2C_FIELD(temp_v1, s32 *, 0xA70) & 0x02000000)) {
            return 1;
        }
    }
    return 0;
}
