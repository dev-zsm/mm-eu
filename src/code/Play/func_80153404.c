#include "types.h"

typedef struct {
    u8 pad0[0x24];
    s32 unk24;
    f32 unk28;
    f32 unk2C;
} Cam;
typedef struct {
    u8 pad0[0x1202C];
    u16 unk1202C;
    u8 pad1202E[2];
    u16 unk12030;
    u8 pad12032[0x82];
    u8 unk120B4;
} Sub;
typedef struct {
    u8 pad0[0x1CCC];
    Cam *cam;
} Play;
extern s16 D_801C8828[];
extern s32 D_801C8848[];
extern void Actor_Spawn(void *, void *, s16, s32, f32, f32, s32, s32, s32, s32);
void func_80153404(Play *play) {
    Sub *s = (Sub *) (((u8 *) play) + 0x4908);
    Cam *cam = play->cam;
    // one line: the ROM's scheduling depends on these stores sharing a single source line
    do { if ((s->unk1202C < 0x17) && (s->unk1202C != 0xE)) { if ((s->unk12030 < 0x43) || (s->unk12030 >= 0x47)) { s->unk120B4 = 1; if (0) { } if (s->unk1202C != 0x16) { Actor_Spawn(((u8 *) play) + 0x1CA0, play, D_801C8828[s->unk1202C], cam->unk24, cam->unk28, cam->unk2C, 0, 0, 0, D_801C8848[s->unk1202C]); return; } Actor_Spawn(((u8 *) play) + 0x1CA0, play, 0xF6, cam->unk24, cam->unk28, cam->unk2C, 0, 0, 0, 0); } } } while (0);
}
