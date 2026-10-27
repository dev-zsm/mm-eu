#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    u32 unk0;
    u8 pad4[0xDC];
    u8 unkE0[1];
    u8 padE1[0x1702E - 0xE1];
    s8 lightDir[3];
} PlayState;

extern void Hilite_DrawOpa(void *arg0, void *arg1, Vec3f *lightDir, u32 arg3);

void func_800BC978(void *arg0, PlayState *play) {
    Vec3f lightDir;

    lightDir.x = play->lightDir[0];
    lightDir.y = play->lightDir[1];
    lightDir.z = play->lightDir[2];
    Hilite_DrawOpa(arg0, play->unkE0, &lightDir, play->unk0);
}
