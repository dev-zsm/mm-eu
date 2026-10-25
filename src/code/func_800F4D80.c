#include "types.h"

extern u8 D_A98000[];
extern void func_80080CE0(void *dst, void *src, s32 size);

void Font_LoadMessageBoxEndIcon(u8 *arg0, u16 arg1) {
    func_80080CE0(arg0 + 0x7800, D_A98000 + 0x5000 + (arg1 << 7), 0x80);
}
