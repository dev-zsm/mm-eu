#include "types.h"
#include "generated/overlays/0155.h"

extern void func_800B8C4C();

void ObjSwitch_PlayFootSwitchSfx(ObjSwitch *this) {
    if (!(((s8 *)this)[0x165] > 0)) {
        func_800B8C4C(this, 0x2815);
    }
}
