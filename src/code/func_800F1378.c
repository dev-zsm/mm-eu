#include "types.h"

typedef struct {
    u8 pad0[0x164];
    s16 unk164;
} CameraData;

typedef struct {
    u8 pad0[0x688];
    u8 unk688[0x164];
    s16 unk7EC;
} PlayState;

typedef struct {
    s16 unk0;
    u8 pad2[0xE];
    PlayState *play;
    u8 pad14[2];
    s16 unk16;
} CutsceneState;

extern CutsceneState D_801BE3E0;

void func_8008F3A8(void *dst, void *src, s32 size);
void func_800DE0B8(void *dst, s32 arg);

void CutsceneManager_StoreCamera(CameraData *camera) {
    if (camera != NULL) {
        func_8008F3A8(D_801BE3E0.play->unk688, camera, 0x178);
        D_801BE3E0.play->unk7EC = camera->unk164;
        func_800DE0B8(D_801BE3E0.play->unk688, 0x100);
        D_801BE3E0.unk16 = 1;
    }
}
