#include "types.h"

typedef struct { u8 pad0[0x30]; f32 x, y, z; } Mtxf3;

extern Mtxf3 *Matrix_GetCurrent(void);
extern u8 *Actor_SpawnAsChild(u8 *, u8 *, u8 *, s32, f32, f32, f32, s32, s32, s32, s32);
extern void Matrix_MtxFToYXZRot(Mtxf3 *, u8 *, s32);
extern void Math_Vec3f_Copy(u8 *, u8 *);

void Actor_SpawnBodyParts(u8 *actor, u8 *play, s32 arg2, s32 *arg3) {
    s32 pad;
    u8 *part;
    Mtxf3 *v;

    if (*arg3 != 0) {
        v = Matrix_GetCurrent();
        part = Actor_SpawnAsChild(play + 0x1CA0, actor, play, 3, v->x, v->y, v->z, 0, 0, *(s8 *)(actor + 0x1E), arg2);
        if (part != 0) {
            Matrix_MtxFToYXZRot(v, part + 0xBC, 0);
            *(s32 *)(part + 0x150) = *arg3;
            Math_Vec3f_Copy(part + 0x58, actor + 0x58);
        }
    }
}
