// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_switch.h"

s32 ObjSwitch_IsEyeSwitchHit(ObjSwitch* this) {
    Actor* acActor;
    Actor* actor = &this->dyna.actor;

    if ((this->colliderTris.base.acFlags & AC_HIT) && !(this->collisionFlags & AC_HIT)) {
        acActor = this->colliderTris.base.ac;
        if (acActor != NULL) {
            Vec3f sp2C;
            Vec3f sp20;

            Matrix_Push();
            Matrix_RotateYS(acActor->world.rot.y, MTXMODE_NEW);
            Matrix_RotateXS(acActor->world.rot.x, MTXMODE_APPLY);
            Matrix_MultVecZ(1.0f, &sp2C);
            Matrix_RotateYS(actor->shape.rot.y, MTXMODE_NEW);
            Matrix_RotateXS(actor->shape.rot.x, MTXMODE_APPLY);
            Matrix_RotateZS(actor->shape.rot.z, MTXMODE_APPLY);
            Matrix_MultVecZ(1.0f, &sp20);
            Matrix_Pop();
            if ((Math3D_Cos(&sp2C, &sp20) < COS_OF_5_PI_DIV_8)) {
                return true;
            }
        }
    }
    return false;
}
