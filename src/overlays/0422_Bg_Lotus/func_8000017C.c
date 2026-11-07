// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_lotus.h"

void ref_func_80AD68DC(BgLotus* this, PlayState* play) {
    f32 sp34;

    this->unk168--;
    sp34 = Math_SinF(this->unk168 * (M_PIf / 48)) * 6.0f;

    if (this->dyna.actor.params == 0) {
        this->dyna.actor.world.pos.x = (Math_SinS(this->dyna.actor.world.rot.y) * sp34) + this->dyna.actor.home.pos.x;
        this->dyna.actor.world.pos.z = (Math_CosS(this->dyna.actor.world.rot.y) * sp34) + this->dyna.actor.home.pos.z;
        if (this->unk168 == 0) {
            this->unk168 = 0x60;
            this->dyna.actor.world.rot.y += (s16)((s32)Rand_Next() >> 0x12);
        }
    }
    if (this->unk160 < this->dyna.actor.floorHeight) {
        this->dyna.actor.world.pos.y = this->dyna.actor.floorHeight;
    } else {
        this->dyna.actor.world.pos.y = this->unk160;
        if (DynaPolyActor_IsPlayerOnTop(&this->dyna)) {
            if (!this->unk164) {
                EffectSsGRipple_Spawn(play, &this->dyna.actor.world.pos, 0x3E8, 0x578, 0);
                EffectSsGRipple_Spawn(play, &this->dyna.actor.world.pos, 0x3E8, 0x578, 8);
                this->unk166 = 40;
            }
            if (gSaveContext.save.playerForm != PLAYER_FORM_DEKU) {
                this->unk166 = 40;
                this->dyna.actor.flags |= ACTOR_FLAG_UPDATE_CULLING_DISABLED;
                this->actionFunc = ref_func_80AD6A88;
                return;
            }
            this->unk164 = true;
        } else {
            this->unk164 = false;
        }
    }
    if (this->unk166 > 0) {
        this->unk166--;
    }
    ref_func_80AD6830(this);
}
