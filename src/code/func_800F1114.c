#include "types.h"

typedef struct {
    u8 pad0[0x18B20];
    u16 flags[1];
} CutsceneFlagsOwner;
void CutsceneFlags_Unset(CutsceneFlagsOwner *arg0, s16 arg1) {
    s16 index = arg1 / 16;
    s16 bit = arg1 % 16;
    int new_var;
    bit = (new_var = 1 << bit) ^ 0xFFFF;
    arg0->flags[index] = arg0->flags[index] & bit;
}
