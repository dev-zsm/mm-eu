#include "types.h"

extern void func_800897D0(void *ptr, s32 size);
extern void THA_Reset(s32 *arg0);

void THA_Init(s32 *arg0, s32 arg1, s32 arg2) {
    func_800897D0(arg0, 0x10);
    arg0[1] = arg1;
    arg0[0] = arg2;
    THA_Reset(arg0);
}
