#include "types.h"
#include "generated/code_funcs.h"

typedef struct { u8 pad0[0x30]; f32 x, y, z; } Mtxf3;

extern u8 *Actor_SpawnAsChild(u8 *, u8 *, u8 *, s32, f32, f32, f32, s32, s32, s32, s32);
extern void Math_Vec3f_Copy(u8 *, u8 *);

void Actor_SpawnBodyParts(struct Actor *actor, struct PlayState *play, s32 partParams, union Gfx **dList) {
    s32 pad;
    u8 *part;
    Mtxf3 *v;

    if (*dList != 0) {
        v = Matrix_GetCurrent();
        part = Actor_SpawnAsChild((u8 *)play + 0x1CA0, actor, play, 3, v->x, v->y, v->z, 0, 0, *(s8 *)((u8 *)actor + 0x1E), partParams);
        if (part != 0) {
            Matrix_MtxFToYXZRot(v, part + 0xBC, 0);
            *(s32 *)(part + 0x150) = *dList;
            Math_Vec3f_Copy(part + 0x58, (u8 *)actor + 0x58);
        }
    }
}
