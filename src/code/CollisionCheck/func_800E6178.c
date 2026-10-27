#include "types.h"
typedef struct S S;
struct S {
    u8 pad0[0x18];
    u8 unk18[0xE];
    u8 unk26[6];
    u8 pad2c[2];
    u8 unk2E;
    u8 pad2f[5];
    s32 unk34;
    u8 pad38[4];
    u8 *unk3C;
};
void Math_Vec3s_ToVec3f();
void CollisionCheck_HitEffects();
void CollisionCheck_SetSphereHitFX(s32 a0, s32 a1, S *s) {
    s32 pad[1]; // unused, only to match the frame size
    u8 sp28[12];
    u8 *t;
    if (s->unk2E & 0x80) {
        t = s->unk3C;
        if ((t != NULL) && !(t[0x15] & 0x40)) {
            Math_Vec3s_ToVec3f(sp28, s->unk26);
            CollisionCheck_HitEffects(a0, s->unk34, s->unk3C, s, s->unk18, sp28);
            s->unk3C[0x15] |= 0x40;
        }
    }
}
