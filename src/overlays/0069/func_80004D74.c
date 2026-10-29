#include "types.h"
extern void func_8087F9F0(void *, s32, f32, s32);
void func_80004D74(u8 *a0, s32 a1, f32 a2) { func_8087F9F0(a0, a1, a2, *(s32 *)(a0 + 0x210)); }
