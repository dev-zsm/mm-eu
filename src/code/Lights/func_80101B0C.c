#include "types.h"
typedef struct { u8 pad0[16]; } LightSlot;
typedef struct {
    u8 pad0[1];
    u8 numUsed;
    u8 pad2[0xE];
    LightSlot slots[7];
} LightSlots;
LightSlot *Lights_FindSlot(LightSlots *slots) {
    if (slots->numUsed >= 7) {
        return NULL;
    }
    return &slots->slots[slots->numUsed++];
}
