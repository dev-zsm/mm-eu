#include "types.h"

typedef struct {
    u8 pad0[0xA6C];
    u32 unkA6C;
} Actor;
typedef struct {
    u8 pad0[0x1CCC];
    Actor *unk1CCC;
} Play;
typedef struct {
    u8 pad0[0x8C];
    Play *play;
    Actor *target;
} Camera;
u32 Camera_IsMountedOnHorse(Camera *camera) {
    Actor *new_var2;
    Actor *new_var;
    new_var = camera->target;
    new_var2 = camera->target;
    if (new_var == camera->play->unk1CCC) {
        return new_var2->unkA6C & 0x800000;
    }
    return 0;
}
