// FLAGS: -O2 -g0
#include "boot/arena.h"

u8 func_8008738C(Arena *arena) {
    return arena->isInit;
}
