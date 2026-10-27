#include "types.h"

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
} Ctx;

extern u16 D_801C2DEC[11][27];
extern u32 D_801C29F0[];
extern struct { u8 pad[0xF5C]; u32 unkF5C; } D_801E6EF0;

void Scene_CommandSetRegionVisitedFlag(Ctx *arg0, s32 arg1) {
    s16 j = 0;
    s16 i = 0;

    while (1) {
        if (D_801C2DEC[i][j] == 0xFFFF) {
            i++;
            j = 0;
            if (i == 11) {
                break;
            }
        }
        if (arg0->unkA4 == D_801C2DEC[i][j]) {
            break;
        }
        j++;
    }
    if (i < 11) {
        D_801E6EF0.unkF5C = D_801C29F0[i] | D_801E6EF0.unkF5C | D_801E6EF0.unkF5C;
    }
}
