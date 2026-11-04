// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_yasi.h"

void ObjYasi_Update(Actor* thisx, PlayState* play) {
    ObjYasi* this = (ObjYasi*)thisx;
    s16 temp;
    Vec3f dropPos;

    if (this->dyna.actor.home.rot.z != 0) {
        if (CAN_DROP_NUT(thisx)) {
            if (Rand_ZeroOne() < 0.5f) {
                dropPos.x = this->dyna.actor.world.pos.x;
                dropPos.y = this->dyna.actor.world.pos.y + 280.0f;
                dropPos.z = this->dyna.actor.world.pos.z;
                Item_DropCollectible(play, &dropPos, ITEM00_DEKU_NUTS_1);
            }
        }
        this->dyna.actor.home.rot.y = GET_PLAYER(play)->actor.shape.rot.y;
        this->dyna.actor.home.rot.x = 400;
        this->dyna.actor.home.rot.z = 0;
    }
    temp = TRUNCF_BINANG(this->dyna.actor.shape.rot.x * 0.1f);
    this->dyna.actor.home.rot.x -= temp;
    this->dyna.actor.shape.rot.x +=
        BINANG_SUB(this->dyna.actor.home.rot.x, TRUNCF_BINANG(this->dyna.actor.shape.rot.x * 0.08f));
}
