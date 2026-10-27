#include "types.h"
typedef struct {
    u8 pad0[0x17022];
    u8 unk17022;
    u8 unk17023;
    u8 unk17024;
    u8 pad17025[0x170C4 - 0x17025];
    u8 unk170C4;
    u8 unk170C5;
    u8 pad170C6;
    u8 unk170C7;
    u8 pad170C8[0x170E0 - 0x170C8];
    f32 unk170E0;
} Play;
extern u8 D_801BE704;
extern u8 D_801EC7B9;
void Environment_DisableUnderwaterLights(Play *play) {
    if (play->unk17022 == 0) {
        if (D_801EC7B9 != 0) {
            D_801EC7B9 = 0;
            play->unk17023 = D_801BE704;
            play->unk17024 = D_801BE704;
        }
    } else if (D_801EC7B9 != 0) {
        D_801EC7B9 = 0;
        play->unk170C5 = D_801BE704;
        play->unk170C4 = 0;
        play->unk170C7 = 0xFF;
        play->unk170E0 = 1.0f;
    }
}
