#include "types.h"
#include "m2c_compat.h"
void func_800B8C4C(u8 *a, s32 b);

void func_800007A0(u8 *a, u8 *play) {
    if (M2C_FIELD(a, s16 *, 0x1C) == 0) {
        switch (M2C_FIELD(play, u16 *, 0x1F34)) {
            case 8:
                func_800B8C4C(a, 0x2925);
                break;
            case 0x82:
                func_800B8C4C(a, 0x285F);
                break;
        }
    }
}
