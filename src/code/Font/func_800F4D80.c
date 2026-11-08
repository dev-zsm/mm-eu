#include "types.h"
#include "generated/code_funcs.h"

extern u8 D_A98000[];
extern void func_80080CE0(void *dst, void *src, s32 size);

void Font_LoadMessageBoxEndIcon(struct Font *font, u16 icon) {
    func_80080CE0((u8 *)font + 0x7800, D_A98000 + 0x5000 + (icon << 7), 0x80);
}
