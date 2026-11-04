#include "types.h"

typedef struct {
    u8 pad0[0xC];
    f32 unkC;
    f32 unk10;
    u8 pad14[8];
    f32 unk1C;
} Animation;

void Animation_Reverse(Animation *arg0) {
    f32 temp = arg0->unkC;

    arg0->unkC = arg0->unk10;
    arg0->unk10 = temp;
    arg0->unk1C = -arg0->unk1C;
}
