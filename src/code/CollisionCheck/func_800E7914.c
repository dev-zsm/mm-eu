#include "types.h"

typedef struct {
    u8 pad0[0x2F];
    u8 unk2F;
    u8 pad30[0x10];
    u8 unk40[0x10];
} ColliderCyl7914;

extern u8 D_801E5828[];
extern u8 D_801E5838[];

s32 Math3D_CylVsLineSeg(void *, void *, void *, void *, void *);

s32 CollisionCheck_LineOC_Cyl(void *play, void *colCtx, ColliderCyl7914 *cyl, void *a, void *b) {
    if (!(cyl->unk2F & 1)) {
        return 0;
    }
    if (Math3D_CylVsLineSeg(cyl->unk40, a, b, D_801E5828, D_801E5838)) {
        return 1;
    }
    return 0;
}
