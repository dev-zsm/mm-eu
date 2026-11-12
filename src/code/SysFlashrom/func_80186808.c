// FLAGS: -O2 -g3 -mips2
#include "types.h"
#include "generated/code_funcs.h"

void func_8008F490(s32, s32);
void func_801883CC(void *, s32, s32, s32, s32, void *);
void func_80088070(void *, s32, s32);
extern u8 D_801F3650[];

s32 SysFlashrom_Read(void *addr, u32 pageNum, u32 pageCount) {
    u8 sp20[0x18];

    if (SysFlashrom_IsInit() == 0) {
        return -1;
    }
    func_8008F490(addr, pageCount << 7);
    func_801883CC(sp20, 0, pageNum, addr, pageCount, D_801F3650);
    func_80088070(D_801F3650, 0, 1);
    return 0;
}
