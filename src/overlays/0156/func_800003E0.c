// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_lift.h"

void ref_func_8093D7A0(ObjLift* this, PlayState* play) {
    s32 pad;
    s16 quakeIndex;

    if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
        if (this->timer <= 0) {
            if (OBJLIFT_GET_7(&this->dyna.actor) == 7) {
                ref_func_8093D9C0(this);
            } else {
                quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_1);
                Quake_SetSpeed(quakeIndex, 10000);
                Quake_SetPerturbations(quakeIndex, 2, 0, 0, 0);
                Quake_SetDuration(quakeIndex, 20);

                ref_func_8093D88C(this);
            }
        }
    } else {
        this->timer = ref_D_8093DD50[OBJLIFT_GET_7(&this->dyna.actor)];
    }
}
