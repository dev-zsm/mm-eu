#include "types.h"
#include "generated/overlays/0562.h"

extern u8 D_80BAE420[];

void func_800003F0(Actor *thisx) {
    *(s16 *)((u8 *)thisx + 0x274) = 0;
    *(s16 *)((u8 *)thisx + 0x270) = 1;
    *(u8 **)((u8 *)thisx + 0x254) = D_80BAE420;
}
