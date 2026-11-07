#include "types.h"
#include "m2c_compat.h"
void func_801A58EC(s32 a);
void func_800B8C4C(u8 *a, s32 b);

void func_80000990(u8 *a, u8 *play) {
    switch (M2C_FIELD(play, u16 *, 0x1F34)) {
        case 5:
            func_801A58EC(0xC);
            break;
        case 0x294:
            func_800B8C4C(a, 0x390B);
            break;
    }
}
