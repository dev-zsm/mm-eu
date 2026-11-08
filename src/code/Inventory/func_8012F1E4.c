#include "types.h"
#include "generated/code_funcs.h"
extern u32 D_801C29F0[];
extern u32 D_801E7D94[];
s32 Inventory_IsMapVisible(s16 sceneId) {
    s32 v = 0;
    if (sceneId >= 0x20) {
        if (sceneId < 0x40) {
            v = 1;
        } else if (sceneId < 0x60) {
            v = 2;
        } else if (sceneId < 0x80) {
            v = 3;
        } else if (sceneId < 0xA0) {
            v = 4;
        } else if (sceneId < 0xC0) {
            v = 5;
        } else if (sceneId < 0xE0) {
            v = 6;
        }
    }
    if (D_801E7D94[v] & D_801C29F0[sceneId - v * 0x20]) {
        return 1;
    }
    return 0;
}
