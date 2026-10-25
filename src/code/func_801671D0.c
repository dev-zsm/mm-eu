#include "types.h"

typedef struct {
    s16 unk0;
    s8 unk2;
} TransitionState;

typedef struct {
    u8 pad0[0x18BF0];
    TransitionState transition;
} PlayState;

extern void Transition_Destroy(TransitionState *transition);

void Play_ClearTransition(PlayState *play) {
    if (play->transition.unk2 != -1) {
        Transition_Destroy(&play->transition);
    }
    play->transition.unk0 = -1;
}
