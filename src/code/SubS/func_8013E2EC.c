#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Fn8013E2ECVec;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Fn8013E2ECVecS;

typedef struct {
    u8 pad0[8];
    Fn8013E2ECVecS *unk8;
    u8 padC[4];
    s32 unk10;
    u8 pad14[0xC];
    Fn8013E2ECVec unk20;
    Fn8013E2ECVec unk2C;
    u8 pad38[0xC];
    Fn8013E2ECVec *unk44;
    u8 pad48[4];
    f32 unk4C;
    f32 unk50;
    s16 unk54;
    s16 unk56;
    s16 unk58;
} Fn8013E2ECObj;

float sqrtf(float);
#pragma intrinsic (sqrtf)

extern f32 Math3D_Dist1DSq(f32, f32);
extern f32 Math3D_Vec3fMagnitudeSq(Fn8013E2ECVec *);
extern s16 Math_Atan2S_XY(f32, f32);

void SubS_ActorPathing_ComputePointInfo(s32 arg0, Fn8013E2ECObj *arg1) {
    Fn8013E2ECVec sp2C;
    Fn8013E2ECVecS *v;

    v = arg1->unk8 + arg1->unk10;
    arg1->unk20.x = v->x + arg1->unk2C.x;
    arg1->unk20.y = v->y + arg1->unk2C.y;
    arg1->unk20.z = v->z + arg1->unk2C.z;
    sp2C.x = arg1->unk20.x - arg1->unk44->x;
    sp2C.y = arg1->unk20.y - arg1->unk44->y;
    sp2C.z = arg1->unk20.z - arg1->unk44->z;
    arg1->unk4C = Math3D_Dist1DSq(sp2C.x, sp2C.z);
    arg1->unk50 = Math3D_Vec3fMagnitudeSq(&sp2C);
    arg1->unk56 = Math_Atan2S_XY(sp2C.z, sp2C.x);
    arg1->unk54 = Math_Atan2S_XY(sqrtf(arg1->unk4C), -sp2C.y);
    arg1->unk58 = 0;
}
