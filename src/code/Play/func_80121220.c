// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    u8 pad0[0x184];
    u8 x184[0x198];
    u8 state;
    u8 pad31D[3];
    u8 x320[0x18];
    s32 unk338;
    s32 unk33C;
    s32 unk340;
    s32 unk344;
} Sub;
typedef struct {
    u8 pad0[0x169E8];
    Sub sub;
} Ctx;
extern void func_8008F3E0(void *, void *, s32);
extern void func_80080C54(void *, s32, s32, s32, s32, void *, s32);
extern s32 func_80088070(void *, s32, s32);
void func_80121220(Ctx *ctx, s32 a1) {
    Sub *s;
    s = &ctx->sub;
    switch (ctx->sub.state) {
        case 0:
            if (s->unk33C == 0) {
            break;
        }
            func_8008F3E0(s->x320, &s->unk338, 1);
            func_80080C54(s->x184, s->unk33C, s->unk340, s->unk344, 0, s->x320, 0);
            s->state = 1;

        case 1:
            if (func_80088070(s->x320, 0, a1) == 0) {
            s->state = 2;
        }
            break;

        s = &ctx->sub;
    }

}
