#include "types.h"

typedef struct {
    u8 pad0[8];
    u16 unk8;
} Room;
typedef struct {
    Room **rooms;
    u8 pad4[0x38];
    s16 *unk3C;
} Disp;

extern Disp D_801BF708;

s32 MapDisp_AreRoomsSameStorey(s32 a, s32 b) {
    s16 sa;
    s16 sb;
    u8 *base;

    if (a == -1 || b == -1) {
        return 0;
    }
    sb = D_801BF708.unk3C[b];
    sa = D_801BF708.unk3C[a];
    base = (u8 *)*D_801BF708.rooms;
    if (sb >= sa && sa + ((((Room *)(base + a * 10))->unk8 >> 2) & 7) >= sb) {
        return 1;
    }
    if (sa >= sb && sb + ((((Room *)(base + b * 10))->unk8 >> 2) & 7) >= sa) {
        return 1;
    }
    return 0;
}
