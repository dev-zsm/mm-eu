#include "types.h"

typedef struct {
    u8 pad0[0x1C];
    s16 unk1C;
} Ovl0155Actor;

extern void (*D_80921938[])();

void ObjSwitch_Draw(Ovl0155Actor *a) {
    D_80921938[a->unk1C & 7](a);
}
