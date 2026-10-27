#include "types.h"

typedef struct { f32 x, y, z; } Vec3f;
typedef struct {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ Vec3f vel;
    /* 0x18 */ Vec3f accel;
    /* 0x24 */ void (*update)(void *a, s32 b, void *c);
    /* 0x28 */ u8 pad28[0x60 - 0x28];
} Effect; /* size 0x60 */

extern Effect *D_801AF260;

void EffectSs_Update(void *play, s32 index) {
    Effect *e = &D_801AF260[index];

    if (e->update != 0) {
        e->vel.x += e->accel.x;
        e->vel.y += e->accel.y;
        e->vel.z += e->accel.z;
        e->pos.x += e->vel.x;
        e->pos.y += e->vel.y;
        e->pos.z += e->vel.z;
        e->update(play, index, e);
    }
}
