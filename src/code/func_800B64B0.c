#include "types.h"
typedef struct Blk { s32 a; s32 b; s32 c; s32 d; s32 e; } Blk;
void Actor_SetWorldToHome(u8 *a0) {
    *(Blk *)(a0 + 0x24) = *(Blk *)(a0 + 0x8);
}
