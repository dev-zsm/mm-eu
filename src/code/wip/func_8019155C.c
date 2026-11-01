// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct { u8 pad0[2]; u8 b; u8 pad3; s32 unk4; s32 unk8; s32 unkC; s32 unk10; } Req;
typedef struct { u8 pad0[0x14]; s32 unk14; } Chn;
typedef struct { u8 pad0[0x1E38]; Chn *unk1E38; Chn *unk1E3C; u8 pad1E40[0xB64]; u32 unk29A4; } Aud;
extern Aud D_801F84B0;
extern void (*D_801CE910)(Chn *, Req *, s32);

s32 func_8019155C(Req *req, s32 b, s32 unused, s32 c, s32 d, s32 size, s32 e, s32 kind) {
    Chn *chn;

    if (D_801F84B0.unk29A4 >= 0x11) {
        return -1;
    }
    switch (kind) {
        case 2:
            chn = D_801F84B0.unk1E38;
            break;
        case 3:
            chn = D_801F84B0.unk1E3C;
            break;
        default:
            return 0;
    }
    if (size & 0xF) {
        size = (size + 0xF) & ~0xF;
    }
    req->b = b;
    req->unk4 = e;
    req->unkC = c;
    req->unk10 = size;
    req->unk8 = d;
    chn->unk14 = 2;
    D_801CE910(chn, req, unused);
    return 0;
}
