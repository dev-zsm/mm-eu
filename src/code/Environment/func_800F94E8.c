#include "types.h"

typedef struct {
    f32 x, y, z;
} Vec3f;

typedef struct {
    u32 unk0;
    u8 pad4[0x7FC];
    u8 *unk800[4];
    s16 unk810;
} Play;

extern u16 D_801E6EFC;
extern f32 Math_CosS(s16 a);
extern void Environment_DrawLensFlare(void *, void *, void *, u32, Vec3f, f32, f32, s32, s32);

void Environment_DrawSunLensFlare(Play *a0, s32 a1, s32 a2, s32 a3, Vec3f pos) {
    s32 t;
    if (*((u8 *)a0 + 0x170F7) == 0 && !(*(s16 *)(a0->unk800[a0->unk810] + 0x14C) & 0x100) &&
        *((u8 *)a0 + 0x18874) == 1) {
        t = D_801E6EFC;
        Environment_DrawLensFlare(a0, (u8 *)a0 + 0x17004, (u8 *)a0 + 0xB8, a0->unk0, pos, 370.0f,
                                  Math_CosS(t - 0x8000) * 120.0f, 0x190, 1);
    }
}
