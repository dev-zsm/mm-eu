#include "types.h"

typedef struct {
    /* 0x0 */ u8 active;
    /* 0x1 */ u8 arg4;
    /* 0x2 */ u8 arg3;
    /* 0x3 */ u8 pad3;
} EffectInfo;

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ EffectInfo info;
    /* 0x08 */ u8 data[0x4C8 - 8];
} EffectSlotA;

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ EffectInfo info;
    /* 0x08 */ u8 data[0x1B0 - 8];
} EffectSlotB;

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ EffectInfo info;
    /* 0x08 */ u8 data[0x1CC - 8];
} EffectSlotC;

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ EffectInfo info;
    /* 0x08 */ u8 data[0x610 - 8];
} EffectSlotD;

typedef struct {
    /* 0x0000 */ EffectSlotA a[3];
    /* 0x0E58 */ EffectSlotB b[25];
    /* 0x3888 */ EffectSlotC c[3];
    /* 0x3DEC */ EffectSlotD d[15];
} EffectTable;

typedef struct {
    /* 0x00 */ void (*init)(void *data, void *initParams);
    /* 0x04 */ u8 pad4[0x10];
} EffectInit;

extern EffectTable D_801DB840;
extern EffectInit D_801AF1F4[];
extern s32 func_8016B1A4(void *play);

void Effect_Add(void *play, s32 *index, s32 type, u8 arg3, u8 arg4, void *initParams) {
    s32 pad[2]; // unused: pads the frame to the ROM size
    void *data = NULL;
    EffectInfo *info = NULL;
    s32 found;
    s32 i;

    *index = 0x2E;
    if (func_8016B1A4(play) == 1) {
        return;
    }
    found = 0;
    switch (type) {
        case 0:
            for (i = 0; i < 3; i++) {
                if (D_801DB840.a[i].info.active == 0) {
                    found = 1;
                    *index = i;
                    data = D_801DB840.a[i].data;
                    info = &D_801DB840.a[i].info;
                    break;
                }
            }
            break;
        case 1:
        case 2:
            for (i = 0; i < 25; i++) {
                if (D_801DB840.b[i].info.active == 0) {
                    found = 1;
                    *index = i + 3;
                    data = D_801DB840.b[i].data;
                    info = &D_801DB840.b[i].info;
                    break;
                }
            }
            break;
        case 3:
            for (i = 0; i < 3; i++) {
                if (D_801DB840.c[i].info.active == 0) {
                    found = 1;
                    *index = i + 0x1C;
                    data = D_801DB840.c[i].data;
                    info = &D_801DB840.c[i].info;
                    break;
                }
            }
            break;
        case 4:
            for (i = 0; i < 15; i++) {
                if (D_801DB840.d[i].info.active == 0) {
                    found = 1;
                    *index = i + 0x1F;
                    data = D_801DB840.d[i].data;
                    info = &D_801DB840.d[i].info;
                    break;
                }
            }
            break;
        default:
            break;
    }
    if (found) {
        D_801AF1F4[type].init(data, initParams);
        info->arg3 = arg3;
        info->arg4 = arg4;
        info->active = 1;
    }
}
