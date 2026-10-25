#include "types.h"

typedef struct {
    u8 type;
    u8 unk1;
    u8 unk2;
} TransitionFade;

void TransitionFade_SetType(TransitionFade *this, s32 type) {
    if (type == 1) {
        this->type = 1;
        this->unk2 = 1;
    } else if (type == 2) {
        this->type = 1;
        this->unk2 = 0;
    } else if (type == 3) {
        this->type = 2;
    } else {
        this->type = 0;
    }
}
