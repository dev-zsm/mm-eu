#include "types.h"
#include "m2c_compat.h"
#include "generated/overlays/0342.h"
extern u8 D_80A35FB0[];
extern u8 D_80A360E4[];
extern u8 D_80A360EC[];

u8 *func_800000B8(u8 *a, s32 b) {
    switch (M2C_FIELD(a, s16 *, 0x198)) {
        case 1:
            return D_80A360E4;
        case 2:
            return D_80A360EC;
        default:
            return D_80A35FB0;
    }
}
