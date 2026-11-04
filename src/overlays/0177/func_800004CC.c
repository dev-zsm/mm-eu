// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lightswitch.h"

void ObjLightswitch_Idle(ObjLightswitch* this, PlayState* play) {
    s32 actorType = LIGHTSWITCH_GET_TYPE(&this->actor);

    if (this->hitState >= 10) {
        if (actorType == LIGHTSWITCH_TYPE_FAKE) {
            ObjLightswitch_SetAction(this, ObjLightSwitch_SetupFade, 1);
        } else {
            if (actorType == LIGHTSWITCH_TYPE_FLIP) {
                this->hitState = 0;
            }
            ObjLightswitch_SetAction(this, ObjLightSwitch_SetupAsleep, 1);
        }
    }
}
