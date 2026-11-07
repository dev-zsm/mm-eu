#include "types.h"
void func_800FF0F8(u8 *, f32, f32, s32);
void func_800FEC70(u8 *, s16, s16);
void func_8000F09C(u8 *p, f32 a, s16 b, f32 c, s32 d, s16 e) {
    func_800FF0F8(p + 0xAD0, a, c, d);
    func_800FEC70(p + 0xAD4, b, e);
}
