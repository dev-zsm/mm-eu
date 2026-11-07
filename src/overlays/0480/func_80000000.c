#include "types.h"
#include "m2c_compat.h"
#include "actor.h"
void func_80000000(Actor *this) {
    this->focus.pos.x = this->world.pos.x;
    this->focus.pos.y = this->world.pos.y + 80.0f;
    this->focus.pos.z = this->world.pos.z;
    this->focus.rot.x = this->world.rot.x;
    this->focus.rot.y = this->world.rot.y;
    this->focus.rot.z = this->world.rot.z;
}
