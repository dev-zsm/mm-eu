// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9C058(BgHakuginPost* this, PlayState* play, BgHakuginPostUnkStruct* unkStruct) {
    s32 i;
    s32 pad;
    Vec3f sp44;
    s32 pad2[2];
    s16 quakeIndex;

    if (this->unk_170 == 0) {
        for (i = 0; i < unkStruct->count; i++) {
            BgHakuginPostUnkStruct1* unkStruct1 = &unkStruct->unk_0000[i];

            if (unkStruct1->unk_2F & 2) {
                sp44.x = this->dyna.actor.home.pos.x + unkStruct1->unk_14.x;
                sp44.y = this->unk_16C + unkStruct1->unk_14.y;
                sp44.z = this->dyna.actor.home.pos.z + unkStruct1->unk_14.z;
                Rumble_Request(Math3D_Vec3fDistSq(&sp44, &GET_PLAYER(play)->actor.world.pos), 255, 20, 150);

                quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);
                Quake_SetSpeed(quakeIndex, 20000);
                Quake_SetPerturbations(quakeIndex, 7, 0, 0, 0);
                Quake_SetDuration(quakeIndex, 12);

                if (this->unk_179 <= 0) {
                    Audio_PlaySfx_2(NA_SE_EV_STONEDOOR_STOP);
                    this->unk_179 = 40;
                }
                break;
            }
        }
    }
}
