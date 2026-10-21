// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

extern u8 D_80098E70[];
extern u8 D_80098E88[];
extern u8 D_80098E8C[];
extern u8 D_80098E94[];
extern u8 D_80098E98[];
extern u8 D_80098EA0[];
extern u8 D_80098EB8[];
extern u8 D_80098EBC[];
extern u8 D_80098EC4[];
extern u8 D_80098EC8[];

extern s32 func_8008B0D0(s32 a0);
extern void func_8008198C(void *a0, s32 a1);
extern void func_8008482C(void *a0, s32 a1);

void func_80083D58(s32 a0, s32 a1) {
    func_8008198C(D_80098E70, func_8008B0D0(0));
    func_8008198C(D_80098E88, a0 ? a0 : (s32)D_80098E8C);
    func_8008198C(D_80098E94, a1 ? a1 : (s32)D_80098E98);
    func_8008482C(D_80098EA0, func_8008B0D0(0));
    func_8008482C(D_80098EB8, a0 ? a0 : (s32)D_80098EBC);
    func_8008482C(D_80098EC4, a1 ? a1 : (s32)D_80098EC8);
}
