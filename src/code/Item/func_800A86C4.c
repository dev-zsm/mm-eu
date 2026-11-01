#include "types.h"
#include "code_funcs.h"

extern s32 Flags_GetCollectible(void *ctx, s32 flag);

s32 Item_CanDropBigFairy(void *play, s32 item, s32 flag) {
    return (func_800A8670(item) == 0x1A) && !Flags_GetCollectible(play, flag);
}
