#include "types.h"
#include "generated/overlays/0630.h"

extern f32 D_80BEFEBC;
extern u8 D_80BEF8E4[];

void func_800003D4(BgIkninSusceil *this) {
    *(s16 *)((u8 *)this + 0x164) = 0x6E;
    *(f32 *)((u8 *)this + 0x28) = *(f32 *)((u8 *)this + 0xC) + D_80BEFEBC;
    *(u8 **)((u8 *)this + 0x160) = D_80BEF8E4;
}
