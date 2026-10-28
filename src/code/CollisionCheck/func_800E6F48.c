#include "types.h"

typedef struct { u8 pad0[0x12]; u8 f12; u8 pad13[0x1C]; u8 f2F; u8 pad30[0x18]; u8 sph[1]; } Col;
void CollisionCheck_SetOCvsOC(s32 play, Col *a, void *b, void *c, Col *d, void *e, void *f, f32 g);
void Math_Vec3s_ToVec3f(void *a, void *b);
s32 Math3D_SphVsSphOverlap(void *a, void *b, f32 *c);

void CollisionCheck_OC_SphereVsSphere(s32 play, s32 unused, Col *a, Col *b) {
    u8 *pa;
    u8 *pb;
    f32 sp54;
    f32 sp48[3];
    f32 sp3C[3];
    if ((a->f12 & 1) && (a->f2F & 1) && (b->f12 & 1)) {
        pb = (u8 *)b + 0x48;
        pa = (u8 *)a + 0x48;
        if (b->f2F & 1) {
            if (Math3D_SphVsSphOverlap(pa, pb, &sp54) != 0) {
                Math_Vec3s_ToVec3f(sp48, pa);
                Math_Vec3s_ToVec3f(sp3C, pb);
                CollisionCheck_SetOCvsOC(play, a, (u8 *)a + 0x18, sp48, b, (u8 *)b + 0x18, sp3C, sp54);
            }
        }
    }
}
