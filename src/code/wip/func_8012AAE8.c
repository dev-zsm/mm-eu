// FLAGS: -O2 -g3 -mips2
#include "types.h"
typedef struct {
    s16 unk0;
    u8 pad2[2];
    void *unk4;
    void *unk8;
    u8 pad0C[0x10];
    s16 unk1C;
    s16 unk1E;
    s16 unk20;
    u8 pad22[2];
} Quake;
typedef struct { u8 pad[0x164]; s16 unk164; } Cam;
extern Quake D_801ED280[];
extern s16 D_801C1B84;
s16 Quake_GetFreeIndex(void);
void func_80096A20(void *, s32, s32);
f32 func_8008704C(Cam *);
s32 Quake_RequestImpl(Cam *cam, void *arg1) {
    s16 idx;
    Quake *q;
    idx = Quake_GetFreeIndex();
    q = &D_801ED280[idx];
    func_80096A20(q, 0, 0x24);
    q->unk4 = cam;
    q->unk20 = cam->unk164;
    q->unk8 = arg1;
    q->unk1C = 1;
    q->unk0 = (s16)((s32)(func_8008704C(cam) * 65536.0f) & 0xFFFC) + idx;
    D_801C1B84 += 1;
}
