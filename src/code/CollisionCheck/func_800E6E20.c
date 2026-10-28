#include "types.h"
typedef struct { f32 x, y, z; } Vec;
typedef struct { u8 pad0[0x12]; u8 flags12; u8 pad13[0x5]; Vec pos18; u8 pad24[0xB]; u8 flags2F; u8 pad30[0x10]; u8 vec40[6]; u8 vec46[2]; u8 mat48[1]; } Col;
extern s32 Math3D_SphVsCylOverlap(void *, void *, f32 *);
extern void Math_Vec3s_ToVec3f(void *, void *);
extern void CollisionCheck_SetOCvsOC(s32, void *, void *, void *, void *, void *, void *, f32);
void CollisionCheck_OC_CylVsSphere(s32 a0, s32 a1, Col *a, Col *b) {
    s32 pad[2]; // frame padding to match
    f32 f;
    Vec v1;
    Vec v2;

    if ((a->flags12 & 1) && (a->flags2F & 1) && (b->flags12 & 1) && (b->flags2F & 1)) {
        if (Math3D_SphVsCylOverlap(b->mat48, a->vec40, &f)) {
            Math_Vec3s_ToVec3f(&v1, a->vec46);
            Math_Vec3s_ToVec3f(&v2, b->mat48);
            CollisionCheck_SetOCvsOC(a0, a, &a->pos18, &v1, b, &b->pos18, &v2, f);
        }
    }
}
