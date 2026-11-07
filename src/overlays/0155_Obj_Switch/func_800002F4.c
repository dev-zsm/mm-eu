#include "types.h"
#include "generated/overlays/0155.h"

extern void func_800B8C4C();

void ObjSwitch_PlayFootSwitchSfx(u8 *a0) {
    if (!(((s8 *)a0)[0x165] > 0)) {
        func_800B8C4C(a0, 0x2815);
    }
}
