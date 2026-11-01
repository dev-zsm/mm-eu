// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    u8 pad0[0xE];
    s16 unkE;
} Cam;

extern s16 D_801E5280[4];
extern u8 D_801E5288[];
extern u8 D_801E52AC[];
extern u8 D_801E52B0[];
extern u8 D_801E52B4[];
extern f32 D_801E52B8;
void CollisionPoly_GetVertices(Cam *, void *);
void CollisionPoly_GetNormalF(Cam *, void *, void *, void *);
void Math3D_TriVsSphIntersect(void *, void *, void *);

void CollisionPoly_SphVsPoly(Cam *a0, s32 a1, Vec3f *a2, f32 a3) {
    u8 sp1C[12];

    CollisionPoly_GetVertices(a0, D_801E5288);
    CollisionPoly_GetNormalF(a0, D_801E52AC, D_801E52B0, D_801E52B4);
    D_801E52B8 = a0->unkE;
    D_801E5280[0] = a2->x;
    D_801E5280[1] = a2->y;
    D_801E5280[3] = a3;
    D_801E5280[2] = a2->z;
    Math3D_TriVsSphIntersect(D_801E5280, D_801E5288, sp1C);
}
