#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;

extern Vec3f D_801E58B8;
extern Vec3f D_801E58C4;
extern s32 Math3D_LineVsSph(void *a);

s32 CollisionCheck_LineOC_Sphere(void *play, void *cc, u8 *col, Vec3f *a, Vec3f *b) {
    if (col[0x2F] & 1) {
        D_801E58B8 = *a;
        D_801E58C4 = *b;
        if (Math3D_LineVsSph(col + 0x48)) {
            return 1;
        }
    }
    return 0;
}
