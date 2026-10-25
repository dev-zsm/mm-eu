#include "types.h"

extern u32 D_801BF834[];
extern u32 D_801BF850[];
extern u8 D_C000000[];

u32 MapDisp_GetDungeonMapFloorTexture(s32 index) {
    if (index >= 0 && index < 8) {
        return D_801BF834[index];
    }
    if (index >= -8 && index < 0) {
        return D_801BF850[-index];
    }
    return (u32)D_C000000;
}
