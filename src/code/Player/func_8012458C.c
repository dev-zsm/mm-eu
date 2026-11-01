#include "types.h"
#include "code_funcs.h"
s32 func_8012458C(u8 *a0) {
    return Player_IsHoldingHookshot(a0) && (*(s32 *)(a0 + 0x34C) == 0);
}
