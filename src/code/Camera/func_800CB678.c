#include "types.h"

s32 Camera_IsDiving(u8 *camera) {
    u8 *play;
    u8 *player = *((u8 **) (camera + 0x90));
    u32 *new_var;
    new_var = &(*((u32 *) (player + 0xA70)));
    if ((*((u8 **) (camera + 0x90))) == (*((u8 **) ((*((u8 **) (camera + 0x8C))) + 0x1CCC)))) {
        return (*new_var) & 0x800;
    }
    return 0;
}
