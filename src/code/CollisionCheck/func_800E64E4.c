#include "types.h"

s32 CollisionCheck_GetMassType(u8 mass) {
    if (mass == 0xFF) {
        return 0;
    }
    if (mass == 0xFE) {
        return 1;
    }
    return 2;
}
