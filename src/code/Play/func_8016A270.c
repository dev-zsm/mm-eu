#include "types.h"

typedef struct {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3f;

typedef struct {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
} Mtx4;

extern f32 BgCheck_EntityRaycastFloor3();
extern void func_800BFE24(s32, s32, f32, s32, void *);

f32 Play_GetFloorSurfaceImpl(u8 *play, Mtx4 *m, s32 *poly, s32 bgId, Vec3f *pos) {
    f32 y = BgCheck_EntityRaycastFloor3(play + 0x830, poly, bgId, pos);

    if (y > -32000.0f) {
        func_800BFE24(*poly, *(s32 *)&pos->x, y, *(s32 *)&pos->z, m);
    } else {
        m->unk10 = 0.0f;
        m->unk8 = 0.0f;
        m->unk4 = 0.0f;
        m->unk0 = 0.0f;
        m->unk2C = 0.0f;
        m->unk20 = 0.0f;
        m->unk1C = 0.0f;
        m->unkC = 0.0f;
        m->unk28 = 0.0f;
        m->unk24 = 0.0f;
        m->unk18 = 0.0f;
        m->unk14 = 1.0f;
        m->unk30 = pos->x;
        m->unk34 = pos->y;
        m->unk38 = pos->z;
        m->unk3C = 1.0f;
    }
    return y;
}
