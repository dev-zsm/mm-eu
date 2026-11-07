#include "types.h"
#include "m2c_compat.h"
extern u8 D_801E7DFF;
extern u8 D_80A38160[];
extern u8 D_80A38180[];
extern u8 D_80A38198[];

u8 *func_800007C8(u8 *a, s32 b) {
    if (D_801E7DFF & 0x20) {
        return D_80A38198;
    }
    if (M2C_FIELD(a, s32 *, 0x3A4) != 0) {
        return D_80A38180;
    }
    return D_80A38160;
}
