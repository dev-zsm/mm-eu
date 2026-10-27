#include "types.h"

extern u8 D_801BAA50[];

void *DamageTable_Get(s32 index) {
    if ((index < 0) || (index >= 0x17)) {
        return NULL;
    }
    return D_801BAA50 + index * 0x20;
}
