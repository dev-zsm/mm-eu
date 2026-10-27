#include "types.h"

typedef struct {
    u8 pad0[0xA70];
    u32 unkA70;
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
u32 func_800CB82C(Camera *camera) {
    Actor *new_var;
    Actor *target = camera->target;
    if (target == camera->play->unk1CCC) {
        new_var = target;
        if (!camera->target) {
        }
        return new_var->unkA70 & 0x800000;
    }
    return 0;
}
