#include "types.h"
extern u32 D_801C29F0[];
extern u32 D_801E7D94[];
s32 Inventory_IsMapVisible(s16 arg0) {
    s32 v = 0;
    if (arg0 >= 0x20) {
        if (arg0 < 0x40) {
            v = 1;
        } else if (arg0 < 0x60) {
            v = 2;
        } else if (arg0 < 0x80) {
            v = 3;
        } else if (arg0 < 0xA0) {
            v = 4;
        } else if (arg0 < 0xC0) {
            v = 5;
        } else if (arg0 < 0xE0) {
            v = 6;
        }
    }
    if (D_801E7D94[v] & D_801C29F0[arg0 - v * 0x20]) {
        return 1;
    }
    return 0;
}
