#include "types.h"

typedef struct {
    u8 pad0[0x24E];
    s16 unk24E;
    s16 unk250;
} Sub;
typedef struct {
    u8 pad0[0x16C38];
    s16 unk16C38;
    u8 pad16C3A[0x1B4A];
    void (*unk18784)(void *, s32);
} Ctx;
extern s16 D_801E6F26;
s32 LifeMeter_DecreaseInterfaceHealth(Ctx *ctx) {
    Sub *s = (Sub *) (((u8 *) ctx) + 0x169E8);
    s32 d;
    if (ctx->unk16C38 != 0) {
        s->unk250--;
    } else {
        s->unk250 = 0x140;
        s->unk24E -= 0x10;
        if (s->unk24E <= 0) {
            // one line: the ROM's scheduling depends on these stores sharing a single source line
            do { s->unk24E = 0; d = D_801E6F26; ctx->unk18784(ctx, (-1) - d); return 1; } while (0);
        }
    }
    return 0;
}
