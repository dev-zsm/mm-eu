#include "types.h"
void func_800812A0(s32, u8 *, u8 *);
void func_80081A50(void *, void *, u8 *, s32);
void func_800897D0(u8 *, s32);
void func_80089FE0(u8 *, s32, void *, u8 *, s32, s32);
void func_8008D7E0(s32, u8 *, s32);
void func_8008F3E0(u8 *, u8 *, s32);
void func_80095950(u8 *);
extern u8 D_801F3320[];
extern u8 func_80178258[];
extern u8 func_80178330[];

void func_80178480(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {

    func_800897D0(arg0, 0x338);
    arg0[0x32F] = 1;
    func_8008F3E0(arg0, arg0 + 0x18, 0x40);
    func_8008F3E0(arg0 + 0x118, arg0 + 0x130, 8);
    func_8008D7E0(4, arg0, 0x29B);
    func_8008D7E0(9, arg0, 0x29C);
    func_800812A0(arg5, arg0 + 0x330, arg0);
    func_80081A50(D_801F3320, func_80178258, arg0, 0);
    func_80089FE0(arg0 + 0x150, 5, func_80178330, arg0, arg1, arg2);
    func_80095950(arg0 + 0x150);
}
