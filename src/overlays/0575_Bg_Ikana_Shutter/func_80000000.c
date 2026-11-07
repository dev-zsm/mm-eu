// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_shutter.h"

bool BgIkanaShutter_AllSwitchesPressed(BgIkanaShutter* this, PlayState* play) {
    return Flags_GetSwitch(play, BGIKANASHUTTER_GET_SWITCH_FLAG(&this->dyna.actor)) &&
           Flags_GetSwitch(play, BGIKANASHUTTER_GET_SWITCH_FLAG(&this->dyna.actor) + 1) &&
           Flags_GetSwitch(play, BGIKANASHUTTER_GET_SWITCH_FLAG(&this->dyna.actor) + 2) &&
           Flags_GetSwitch(play, BGIKANASHUTTER_GET_SWITCH_FLAG(&this->dyna.actor) + 3);
}
