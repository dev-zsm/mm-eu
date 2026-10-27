#include "types.h"
extern u8 D_801AF97C[];
s16 Npc_GetTrackingPresetMaxPlayerYaw(s16 a0) {
    return *(s16 *)(D_801AF97C + a0 * 24);
}
