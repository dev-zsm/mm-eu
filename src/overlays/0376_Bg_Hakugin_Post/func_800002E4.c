// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_bg_hakugin_post.h"

void ref_func_80A9AFB4(BgHakuginPost* this, PlayState* play, BgHakuginPostUnkStruct* unkStruct) {
    s32 i;
    s32 j;

    if (unkStruct->count < ARRAY_COUNT(unkStruct->unk_0000)) {
        for (i = 0; i < unkStruct->count; i++) {
            if ((unkStruct->unk_0000[i].unk_34 == 0) ||
                (this->dyna.actor.world.pos.y < unkStruct->unk_0000[i].unk_08.y)) {
                for (j = 10; j >= i; j--) {
                    bcopy(&unkStruct->unk_0000[j], &unkStruct->unk_0000[j + 1], sizeof(BgHakuginPostUnkStruct1));
                }
                break;
            }
        }

        unkStruct->unk_0000[i].unk_00 = BGHAKUGINPOST_GET_7(&this->dyna.actor);
        Math_Vec3f_Copy(&unkStruct->unk_0000[i].unk_08, &this->dyna.actor.world.pos);
        Math_Vec3f_Copy(&unkStruct->unk_0000[i].unk_14, &this->dyna.actor.world.pos);
        unkStruct->unk_0000[i].switchFlag = BGHAKUGINPOST_GET_SWITCH_FLAG(&this->dyna.actor);
        if (ref_D_80A9D880[unkStruct->unk_0000[i].unk_00].unk_04) {
            if (Flags_GetSwitch(play, unkStruct->unk_0000[i].switchFlag)) {
                unkStruct->unk_0000[i].unk_34 = 5;
            } else {
                unkStruct->unk_0000[i].unk_34 = 1;
            }
            unkStruct->unk_0000[i].csId = this->dyna.actor.csId;
            unkStruct->unk_0000[i].additionalCsId = CutsceneManager_GetAdditionalCsId(unkStruct->unk_0000[i].csId);
        } else {
            unkStruct->unk_0000[i].unk_34 = 1;
            unkStruct->unk_0000[i].csId = CS_ID_NONE;
            unkStruct->unk_0000[i].additionalCsId = CS_ID_NONE;
        }

        unkStruct->unk_0000[i].unk_2F = 1;
        unkStruct->count++;
    }
}
