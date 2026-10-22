// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 DmaMgr_RequestSync(void *a0, s32 a1, s32 a2);
void func_80084E40(void *a0, void *a1, s32 a2);
void bzero(void *a0, s32 a1);
void func_8008A780(void *a0, s32 a1);
void osInvalICache(void *a0, s32 a1);

s32 func_80085074(s32 a0, s32 a1, s32 a2, s32 a3, u8 *a4) {
    u8 sp28[0x10];
    s32 len;
    u8 *p;
    u8 *q;
    s32 ret;

    len = a1 - a0;
    DmaMgr_RequestSync(a4, a0, len);
    p = a4 + len;
    q = p - *(s32 *)(p - 4);
    func_80084E40(a4, q, a2);
    if (*(s32 *)(q + 0xC) != 0) {
        bzero(p, *(s32 *)(q + 0xC));
    }
    bzero(q, (*(s32 *)(q + 0x10) << 2) + 0x14);
    ret = a3 - a2;
    func_8008A780(a4, ret);
    osInvalICache(a4, ret);
    return ret;
}
