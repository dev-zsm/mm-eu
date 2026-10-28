#include "types.h"

typedef struct {
    u8 pad0[0x1EC];
    u16 unk1EC;
    u8 pad1EE[0x12];
    u16 unk200;
    u8 pad202[0x22];
    u16 unk224;
} Sub;
typedef struct {
    u8 pad0[0x16F34];
    u16 unk16F34;
} Ctx;
s32 MapDisp_SkipDrawDungeonMap(Ctx *ctx) {
    Sub *s;
    Sub *new_var;
    long v;
    new_var = (Sub *) (((u8 *) ctx) + 0x16D30);
    if ((*((u16 *) (((u8 *) ctx) + 0x16F34))) != 1) {
        return 1;
    }
    s = new_var;
    v = s->unk1EC;
    if ((v == 7) || ((v >= 8) && (v < 0x13))) {
        return 1;
    }
    if ((v != 6) || (s->unk200 != 0)) {
        return 1;
    }
    if (s->unk224 == 0) {
        return 1;
    }
    return 0;
}
