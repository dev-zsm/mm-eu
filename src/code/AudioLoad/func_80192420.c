// FLAGS: -O2 -g0
#include "types.h"
typedef struct { u8 pad[0x18]; s32 unk18; } Entry;
extern u8 D_801FA1C0[];
Entry *AudioLoad_StartAsyncLoad(s32, s32, s32, s32, s32, s32, s32);
void func_80087CB0(void *, void *, s32);
Entry *AudioLoad_StartAsyncLoadUnkMedium(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7) {
    Entry *e = AudioLoad_StartAsyncLoad(a1, a2, a3, a4, a5, a6, a7);
    if (e == NULL) {
        return NULL;
    }
    func_80087CB0(D_801FA1C0, e, 0);
    e->unk18 = a0;
    return e;
}
