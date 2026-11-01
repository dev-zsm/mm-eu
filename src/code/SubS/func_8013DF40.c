#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;
typedef struct {
    u8 pad0[0x830];
    u8 colCtx[1];
} Play;
s32 BgCheck_EntityLineTest1(void *colCtx, Vec3f *a1, Vec3f *a2, Vec3f *a3, s32 *a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 *a9);
s32 SubS_IsFloorAbove(Play *play, Vec3f *pos, f32 yOffset) {
    s32 sp64;
    Vec3f sp58;
    Vec3f sp4C;
    Vec3f sp40;
    s32 sp3C;
    Vec3f sp30;
    sp30 = *pos;
    sp4C = sp30; sp58 = sp30;
    sp4C.y += yOffset;
    return BgCheck_EntityLineTest1(&play->colCtx, &sp58, &sp4C, &sp40, &sp64, 0, 1, 0, 1, &sp3C);
}
