#include "types.h"
extern u8 D_801FFCF0[];
extern void AudioList_InitNoteLists(void *, s32, void *);
extern void AudioScript_ResetSequencePlayer(void *);
typedef struct {
    u8 f7 : 1;
    u8 f6 : 1;
    u8 f5 : 1;
    u8 f4 : 1;
    u8 f3 : 1;
    u8 f2 : 1;
    u8 f1 : 1;
    u8 f0 : 1;
    u8 pad1[2];
    u8 unk3;
    u8 pad4[0x28];
    f32 unk2C;
    u8 pad30[4];
    f32 unk34;
    void *unk38[16];
    u8 pad78[0x158 - 0x78];
    s8 unk158[8];
} X;
void func_8019BB7C(X *p) {
    s32 i;
    for (i = 0; i != 16; i += 4) {
        p->unk38[i + 1] = D_801FFCF0;
        p->unk38[i + 2] = D_801FFCF0;
        p->unk38[i + 3] = D_801FFCF0;
        p->unk38[i] = D_801FFCF0;
    }
    p->f7 = 0;
    p->f5 = 0;
    p->f3 = 0;
    p->f4 = 0;
    p->f0 = 0;
    for (i = 0; i != 8; i += 4) {
        p->unk158[i + 1] = -1;
        p->unk158[i + 2] = -1;
        p->unk158[i + 3] = -1;
        p->unk158[i] = -1;
    }
    p->unk3 = 0x60;
    p->unk2C = 1.0f;
    p->unk34 = 1.0f;
    AudioList_InitNoteLists((u8 *)p + 0x9C, 8, p);
    AudioScript_ResetSequencePlayer(p);
}
