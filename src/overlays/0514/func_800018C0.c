// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_ikana_rotaryroom.h"

void ref_func_80B81BA0(Actor* thisx, PlayState* play) {
    BgIkanaRotaryroom* this = (BgIkanaRotaryroom*)thisx;
    s32 sp30 = 0;
    s32 i;

    Actor_PlaySfx_Flagged(&this->dyna.actor, NA_SE_EV_EARTHQUAKE - SFX_FLAG);

    if (this->unk_584 > 0) {
        this->unk_584--;
    }

    thisx->shape.rot.x += 0x1F4;

    if (!(this->unk_584 & 7)) {
        s16 quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);

        Quake_SetSpeed(quakeIndex, 31536);
        Quake_SetPerturbations(quakeIndex, (s32)(Rand_ZeroOne() * 2.5f) + 3, 0, 10, 0);
        Quake_SetDuration(quakeIndex, 15);
    }

    if (Flags_GetSwitch(play, BGIKANAROTARYROOM_GET_SWITCH_FLAG_1(&this->dyna.actor))) {
        if (this->dyna.actor.shape.rot.x < 0) {
            this->dyna.actor.shape.rot.x = -0x8000;
            sp30 = 1;
        }
    } else if (this->dyna.actor.shape.rot.x >= 0) {
        this->dyna.actor.shape.rot.x = 0;
        sp30 = 1;
    }

    ref_func_80B80C88(this, play);

    if (sp30 != 0) {
        Player* player = GET_PLAYER(play);
        BgIkanaRotaryroomStruct1* ptr;
        BgIkanaBlock* block = (BgIkanaBlock*)this->unk_204.unk_00;

        if (block != NULL) {
            block->unk_17C &= ~8;
            block->unk_17C |= 4;
        }

        for (i = 0; i < ARRAY_COUNT(this->unk_2D0); i++) {
            ptr = &this->unk_2D0[i];
            if (ptr->unk_00 != NULL) {
                ((EnTorch2*)ptr->unk_00)->state = 4;
            }
        }

        this->unk_520.unk_48 = 0.0f;
        this->unk_520.unk_4C.x = player->actor.world.pos.x;
        this->unk_520.unk_4C.y = player->actor.world.pos.y - ref_D_80B82200[player->transformation];
        this->unk_520.unk_4C.z = player->actor.world.pos.z;

        if (ref_func_80B816A4(this) > 0) {
            this->unk_578 = ref_func_80B81010;
        }

        this->unk_57C = ref_func_80B81234;
        this->actionFunc = ref_func_80B814B8;
        ref_func_80B802E0(this);
        ref_func_80B81DAC(this);
    }
}
