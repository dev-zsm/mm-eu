#include "types.h"

s32 MsgEvent_Jump3(s32 a0, s32 a1, u8 **scriptPtr, s32 a3) {
    unsigned long new_var3;
    s16 offset;
    u8 **new_var2;
    u8 **new_var;
    u8 *new_var4;
    new_var3 = 0;
    new_var4 = *scriptPtr;
    offset = ((*scriptPtr)[2] | (new_var4[1] << 8)) ^ new_var3;
    new_var = scriptPtr;
    *new_var = (*new_var) + offset;
    *(new_var2 = new_var) += 3; return 1;
}
