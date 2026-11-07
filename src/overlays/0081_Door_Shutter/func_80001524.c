// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_door_shutter.h"

void DoorShutter_Draw(Actor* thisx, PlayState* play) {
    s32 pad;
    DoorShutter* this = (DoorShutter*)thisx;
    ShutterInfo* sp44;

    if (ref_func_808A1D68(this, play)) {
        sp44 = &ref_D_808A21B0[this->unk_164];

        OPEN_DISPS(play->state.gfxCtx);

        Gfx_SetupDL25_Opa(play->state.gfxCtx);

        if (this->unk_164 == 7) {
            Matrix_Translate(0.0f, 64.96f, 0.0f, MTXMODE_APPLY);
            Matrix_RotateZS(this->slidingDoor.dyna.actor.home.rot.z, MTXMODE_APPLY);
            Matrix_Translate(0.0f, -64.96f, 0.0f, MTXMODE_APPLY);
        }

        if (sp44->unk_04 != 0) {
            TransitionActorEntry* transitionEntry =
                &play->transitionActors.list[DOOR_GET_TRANSITION_ID(&this->slidingDoor.dyna.actor)];

            if ((play->roomCtx.prevRoom.num >= 0) ||
                (transitionEntry->sides[0].room == transitionEntry->sides[1].room)) {
                s16 yaw = this->slidingDoor.dyna.actor.shape.rot.y -
                          Math_Vec3f_Yaw(&play->view.eye, &this->slidingDoor.dyna.actor.world.pos);

                if (ABS_ALT(yaw) < 0x4000) {
                    Matrix_RotateYF(M_PIf, MTXMODE_APPLY);
                }
            } else if (this->slidingDoor.dyna.actor.room == transitionEntry->sides[0].room) {
                Matrix_RotateYF(M_PIf, MTXMODE_APPLY);
            }
        } else if (this->doorType == DOORSHUTTER_TYPE_BOSS_DOOR) {
            gSPSegment(POLY_OPA_DISP++, 0x08, Lib_SegmentedToVirtual(ref_D_808A22DC[this->slidingDoor.unk_15E]));
        }

        MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
        gSPDisplayList(POLY_OPA_DISP++, sp44->unk_00);

        if ((this->unk_168 != 0.0f) && (sp44->unk_04 != 0)) {
            Matrix_Translate(0.0f, sp44->unk_08 * (1.0f - this->unk_168), sp44->translateZ, MTXMODE_APPLY);

            MATRIX_FINALIZE_AND_LOAD(POLY_OPA_DISP++, play->state.gfxCtx);
            gSPDisplayList(POLY_OPA_DISP++, sp44->unk_04);
        }

        if (this->unk_166 != 0) {
            Matrix_Scale(0.01f, 0.01f, 0.025f, MTXMODE_APPLY);
            Actor_DrawDoorLock(play, this->unk_166,
                               (this->doorType == DOORSHUTTER_TYPE_BOSS_DOOR) ? DOORLOCK_BOSS : DOORLOCK_NORMAL);
        }

        CLOSE_DISPS(play->state.gfxCtx);
    }
}
