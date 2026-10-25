#include "types.h"

typedef struct {
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

typedef struct {
    /* 0x00 */ u8 pad0[0x14];
    /* 0x14 */ Vec3s orientation;
    /* 0x1A */ u8 pad1A[2];
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ u8 pad1E[0x24 - 0x1E];
} QuakeRequest; // size = 0x24

QuakeRequest *Quake_GetRequest(s16 index);

s32 Quake_SetOrientation(s16 index, s16 arg1, Vec3s orientation) {
    QuakeRequest *req = Quake_GetRequest(index);

    if (req != NULL) {
        req->unk1C = arg1;
        req->orientation = orientation;
        return 1;
    }
    return 0;
}
