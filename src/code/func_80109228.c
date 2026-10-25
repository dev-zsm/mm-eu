#include "types.h"

typedef struct {
    u8 pad0[0x20];
    u32 flags;
    u8 pad24[0x28];
    s16 counter;
} MapState;

typedef struct {
    u8 pad0[0x184];
    s32 timer;
} MapDisplay;

extern MapState D_801BF708;
extern MapDisplay D_801ECF30;

void MapDisp_UpdateDungeonMap(s32 arg0) {
    D_801BF708.counter++;
    if (!(D_801BF708.flags & 1)) {
        D_801ECF30.timer++;
        if (D_801ECF30.timer >= 41) {
            D_801BF708.flags |= 1;
        }
    } else {
        D_801ECF30.timer--;
        if (D_801ECF30.timer < 0) {
            D_801BF708.flags &= ~1;
        }
    }
}
