#include "types.h"

typedef struct {
    u8 pad0[0x34];
    s16 healthCapacity;
    s16 health;
} SaveContext;

extern SaveContext D_801E6EF0;

s32 LifeMeter_IsCritical(void) {
    s16 threshold;

    if (D_801E6EF0.healthCapacity <= 0x50) {
        threshold = 0x10;
    } else if (D_801E6EF0.healthCapacity <= 0xA0) {
        threshold = 0x18;
    } else if (D_801E6EF0.healthCapacity <= 0xF0) {
        threshold = 0x20;
    } else {
        threshold = 0x2C;
    }

    if (D_801E6EF0.health <= threshold && D_801E6EF0.health > 0) {
        return 1;
    }
    return 0;
}
