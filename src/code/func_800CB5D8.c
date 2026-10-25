#include "types.h"

s32 Camera_IsDekuHovering(u8 *camera) {
    u8 *play;
    u8 *player = *((u8 **) (camera + 0x90));
    if ((*((u8 **) (camera + 0x90))) == (*((u8 **) ((*((u8 **) (camera + 0x8C))) + 0x1CCC)))) {
        return (*((u32 *) (player + 0xA74))) & 0x2000;
    }
    return 0;
}
