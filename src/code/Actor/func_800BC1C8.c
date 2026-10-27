#include "types.h"

typedef struct Act {
    /* 0x000 */ s16 id;
    /* 0x002 */ u8 pad2[0x6E];
    /* 0x070 */ s32 unk70;
    /* 0x074 */ u8 pad74[0xB8];
    /* 0x12C */ struct Act *next;
} Act;

typedef struct {
    /* 0x0000 */ u8 pad[0x1CD8];
    /* 0x1CD8 */ Act *head;
} Ctx;

s32 func_800BBF38(Ctx *a, Act *b, f32 c, s32 d);

Act *func_800BC1C8(Ctx *ctx, Ctx *p, f32 f) {
    Act *a = ctx->head;

    while (a != 0) {
        if ((a->id == 9 || a->id == 0x6A || a->id == 0x2F) && func_800BBF38(p, a, f, a->unk70) != 0) {
            break;
        }
        a = a->next;
    }
    return a;
}
