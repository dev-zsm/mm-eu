#include "types.h"

typedef struct Ovl0161Actor {
    /* 0x000 */ s16 id;
    /* 0x002 */ u8 pad2[0x12A];
    /* 0x12C */ struct Ovl0161Actor *next;
} Ovl0161Actor;

typedef struct {
    /* 0x0000 */ u8 pad0[0x1CE4];
    /* 0x1CE4 */ Ovl0161Actor *head;
} Ovl0161Play;

Ovl0161Actor *func_80000374(Ovl0161Play *play) {
    Ovl0161Actor *actor = play->head;

    while (actor != 0) {
        if (actor->id == 0xA6) {
            return actor;
        }
        actor = actor->next;
    }
    return 0;
}
