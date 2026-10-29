#include "types.h"

extern s32 func_8082F2D4();

s32 func_800223FC(void *a0) {
    return *(s32 *)((u8 *)a0 + 0x730) == 0 && func_8082F2D4() == 0;
}
