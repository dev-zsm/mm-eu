#include "types.h"
#include "generated/overlays/0155.h"

extern void func_800B8C4C();

void ObjSwitch_PlayDiamondSwitchSfx(u8 *a) {
    if (((s8 *)a)[0x165] <= 0) {
        func_800B8C4C(a, 0x28BA);
    }
}
