// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_CrystalSwitchTurnOff(ObjSwitch* this, PlayState* play) {
    s32 switchHit = (this->colliderJntSph.base.acFlags & AC_HIT) != 0;

    if (switchHit) {
        this->disableCrystalSwitchTimer = 10;
    }
    ObjSwitch_StopCutscene(this);
    ObjSwitch_CrystalUpdateTimer(this);
    ObjSwitch_PlayDiamondSwitchSfx(this);
    ObjSwitch_CrystalSwitchOffInit(this);
}
