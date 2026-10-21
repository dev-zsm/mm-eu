// FLAGS: -O2 -g0 -mips2
#include "types.h"

s32 func_80086E68(s32 a0);
s32 func_80086E90(s32 a0, s32 a1, s32 a2);
s32 func_80080CE0(s32 a0, s32 a1, s32 a2);
void func_80084A00(s32 a0, s32 a1, s32 a2);
void func_800897D0(s32 a0, s32 a1);
void func_8008F410(s32 a0, s32 a1);

s32 func_80084D54(s32 a0, s32 a1, s32 a2) {
    s32 len;
    s32 ret;
    s32 q;
    s32 p;
    s32 tmp;
    s32 val;

    len = a1 - a0;
    ret = func_80086E68(len);
    q = ret + len;
    func_80080CE0(ret, a0, len);
    p = q - *(s32 *)(q - 4);
    val = *(s32 *)(p + 0xC) + len;
    ret = func_80086E90(ret, val, q - 4);
    if (ret == 0) {
        return 0;
    }
    tmp = ret + len - *(s32 *)(q - 4);
    func_80084A00(ret, tmp, a2);
    if (*(s32 *)(tmp + 0xC) != 0) {
        func_800897D0(ret + len, *(s32 *)(tmp + 0xC));
    }
    func_8008F410(ret, val);
    return ret;
}
