#include "types.h"
#include "actor.h"
void func_800E09D8();
void func_80A4D8CC();
void func_80001B28(Actor *thisx, PlayState *play) {
    func_800E09D8(play, (u8 *)thisx + 0x2A8);
    func_80A4D8CC(thisx);
}
