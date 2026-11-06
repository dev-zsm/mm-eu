// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_chan.h"

void ObjChan_InitChandelier(ObjChan* this, PlayState* play) {
    Actor* thisx = &this->actor;
    s32 i;
    ObjChan* pot;
    Vec3f childPos;
    Vec3s childRot;
    CollisionPoly* sp94;
    s32 bgId;
    Vec3f sp84;

    Math_Vec3f_Copy(&this->unk1C0, &thisx->world.pos);

    Math_Vec3f_Copy(&sp84, &thisx->world.pos);
    sp84.y += 1600.0f;

    if (BgCheck_EntityLineTest1(&play->colCtx, &thisx->world.pos, &sp84, &this->unk1C0, &sp94, false, false, true, true,
                                &bgId)) {
        this->unk1CC = thisx->world.pos.y - this->unk1C0.y;
    } else {
        Actor_Kill(thisx);
        return;
    }

    for (i = 0; i < 5; i++) {
        ObjChan_CalculatePotPosition(&childPos, &childRot, &thisx->world.pos, &thisx->shape.rot,
                                     (s32)DEG_TO_BINANG_ALT3(i * 360.0f / 5.0f) + this->rotation);
        pot = (ObjChan*)Actor_SpawnAsChildAndCutscene(
            &play->actorCtx, play, ACTOR_OBJ_CHAN, childPos.x, childPos.y, childPos.z, childRot.x, childRot.y,
            childRot.z, (thisx->params & 0xFFF) | 0x1000, thisx->csId, thisx->halfDaysBits, thisx);
        if (pot != NULL) {
            this->pots[i] = pot;
            pot->myPotIndex = i;
            pot->actor.csId = thisx->csId;
        } else {
            Actor_Kill(thisx);
        }
    }

    if (Flags_GetSwitch(play, OBJCHAN_GET_SWITCH_FLAG(thisx))) {
        this->stateFlags |= OBJCHAN_STATE_FIRE_DELAY;
        this->stateFlags |= OBJCHAN_STATE_ON_FIRE;

        this->rotationSpeed = OBJCHAN_ROTATION_SPEED;
        this->flameSize = 1.0f;

        for (i = 0; i < 5; i++) {
            if (this->pots[i] != NULL) {
                this->pots[i]->stateFlags |= OBJCHAN_STATE_FIRE_DELAY;
                this->pots[i]->stateFlags |= OBJCHAN_STATE_ON_FIRE;
                this->pots[i]->flameSize = 1.0f;
            }
        }
    }
    this->collider.dim.radius = 45;
    this->collider.dim.height = 60;
    this->collider.dim.yShift = -20;
    this->actionFunc = ObjChan_ChandelierAction;
}
