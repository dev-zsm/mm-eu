// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    f32 unk0;
    s16 unk4;
    s16 unk6;
} VecGeo;

void OLib_VecSphToVec3f(void *, void *, void *);

void OLib_VecGeoToVec3f(void *arg0, VecGeo *arg1) {
    VecGeo sp18;

    sp18.unk0 = arg1->unk0;
    sp18.unk4 = 0x4000 - arg1->unk4;
    sp18.unk6 = arg1->unk6;
    OLib_VecSphToVec3f(arg0, &sp18, arg1);
}
