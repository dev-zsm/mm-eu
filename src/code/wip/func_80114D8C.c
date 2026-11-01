#include "types.h"

extern u8 D_801E6F72;
extern u8 D_801E6F73;
extern u8 D_801E6EF0[];

s32 func_80114D8C(void) {
    s32 item = 0x12;
    s32 slot = 0x14;

    if (item == D_801E6F72) {
        return 1;
    }
    if (item == D_801E6F73) {
        return 1;
    }
    if (item == D_801E6EF0[slot + 0x70]) {
        return 1;
    }
    if (item == D_801E6EF0[slot + 0x71]) {
        return 1;
    }
    if (item == D_801E6EF0[slot + 0x72]) {
        return 1;
    }
    if (item == D_801E6EF0[slot + 0x73]) {
        return 1;
    }
    return 0;
}
