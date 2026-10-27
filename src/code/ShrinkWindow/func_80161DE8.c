#include "types.h"

typedef struct {
    u8 pad0[3];
    u8 unk3;
} Window;

extern Window *D_801EE3D4;

void ShrinkWindow_Pillarbox_SetSize(s32 arg0) {
    D_801EE3D4->unk3 = arg0;
}
