// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_light.h"

void ref_func_80865BF8(EnLight* this, PlayState* play) {
    this->actor.shape.rot.y = BINANG_ROT180(Camera_GetCamDirYaw(GET_ACTIVE_CAM(play)));

    if (this->actor.parent != NULL) {
        Math_Vec3f_Copy(&this->actor.world.pos, &this->actor.parent->world.pos);
        this->actor.world.pos.y += 17.0f;
    }

    this->unk_144++;
}
