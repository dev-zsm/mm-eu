// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9CE1C(BgHakuginPost* this, PlayState* play) {
    s32 pad;
    Player* player = GET_PLAYER(play);
    ColliderCylinder* collider;
    s32 yDiff;
    s32 i;
    s16 temp;
    f32 temp_f0;
    f32 temp_f2;

    if (this->unk_170 != 0) {
        ref_func_80A9D1E0(this, ref_func_80A9D0A0, (this->unk_164 - this->dyna.actor.home.pos.y) + 100.0f, 0x3C,
                      CutsceneManager_GetAdditionalCsId(this->dyna.actor.csId));
        return;
    }

    for (i = 0; i < ref_D_80A9E028.count; i++) {
        collider = ref_D_80A9E028.unk_0000[i].collider;
        if ((collider != NULL) && (collider->base.acFlags & AC_HIT) && (ref_D_80A9E028.unk_0000[i].unk_34 == 1)) {
            temp_f2 = this->unk_16C;
            yDiff = ABS_ALT(BINANG_SUB(this->dyna.actor.yawTowardsPlayer, player->actor.shape.rot.y));
            temp_f0 = temp_f2 + ref_D_80A9E028.unk_0000[i].unk_14.y;
            if ((yDiff > 0x5000) && ((temp_f0 - 60.0f) < player->actor.world.pos.y) &&
                (player->actor.world.pos.y < ((temp_f0 + ref_D_80A9D880[ref_D_80A9E028.unk_0000[i].unk_00].unk_00) - 70.0f))) {
                ref_D_80A9E028.unk_0000[i].unk_20 = 20.0f;
                temp = (s16)(this->dyna.actor.yawTowardsPlayer + 0x58F0);
                ref_D_80A9E028.unk_0000[i].unk_28 = ((s16)(player->actor.shape.rot.y - temp) / 3) + temp;
                ref_D_80A9E028.unk_0000[i].unk_34 = 2;
                Player_PlaySfx(player, NA_SE_IT_HAMMER_HIT);
                Audio_PlaySfx_2(NA_SE_EV_SLIDE_DOOR_OPEN);
                Flags_SetSwitch(play, ref_D_80A9E028.unk_0000[i].switchFlag);
                this->unk_178 = 20;
                ref_func_80A9D2C4(this, ref_func_80A9CE00, ref_D_80A9E028.unk_0000[i].unk_14.y + 50.0f, ref_D_80A9E028.unk_0000[i].csId,
                              ref_D_80A9E028.unk_0000[i].additionalCsId);
                break;
            }
        }
    }

    for (i = 0; i < ref_D_80A9E028.count; i++) {
        collider = ref_D_80A9E028.unk_0000[i].collider;
        if (collider != NULL) {
            collider->base.acFlags &= ~AC_HIT;
        }
    }

    if (this->unk_178 <= 0) {
        ref_func_80A9AEB8(this, play, &ref_D_80A9E028);
    }
}
