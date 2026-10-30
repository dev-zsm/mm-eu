#include "types.h"
#include "actor.h"
extern u8 D_6001400[];
void func_800B7DD4();
void func_800BDD44();
void func_80000A90(Actor *thisx, PlayState *play) {
    func_800B7DD4(thisx, play, 1);
    func_800BDD44(play, D_6001400);
}
