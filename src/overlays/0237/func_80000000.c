// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure3.h"

void ref_func_8098F040(ObjMure3* this, PlayState* play) {
    s32 i;
    Vec3f spawnPos;

    Math_Vec3f_Copy(&spawnPos, &this->actor.world.pos);
    for (i = 0; i < 5; i++, spawnPos.y += 20.0f) {
        if (!((this->unk164 >> i) & 1)) {
            this->unk148[i] = (EnItem00*)Item_DropCollectible2(play, &spawnPos, 0x10001);
            if (this->unk148[i] != NULL) {
                this->unk148[i]->actor.room = this->actor.room;
            }
        }
    }
}
