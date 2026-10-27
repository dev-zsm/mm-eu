#include "types.h"

typedef struct {
    /* 0x00 */ s16 index;
    /* 0x02 */ u8 pad2[6];
    /* 0x08 */ s32 isActive;
    /* 0x0C */ u8 padC[0x24 - 0xC];
} QuakeRequest; // size = 0x24

extern QuakeRequest D_801ED280[4];

QuakeRequest *Quake_GetRequest(s16 index) {
    QuakeRequest *req = &D_801ED280[index & 3];

    if (req->isActive == 0) {
        return NULL;
    }
    if (index != req->index) {
        return NULL;
    }
    return req;
}
