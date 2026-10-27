#include "types.h"

extern void BgCheck_GetBgCamFuncDataImpl(void *arg0, s32 arg1, s32 arg2);
extern void func_8016AE0C(void *arg0, s32 arg1);

void Camera_GetBgCamOrActorCsCamFuncData(u8 *arg0, s32 arg1) {
    if (arg1 & 0x1000) {
        BgCheck_GetBgCamFuncDataImpl(*(u8 **)(arg0 + 0x8C) + 0x830, arg1 & ~0x1000, 0x32);
    } else {
        func_8016AE0C(*(void **)(arg0 + 0x8C), arg1);
    }
}
