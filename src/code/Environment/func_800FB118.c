#include "types.h"

typedef struct {
    u8 state;
    u8 pad1[0x1F];
} LightningBolt;

extern LightningBolt D_801EC708[3];

void Environment_AddLightningBolts(void *play, u8 numBolts) {
    s16 count = 0;
    s16 i;

    for (i = 0; i < 3; i++) {
        if (D_801EC708[i].state == 0xFF) {
            count++;
            D_801EC708[i].state = 0;
            if (count >= numBolts) {
                break;
            }
        }
    }
}
