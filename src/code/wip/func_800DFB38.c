#include "types.h"

typedef struct {
    f32 x;
    f32 y;
    f32 z;
} Vec3f;

typedef struct {
    /* 0x000 */ u8 pad0[0x50];
    /* 0x050 */ Vec3f unk50;
    /* 0x05C */ Vec3f unk5C;
    /* 0x068 */ Vec3f unk68;
    /* 0x074 */ Vec3f unk74;
    /* 0x080 */ u8 pad80[0x28];
    /* 0x0A8 */ Vec3f *unkA8;
    /* 0x0AC */ Vec3f unkAC;
    /* 0x0B8 */ u8 padB8[0x44];
    /* 0x0FC */ f32 unkFC;
    /* 0x100 */ u8 pad100[0x5A];
    /* 0x15A */ s16 unk15A;
    /* 0x15C */ s16 flags;
} Camera;

extern f32 D_801D563C;

// Differs from the ROM by one instruction: IDO hoists "or v0, zero, zero" into the delay slot of the NULL check.
s32 Camera_SetViewParam(Camera *camera, s32 param, Vec3f *value) {
    Vec3f tmp;
    s32 pad[4]; // frame size (0x20)

    if (value != NULL) {
        switch (param) {
            case 1:
                camera->flags &= 0xFFE6;
                camera->unk50 = *value;
                break;
            case 16:
                camera->flags &= 0xFFE6;
                camera->unkAC = *value;
                break;
            case 8:
                camera->unkA8 = value;
                camera->flags &= 0xFFE6;
                break;
            case 2:
                tmp = *value;
                camera->unk74 = tmp;
                camera->unk5C = tmp;
                break;
            case 4:
                camera->unk68 = *value;
                break;
            case 64:
                camera->unk15A = *(f32 *)value * D_801D563C + 0.5f;
                break;
            case 32:
                camera->unkFC = *(f32 *)value;
                break;
            default:
                return 0;
        }
        camera->flags |= param;
        return 1;
    } else {
        return 0;
    }
}
