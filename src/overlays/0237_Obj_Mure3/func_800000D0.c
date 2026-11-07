// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure3.h"

void ref_func_8098F110(ObjMure3* this, PlayState* play) {
    s32 i;
    Vec3f spawnPos;
    f32 sin = Math_SinS(this->actor.world.rot.y);
    f32 cos = Math_CosS(this->actor.world.rot.y);
    f32 dist;

    spawnPos.y = this->actor.world.pos.y;

    for (i = 0, dist = -40.0f; i < 5; i++, dist += 20.0f) {
        if (!((this->unk164 >> i) & 1)) {
            spawnPos.x = this->actor.world.pos.x + (sin * dist);
            spawnPos.z = this->actor.world.pos.z + (cos * dist);
            this->unk148[i] = (EnItem00*)Item_DropCollectible2(play, &spawnPos, 0x4000);
            if (this->unk148[i] != NULL) {
                this->unk148[i]->actor.room = this->actor.room;
            }
        }
    }
}
