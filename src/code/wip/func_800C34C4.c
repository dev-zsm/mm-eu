#include "types.h"

typedef struct {
    u8 pad0[0xA4];
    s16 unkA4;
} Struct_800C34C4;

extern s16 D_801B5200[];
extern s16 D_801B5202[];

s32 BgCheck_IsSmallMemScene(Struct_800C34C4 *arg0) {
    s16 id = arg0->unkA4;
    s16 *p = D_801B5200;
    s16 v = *p;

    while (1) {
        p++;
        if (id == v) {
            return 1;
        }
        if ((u32)p >= (u32)D_801B5202) {
            break;
        }
        v = *p;
    }
    return 0;
}
