// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_spidertent.h"

void ref_func_80B30AF8(ObjSpidertent* this, PlayState* play) {
    ObjSpidertentStruct* temp_s0 = &ref_D_80B31350[OBJSPIDERTENT_GET_1(&this->dyna.actor)];
    s32 i;
    s32 j;
    s32 pad;

    this->unk_3C6++;

    if (this->unk_3C6 < 40) {
        if (this->unk_3C2 > 2) {
            this->unk_3C2 -= 2;
        } else {
            this->unk_3C2 = 0;
        }

        if (this->unk_3C3 > 5) {
            this->unk_3C3 -= 5;
        } else {
            this->unk_3C3 = 0;
        }

        if (this->unk_3C4 > 5) {
            this->unk_3C4 -= 5;
        } else {
            this->unk_3C4 = 0;
        }

        if (this->unk_3C5 > 1) {
            this->unk_3C5--;
        } else {
            this->unk_3C5 = 0;
        }
    } else {
        if (this->unk_3C2 > 4) {
            this->unk_3C2 -= 4;
        } else {
            this->unk_3C2 = 0;
        }

        if (this->unk_3C3 < 255) {
            this->unk_3C3++;
        } else {
            this->unk_3C3 = 255;
        }

        if (this->unk_3C4 < 255) {
            this->unk_3C4++;
        } else {
            this->unk_3C4 = 255;
        }

        if (this->unk_3C5 > 10) {
            this->unk_3C5 -= 10;
        } else {
            this->unk_3C5 = 0;
        }
    }

    this->unk_3C1--;
    if (this->unk_3C1 == 40) {
        DynaPoly_DisableCollision(play, &play->colCtx.dyna, this->dyna.bgId);
    }

    if (this->unk_3C1 >= 32) {
        if (this->unk_3C7 > 0) {
            this->unk_3C7--;
        } else if (this->unk_3C1 > 50) {
            Actor_PlaySfx(&this->dyna.actor, NA_SE_EN_EXTINCT);
            this->unk_3C7 = Rand_S16Offset(2, 2);
        } else {
            SoundSource_PlaySfxAtFixedWorldPos(play, &this->dyna.actor.world.pos, 11, NA_SE_EN_EXTINCT);
            this->unk_3C7 = Rand_S16Offset(2, 4);
        }

        for (j = 0; j < ARRAY_COUNT(this->unk_3B0); j++) {
            this->unk_3B0[j] += ref_D_80B313A0[j].unk_04;
            if (temp_s0->unk_20 < this->unk_3B0[j]) {
                this->unk_3C0 |= (1 << j);
            }
        }

        for (i = 0; i < ARRAY_COUNT(this->colliderElements); i++) {
            TriNorm* triNorm = &this->collider.elements[i].dim;
            Vec3f sp60;
            f32 sp5C;

            for (j = 0; j < ARRAY_COUNT(this->unk_3B0); j++) {
                if ((this->unk_3B0[j] < 5.0f) || (this->unk_3C0 & (1 << j))) {
                    continue;
                }
                if (ref_func_80B2FB94(&this->unk_3A4, this->unk_3B0[j], triNorm, &sp60, &sp5C)) {
                    ref_func_80B300F4(this, play, triNorm, &sp60, sp5C, j);
                }
            }
        }
    } else if (this->unk_3C1 <= 0) {
        CutsceneManager_Stop(this->dyna.actor.csId);
        Actor_Kill(&this->dyna.actor);
    }
}
