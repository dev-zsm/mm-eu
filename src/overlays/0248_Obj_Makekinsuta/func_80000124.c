// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_makekinsuta.h"

void ref_func_8099FB64(Actor* thisx, PlayState* play) {
    s32 pad[0x2];
    Actor* actor;
    Vec3f destVec;
    s16 rotY;
    f32 speedXZ;
    s32 rotCheck;
    static Vec3f ref_D_8099FE3C = { 0.0f, 1.0f, 0.0f };

    rotCheck = thisx->shape.rot.x == 0;
    if (rotCheck) {
        rotCheck = thisx->shape.rot.z == 0;
    }

    if (rotCheck) {
        rotY = thisx->shape.rot.y;
    } else {
        Matrix_RotateYS(thisx->shape.rot.y, MTXMODE_NEW);
        Matrix_RotateXS(thisx->shape.rot.x, MTXMODE_APPLY);
        Matrix_RotateZS(thisx->shape.rot.z, MTXMODE_APPLY);
        Matrix_MultVec3f(&ref_D_8099FE3C, &destVec);
        rotY = Math_Atan2S_XY(destVec.z, destVec.x);
    }
    actor = Actor_Spawn(&play->actorCtx, play, ACTOR_EN_SW, thisx->world.pos.x, thisx->world.pos.y, thisx->world.pos.z,
                        0, rotY, 0, (OBJMAKEKINSUTA_GET_1F(thisx) << 2) | 0xFF01);
    if (actor != NULL) {
        actor->parent = thisx;
        if (rotCheck) {
            actor->velocity.y = 10.0f;
            actor->speed = 3.0f;
        } else {
            speedXZ = sqrtf((destVec.x * destVec.x) + (destVec.z * destVec.z));
            actor->velocity.y = (4 * destVec.y) + 4.0f;
            actor->speed = (2 * speedXZ) + 2.0f;
        }
    }
}
