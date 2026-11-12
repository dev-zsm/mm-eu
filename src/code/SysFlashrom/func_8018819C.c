// FLAGS: -g
// COMPILER: ido53
#include "types.h"

typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 pad3;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
} Req;

extern u8 D_801F48C0[];
extern s32 D_801F48CC;
extern void func_80093D50(void *, u32, u32);
extern s32 func_8008EFD0(void *, void *, s32);

s32 func_8018819C(Req *req, s32 a1, s32 a2, s32 a3) {
    s32 ret;

    func_80093D50(D_801F48C0, D_801F48CC | 0x10000, 0xB4000000);
    req->unk2 = a1;
    req->unk4 = a3;
    req->unk8 = a2;
    req->unkC = 0;
    req->unk10 = 0x80;
    ret = func_8008EFD0(D_801F48C0, req, 1);
    return ret;
}
