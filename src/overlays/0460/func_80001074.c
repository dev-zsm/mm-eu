// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_dhouse.h"

void ref_func_80B139F4(ObjDhouse* this, PlayState* play) {
    Camera* camera = GET_ACTIVE_CAM(play);
    s16 quakeIndex;

    if (this->unk_1370 == 117) {
        quakeIndex = Quake_Request(camera, QUAKE_TYPE_3);
        Quake_SetSpeed(quakeIndex, 20000);
        Quake_SetPerturbations(quakeIndex, 8, 0, 0, 0);
        Quake_SetDuration(quakeIndex, 17);
    } else if (this->unk_1370 == 105) {
        quakeIndex = Quake_Request(camera, QUAKE_TYPE_3);
        Quake_SetSpeed(quakeIndex, 20000);
        Quake_SetPerturbations(quakeIndex, 7, 0, 0, 0);
        Quake_SetDuration(quakeIndex, 20);
    } else if (this->unk_1370 == 90) {
        quakeIndex = Quake_Request(camera, QUAKE_TYPE_3);
        Quake_SetSpeed(quakeIndex, 20000);
        Quake_SetPerturbations(quakeIndex, 5, 0, 0, 0);
        Quake_SetDuration(quakeIndex, 62);
    }

    this->unk_1370--;
    if (this->unk_1370 <= 0) {
        this->dyna.actor.draw = ref_func_80B13E40;
        this->dyna.actor.flags &= ~ACTOR_FLAG_DRAW_CULLING_DISABLED;
        this->dyna.actor.flags &= ~ACTOR_FLAG_UPDATE_CULLING_DISABLED;
        ref_func_80B13908(this);
    } else {
        ref_func_80B12B38(this, play);
        ref_func_80B13724(this, play);
    }
}
