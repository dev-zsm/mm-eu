// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chikuwa.h"

void ObjChikuwa_Update(Actor* thisx, PlayState* play) {
    ObjChikuwa* this = (ObjChikuwa*)thisx;
    ObjChikuwaStruct* temp;
    f32 temp_fs0;
    s16 quakeVerticalMag;
    s32 i;
    s32 quakeIndex;

    this->unk_29E++;

    for (i = 0; i < this->unk_29C; i++) {
        temp = &this->unk_15C[i];
        if ((this->unk_29E >= temp->unk_0C) && !(temp->unk_0E & 1)) {
            temp->unk_0E |= 1;
            this->unk_2A0++;
            ref_func_809B1550(&this->dyna.actor, play);
            ref_func_809B17D0(play, this, &temp->unk_00);
            temp_fs0 = Math3D_Vec3fDistSq(&temp->unk_00, &GET_PLAYER(play)->actor.world.pos);
            if (temp_fs0 < SQ(240.0f)) {
                quakeIndex = Quake_Request(GET_ACTIVE_CAM(play), QUAKE_TYPE_3);
                if (temp_fs0 < SQ(120.0f)) {
                    quakeVerticalMag = 4;
                } else {
                    quakeVerticalMag = 3;
                }

                Quake_SetSpeed(quakeIndex, 17232);
                Quake_SetPerturbations(quakeIndex, quakeVerticalMag, 0, 0, 0);
                Quake_SetDuration(quakeIndex, 7);
            }
        }
    }

    ref_func_809B1AA0(this);
}
