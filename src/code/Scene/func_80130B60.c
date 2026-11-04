#include "types.h"

typedef struct {
    u8 pad0[0xA6];
    u8 unkA6;
} Play;

extern void (*D_801C4878[])(Play *);

void Scene_Draw(Play *play) {
    D_801C4878[play->unkA6](play);
}
