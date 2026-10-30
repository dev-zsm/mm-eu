#include "types.h"
#include "actor.h"
void func_809A6BF8();
void func_800022EC(Actor *thisx, PlayState *play) {
    (*(void (**)())((u8 *)thisx + 0x144))(thisx, play);
    func_809A6BF8(thisx, play);
}
