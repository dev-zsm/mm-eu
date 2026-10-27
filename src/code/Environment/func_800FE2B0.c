#include "types.h"

typedef struct {
    /* 0x00000 */ u8 pad0[0xA4];
    /* 0x000A4 */ s16 sceneId;
    /* 0x000A6 */ u8 pad1[0x17040];
    /* 0x170E6 */ u8 storm;
    /* 0x170E7 */ u8 pad2[0x15F9];
    /* 0x186E0 */ s8 flag;
} StormCtx;

typedef struct {
    /* 0x0000 */ u8 pad0[0x18];
    /* 0x0018 */ s32 unk18;
    /* 0x001C */ u8 pad1[0xEF2];
    /* 0x0F0E */ u8 unkF0E;
    /* 0x0F0F */ u8 pad2[0x2D9D];
    /* 0x3CAC */ s32 unk3CAC;
} StormData;

extern StormData D_801E6EF0;

s32 Environment_GetStormState(StormCtx* ctx) {
    u8 result = ctx->storm;

    if ((ctx->sceneId == 0x10) && (ctx->flag == 0)) {
        if ((D_801E6EF0.unk18 >= 2) && !(D_801E6EF0.unkF0E & 1)) {
            result = 1;
        } else {
            result = 0;
        }
    }
    switch (ctx->sceneId) {
        case 0x1C:
        case 0x4D:
        case 0x50:
        case 0x5B:
        case 0x5C:
        case 0x5D:
        case 0x6B:
            if (D_801E6EF0.unk3CAC == 0) {
                result = 0;
            }
            break;
        case 0x5A:
            if (D_801E6EF0.unk3CAC == 1) {
                result = 0;
            }
            break;
    }
    return result;
}
