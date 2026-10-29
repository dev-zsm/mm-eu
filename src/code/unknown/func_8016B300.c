// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s16 unk0;
    s16 pad2;
    s16 unk4;
    s16 pad6;
    s16 unk8;
} Entry;

typedef struct {
    u8 pad0[0x1879C];
    s16 list[10];
} Ctx;

extern s16 D_801C9644[10];
extern Entry *CutsceneManager_GetCutsceneEntry(s16);

void func_8016B300(Ctx *ctx, s32 start) {
    s32 i;
    s32 cur;
    Entry *e;
    s16 *out = ctx->list;
    s16 *ref = D_801C9644;

    for (i = 0; i != 10; i++, out++, ref++) {
        *out = -1;
        cur = start;
        if (start != -1) {
            do {
                e = CutsceneManager_GetCutsceneEntry(cur);
                if (e->unk4 == *ref) {
                    if (e->unk4 == -3 && e->unk0 == 0x2BC) {
                        e->unk0 = 0x226;
                    }
                    *out = cur;
                    break;
                }
                cur = e->unk8;
            } while (cur != -1);
        }
    }
}
