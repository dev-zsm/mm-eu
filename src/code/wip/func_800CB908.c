#include "types.h"

typedef struct {
    u8 pad0[0x145];
    s8 unk145;
} Camera90;

typedef struct {
    u8 pad0[0x1CCC];
    Camera90 *unk1CCC;
} Play;

typedef struct {
    u8 pad0[0x8C];
    Play *unk8C;
    Camera90 *unk90;
} Camera;

s32 Camera_IsUnderwaterAsZora(Camera *arg0) {
    if (arg0->unk90 != arg0->unk8C->unk1CCC) {
        return 0;
    }
    return arg0->unk90->unk145 == 5;
}
