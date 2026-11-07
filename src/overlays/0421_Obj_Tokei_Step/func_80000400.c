// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_tokei_step.h"

s32 ObjTokeiStep_OpenProcess(ObjTokeiStep* this, PlayState* play) {
    Actor* thisx = &this->dyna.actor;
    s32 i;
    ObjTokeiStepPanel* panel;
    f32 finalPosY;
    s32 isOpen = true;
    s32 hasPrevBounced = true;

    for (i = 0; i < ARRAY_COUNT(this->panels); i++) {
        panel = &this->panels[i];
        if (hasPrevBounced && (panel->startFallingTimer > 0)) {
            panel->startFallingTimer--;
            isOpen = false;
        }
        if (hasPrevBounced && (panel->numBounces < 3) && (panel->startFallingTimer <= 0)) {
            finalPosY = sPanelXOffsets[i] + this->dyna.actor.world.pos.y;
            if (!panel->hasSoundPlayed) {
                Actor_PlaySfx(&this->dyna.actor, NA_SE_EV_CLOCK_TOWER_STAIR_MOVE);
                panel->hasSoundPlayed = true;
            }
            panel->posChangeY += -2.5f;
            panel->posChangeY *= 0.83f;
            panel->pos.y += panel->posChangeY;
            isOpen = false;
            if (panel->pos.y < finalPosY) {
                panel->numBounces++;
                if (panel->numBounces >= 3) {
                    panel->pos.y = finalPosY;
                } else {
                    panel->posChangeY *= -0.4f;
                    if (panel->posChangeY > 4.0f) {
                        panel->posChangeY = 4.0f;
                    }
                    panel->pos.y = (panel->pos.y - finalPosY) * -0.4f;
                    if (panel->posChangeY < panel->pos.y) {
                        panel->pos.y = panel->posChangeY + finalPosY;
                    } else {
                        panel->pos.y += finalPosY;
                    }
                    if (panel->numBounces == 1) {
                        ObjTokeiStep_SpawnDust(this, panel, play);
                        ObjTokeiStep_RequestQuakeAndRumble(this, play);
                    }
                }
            }
        }
        hasPrevBounced = panel->numBounces > 0;
    }
    return isOpen;
}
