#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} V3s;

typedef struct {
    u8 pad0[0x30];
    V3s unk30;
    u8 pad36[0xBC - 0x36];
    V3s unkBC;
} Actor;

void Actor_SetShapeRotToWorld(Actor *arg0) {
    arg0->unkBC = arg0->unk30;
}
