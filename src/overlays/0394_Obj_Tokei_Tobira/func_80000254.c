// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_tobira.h"

void ObjTokeiTobira_Update(Actor* thisx, PlayState* play) {
    s32 pad1;
    ObjTokeiTobira* this = (ObjTokeiTobira*)thisx;
    Player* player = GET_PLAYER(play);
    s32 pad2;
    s32 type = OBJTOKEITOBIRA_GET_TYPE(&this->dyna.actor);
    f32 sp48 = ref_D_80ABD778[type];
    s32 pad3;

    if (player->actor.bgCheckFlags & BGCHECKFLAG_PLAYER_WALL_INTERACT) {
        if (DynaPoly_GetActor(&play->colCtx, player->actor.wallBgId) == &this->dyna) {
            f32 sp40;
            Vec3f sp34;

            Actor_WorldToActorCoords(&this->dyna.actor, &sp34, &player->actor.world.pos);
            sp40 = sp34.x * sp48;

            if (sp40 > 20.0f) {
                if (sp34.z > 0.0f) {
                    this->unk160 += (sp40 - 20.0f) * sp48 * (16.0f / 3.0f);
                    this->unk168 = 1;
                    if (this->unk16C <= 0) {
                        Actor_PlaySfx(&this->dyna.actor, NA_SE_OC_WOOD_GATE_OPEN);
                        this->unk16C = 80;
                    }
                }

                if (sp40 > 48.0f) {
                    ObjTokeiTobira* tobira;

                    if (type == OBJTOKEITOBIRA_TYPE_0) {
                        tobira = (ObjTokeiTobira*)this->dyna.actor.child;
                    } else {
                        tobira = (ObjTokeiTobira*)this->dyna.actor.parent;
                    }

                    if (tobira != NULL) {
                        tobira->unk168 = 1;
                    }
                }
            }
        }
    } else if (this->unk168 == 1) {
        Vec3f sp24;

        Actor_WorldToActorCoords(&this->dyna.actor, &sp24, &player->actor.world.pos);

        if ((sp24.z > 0.0f) && (sp24.z < 30.0f)) {
            this->unk168 = 1;
            this->unk160 += sp48 * 290.0f;
        }
    }

    if (this->unk16C > 0) {
        this->unk16C--;
    }

    this->unk168 = 0;
    this->unk160 *= 0.87f;
    this->unk164 += this->unk160;
    if ((this->unk164 * sp48) > 14336.0f) {
        this->unk160 *= 0.1f;
        this->unk164 = 14336.0f * sp48;
    } else if ((this->unk164 * sp48) < -1000.0f) {
        this->unk160 *= 0.1f;
        this->unk164 = -1000.0f * sp48;
    }

    this->dyna.actor.shape.rot.y = (s32)this->unk164 + this->dyna.actor.home.rot.y;

    if (this->actionFunc != NULL) {
        this->actionFunc(this);
    }
}
