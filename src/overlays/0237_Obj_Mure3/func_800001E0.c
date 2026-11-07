// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mure3.h"

void ref_func_8098F220(ObjMure3* this, PlayState* play) {
    s16 yRot;
    Vec3f spawnPos;
    s32 i;

    spawnPos.y = this->actor.world.pos.y;
    yRot = this->actor.world.rot.y;

    for (i = 0; i < 6; i++) {
        if (!((this->unk164 >> i) & 1)) {
            spawnPos.x = (Math_SinS(yRot) * 40.0f) + this->actor.world.pos.x;
            spawnPos.z = (Math_CosS(yRot) * 40.0f) + this->actor.world.pos.z;
            this->unk148[i] = (EnItem00*)Item_DropCollectible2(play, &spawnPos, 0x4000);
            if (this->unk148[i] != NULL) {
                this->unk148[i]->actor.room = this->actor.room;
            }
        }
        yRot += 0x2AAA;
    }

    if (!((this->unk164 >> 6) & 1)) {
        spawnPos.x = this->actor.world.pos.x;
        spawnPos.z = this->actor.world.pos.z;
        this->unk160 = Item_DropCollectible2(play, &spawnPos, 0x4002);
        if (this->unk160 != NULL) {
            this->unk160->room = this->actor.room;
        }
    }
}
