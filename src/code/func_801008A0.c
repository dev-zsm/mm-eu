#include "types.h"

extern s16 D_801E6F26;

s32 LifeMeter_IncreaseInterfaceHealth(u8 *arg0) {
    s16 *health = (s16 *)(arg0 + 0x16C36);

    health[1] = 0x140;
    health[0] += 0x10;
    if (health[0] >= D_801E6F26) {
        health[0] = D_801E6F26;
        return 1;
    }
    return 0;
}
