// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

void ObjSwitch_CrystalSwitchOnInit(ObjSwitch* this) {
    this->color.r = 255;
    this->color.g = 255;
    this->color.b = 255;
    this->actionFunc = ObjSwitch_CrystalSwitchOn;
}
