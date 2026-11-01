#include "types.h"
extern u8 D_801BE660[];
extern u8 D_AA0000[];
void func_80080CE0(void *dst, void *src, u32 size);
void Font_LoadOrderedFont(u8 *font) {
    u8 *p = D_801BE660;
    u8 *dst = font + 0x7880;
    u32 off;
    do {
        if (*p != 0) {
            off = *p << 7;
        } else {
            off = 0;
        }
        func_80080CE0(dst, D_AA0000 + off, 0x80);
        dst += 0x80;
    } while (*p++ != 0x8F);
}
