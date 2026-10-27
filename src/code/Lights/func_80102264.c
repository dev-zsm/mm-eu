// FLAGS: -O2 -g3 -mips2
#include "types.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
} LightNode;

extern LightNode D_801EC7F0;

void Lights_FreeNode(s32 *arg0) {
    LightNode *temp_v0;
    s32 temp_t9;

    if (arg0 != NULL) {
        temp_v0 = &D_801EC7F0;
        temp_t9 = ((LightNode *)((u8 *)arg0 - 8) - temp_v0);
        temp_v0->unk0 = temp_v0->unk0 - 1;
        *arg0 = 0;
        temp_v0->unk4 = temp_t9 / 12;
    }
}
