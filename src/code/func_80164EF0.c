#include "types.h"

typedef struct {
    char pad0[0x1C];
} TransitionOverlay;

typedef struct {
    char pad0[2];
    s8 id;
} Transition;

extern TransitionOverlay D_801C9490[];

void TransitionOverlay_Free(TransitionOverlay *overlay);

void Transition_Destroy(Transition *arg0) {
    TransitionOverlay_Free(&D_801C9490[arg0->id]);
}
