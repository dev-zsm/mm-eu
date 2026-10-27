#include "types.h"

void func_801522E8(u8 *arg0, u16 arg1);

void func_801529A8(u8 *arg0, u16 arg1) {
    *(s16 *)(arg0 + 0x16952) = 1;
    func_801522E8(arg0, arg1);
}
