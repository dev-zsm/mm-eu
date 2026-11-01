// FLAGS: -O2 -g0
#include "boot/arena.h"

void ArenaImpl_Lock(Arena *arena) {
    osSendMesg(&arena->lock, NULL, OS_MESG_BLOCK);
}
