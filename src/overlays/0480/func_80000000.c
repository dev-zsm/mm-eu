#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
#include "generated/overlays/0480.h"
void func_80000000(Actor *thisx) {
    thisx->focus.pos.x = thisx->world.pos.x;
    thisx->focus.pos.y = thisx->world.pos.y + 80.0f;
    thisx->focus.pos.z = thisx->world.pos.z;
    thisx->focus.rot.x = thisx->world.rot.x;
    thisx->focus.rot.y = thisx->world.rot.y;
    thisx->focus.rot.z = thisx->world.rot.z;
}
