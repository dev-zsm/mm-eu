#include "types.h"

typedef struct { s16 a; u8 b; u8 c; u8 d; u8 e; u8 f; } FireInfo;
typedef struct { s32 node; u8 pad[0xE]; u8 type; } FireLight;
extern FireInfo D_801BE434[];
void Lights_PointGlowSetInfo(void *a, s16 x, s16 y, s16 z, s32 r, s32 g, s32 b, s32 rad);
s32 LightContext_InsertLight(s32 a, s32 b, void *c);

void FireObj_InitLight(s32 play, FireLight *light, u8 *params, f32 *pos) {
    FireInfo *info = &D_801BE434[*params];
    Lights_PointGlowSetInfo((u8 *)light + 4, pos[0], pos[1], pos[2], info->b, info->c, info->d, info->a);
    light->node = LightContext_InsertLight(play, play + 0x818, (u8 *)light + 4);
    light->type = *params;
}
