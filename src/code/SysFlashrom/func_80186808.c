// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 SysFlashrom_IsInit(void);
void func_8008F490(s32, s32);
void func_801883CC(void *, s32, s32, s32, s32, void *);
void func_80088070(void *, s32, s32);
extern u8 D_801F3650[];

s32 SysFlashrom_Read(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp20[0x18];

    if (SysFlashrom_IsInit() == 0) {
        return -1;
    }
    func_8008F490(arg0, arg2 << 7);
    func_801883CC(sp20, 0, arg1, arg0, arg2, D_801F3650);
    func_80088070(D_801F3650, 0, 1);
    return 0;
}
