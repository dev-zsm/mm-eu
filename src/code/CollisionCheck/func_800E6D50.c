// FLAGS: -O2 -g3 -mips2
#include "types.h"

extern s32 Math3D_CylVsCylOverlap(void *a, void *b, f32 *c);
extern void Math_Vec3s_ToVec3f(void *a, void *b);
extern void CollisionCheck_SetOCvsOC(s32 a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6, f32 a7);

typedef struct {
    u8 pad0[0x12];
    u8 flags12;
    u8 pad13[0x1C];
    u8 flags2F;
    u8 pad30[0x10];
    u8 pos40[6];
    u8 pos46[1];
} Col;

void CollisionCheck_OC_CylVsCyl(s32 a0, s32 a1, Col *a2, Col *a3) {
    s32 pad[2];
    f32 sp4C;
    u8 sp40[12];
    u8 sp34[12];

    if ((a2->flags12 & 1) && (a3->flags12 & 1) && (a2->flags2F & 1) && (a3->flags2F & 1)) {
        if (Math3D_CylVsCylOverlap(a2->pos40, a3->pos40, &sp4C) != 0) {
            Math_Vec3s_ToVec3f(sp40, a2->pos46);
            Math_Vec3s_ToVec3f(sp34, a3->pos46);
            CollisionCheck_SetOCvsOC(a0, a2, (u8 *)a2 + 0x18, sp40, a3, (u8 *)a3 + 0x18, sp34, sp4C);
        }
    }
}
