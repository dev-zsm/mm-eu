#include "types.h"
extern void SysFlashrom_WriteSync();
void func_801473C0(s32 *a0, s32 a1, s32 a2) {
    a0[4] = a1;
    a0[5] = a2;
    SysFlashrom_WriteSync(a0[1]);
}
