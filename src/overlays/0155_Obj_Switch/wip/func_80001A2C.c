// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
// STATUS: reference draft (ObjSwitch_Update), score 4.00 (6 differ, size +1)
#include "generated/mm/z_obj_switch.h"

void func_80001A2C(Actor* thisx, PlayState* play) {
    ObjSwitch* this = (ObjSwitch*)thisx;

    if (this->floorSwitchReleaseTimer > 0) {
        this->floorSwitchReleaseTimer--;
    }
    if (this->sfxTimer > 0) {
        this->sfxTimer--;
    }
    this->actionFunc(this, play);
    if (this->floorSwitchPlayerSnapState != 0) {
        s32 requiredScopeTemp;

        ObjSwitch_FloorSwitchSnapPlayerToSwitchEdge(this, play);
        if (this->floorSwitchPlayerSnapState == 2) {
            this->floorSwitchPlayerSnapState = 0;
        }
    }

    switch (OBJ_SWITCH_GET_TYPE(&this->dyna.actor)) {
        case OBJSWITCH_TYPE_FLOOR:
        case OBJSWITCH_TYPE_FLOOR_RUSTY:
        case OBJSWITCH_TYPE_FLOOR_LARGE:
            this->collisionFlags = this->dyna.interactFlags;
            break;

        case OBJSWITCH_TYPE_EYE:
            this->collisionFlags = this->colliderTris.base.acFlags;
            this->colliderTris.base.acFlags &= ~AC_HIT;
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderTris.base);
            break;

        case OBJSWITCH_TYPE_CRYSTAL:
        case OBJSWITCH_TYPE_CRYSTAL_TARGETABLE:
            if (!Player_InCsMode(play)) {
                if (this->disableCrystalSwitchTimer > 0) {
                    this->disableCrystalSwitchTimer--;
                }
            }
            if (this->disableCrystalSwitchTimer == 0) {
                this->colliderJntSph.base.colMaterial = sJntSphInit.base.colMaterial;
            } else {
                this->colliderJntSph.base.colMaterial = COL_MATERIAL_NONE;
            }
            this->collisionFlags = this->colliderJntSph.base.acFlags;
            CollisionCheck_SetAC(play, &play->colChkCtx, &this->colliderJntSph.base);
            CollisionCheck_SetOC(play, &play->colChkCtx, &this->colliderJntSph.base);
            break;
    }
}
