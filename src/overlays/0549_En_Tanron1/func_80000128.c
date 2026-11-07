// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_en_tanron1.h"

void EnTanron1_Update(Actor* thisx, PlayState* play) {
    EnTanron1* this = (EnTanron1*)thisx;
    Actor* temp_a0;
    Player* player = GET_PLAYER(play);
    s16 i;
    EnTanron1Struct* ptr = &this->unk_160[0];
    Vec3f temp;
    f32 phi_f18;
    s32 pad;

    if (this->unk_148 != 0) {
        this->unk_148--;
    }

    switch (this->unk_144) {
        case 0:
            for (i = 0; i < this->actor.params; i++) {
                ref_func_80BB4E50(this->unk_160, &this->actor.world.pos, Rand_ZeroFloat(0x10000));
            }
            this->unk_144 = 200;
            break;

        case 1:
            this->unk_14C.x = player->actor.world.pos.x;
            this->unk_14C.y = player->actor.world.pos.y + 60.0f;
            this->unk_14C.z = player->actor.world.pos.z;
            if (this->unk_148 != 0) {
                ref_func_80BB4E50(this->unk_160, &this->actor.world.pos, this->actor.world.rot.y);
            }
            this->unk_158 = 0x1000;
            this->unk_15C = 150.0f;
            break;

        case 100:
            phi_f18 = 10.0f;

            while (phi_f18 < 1000.0f) {
                temp_a0 = play->actorCtx.actorLists[ACTORCAT_PROP].first;
                while (temp_a0 != NULL) {
                    if (temp_a0->id != ACTOR_OBJ_SYOKUDAI) {
                        temp_a0 = temp_a0->next;
                        continue;
                    }

                    temp.x = this->unk_14C.x - temp_a0->world.pos.x;
                    temp.y = this->unk_14C.y - temp_a0->world.pos.y + 70.0f;
                    temp.z = this->unk_14C.z - temp_a0->world.pos.z;

                    if (sqrtf(SQXYZ(temp)) < phi_f18) {
                        this->unk_14C.x = temp_a0->world.pos.x;
                        this->unk_14C.y = temp_a0->world.pos.y + 70.0f;
                        this->unk_14C.z = temp_a0->world.pos.z;
                        goto end;
                    }
                    temp_a0 = temp_a0->next;
                }
                phi_f18 += 20.0f;
            }
        end:
            break;

        case 200:
            this->unk_14C = this->actor.world.pos;
            this->unk_158 = 0x5000;
            this->unk_15C = 50.0f;
            break;

        case 250:
            for (i = 0; i < ARRAY_COUNT(this->unk_160); i++, ptr++) {
                if ((ptr->unk_24 != 0) && (ptr->unk_28 < 8)) {
                    ptr->unk_28 = 8;
                    ptr->unk_24 = 2;
                }
            }
            this->unk_144 = 1;
            break;

        default:
            break;
    }

    if ((player->heldItemAction == PLAYER_IA_DEKU_STICK) && (player->unk_B28 != 0)) {
        this->unk_14C.x = player->meleeWeaponInfo[0].tip.x;
        this->unk_14C.y = player->meleeWeaponInfo[0].tip.y;
        this->unk_14C.z = player->meleeWeaponInfo[0].tip.z;

        this->unk_158 = 0x5000;
        this->unk_15C = 50.0f;
        if (this->unk_144 != 1) {
            this->unk_144 = 100;
        }
    } else {
        temp_a0 = play->actorCtx.actorLists[ACTORCAT_EXPLOSIVES].first;
        while (temp_a0 != NULL) {
            if (temp_a0->params == 1) {
                temp_a0 = temp_a0->next;
                continue;
            }

            this->unk_14C.x = temp_a0->world.pos.x;
            this->unk_14C.y = temp_a0->world.pos.y + 50.0f;
            this->unk_14C.z = temp_a0->world.pos.z;

            this->unk_15C = 150.0f;
            this->unk_158 = 0x1000;
            if (this->unk_144 != 1) {
                this->unk_144 = 100;
            }
            break;
        }
    }
    ref_func_80BB5318(this, play);
}
