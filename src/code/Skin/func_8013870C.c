#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    s16 w;
} Vtx8;
typedef struct {
    u8 pad0[4];
    u8 unk4[0x44];
    u8 *unk48;
} SkinA;
extern void SkinMatrix_Vec3fMtxFMultXYZ(void *a, f32 *b, s32 c);
volatile unsigned int Skin_GetVertexPos(SkinA *arg0, s32 arg1, s32 arg2, s32 arg3) {
    f32 sp[3];
    u8 *p = arg0->unk48;
    s16 *v = (s16 *) ((*((u32 *) (((p + (arg1 * 12)) + ((*p) * 4)) + ((0, 4))))) + (arg2 * 16));
    s16 *new_var;
    sp[0] = v[0];
    new_var = &v[1];
    sp[1] = *new_var;
    sp[2] = v[2];
    SkinMatrix_Vec3fMtxFMultXYZ(arg0->unk4, sp, arg3);
}
