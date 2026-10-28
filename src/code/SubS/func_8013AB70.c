#include "types.h"

typedef struct Act {
    u8 pad0[0x12C];
    struct Act *next;
    u8 pad130[0x1A4 - 0x130];
    u8 unk1A4;
    u8 unk1A5;
} Act;
extern Act *SubS_FindActor(void *play, Act *prev, s32 a2, s16 a3);
Act *SubS_FindScheduleDoor(void *play, s32 id) {
    Act *prev = (void *) 0;
    Act *found;
    s32 type = 5;
    while (1) {
        found = SubS_FindActor(play, prev, 0xA, type);
        if (found == ((void *) 0)) {
            break;
        }
        if ((found->unk1A4 == type) && (found->unk1A5 == ((u8) id))) {
            break;
        }
        found = found->next;
        if (!(found != ((void *) 0))) {
            found = (void *) 0;
            break;
        } else {
            prev = found;
        }
    }

    return found;
}
