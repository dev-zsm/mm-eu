#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    Vec3f pos;
    Vec3s rot;
} PosRot;

typedef struct {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad2[0x22];
    /* 0x24 */ Vec3f pos;
    /* 0x30 */ u8 pad30[0x2C];
    /* 0x5C */ f32 unk5C;
    /* 0x60 */ u8 pad60[0x5C];
    /* 0xBC */ Vec3s rot;
    /* 0xC2 */ u8 padC2[0x9FE];
    /* 0xAC0 */ f32 unkAC0;
} Actor;

extern void Math_Vec3f_Copy(Vec3f *, Vec3f *);

PosRot *Actor_GetWorldPosShapeRot(PosRot *a0, Actor *a1) {
    PosRot out;

    Math_Vec3f_Copy(&out.pos, &a1->pos);
    if (a1->id == 0) {
        out.pos.y += a1->unkAC0 * a1->unk5C;
    }
    out.rot = a1->rot;
    *a0 = out;
    return a0;
}
