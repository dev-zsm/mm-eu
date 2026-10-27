#include "types.h"

typedef struct {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 pad4[8];
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ s16 unk12;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
} QuakeRequest;

extern QuakeRequest *Quake_GetRequest(s16 index);

s32 Quake_SetValue(s16 index, s16 type, s16 value) {
    QuakeRequest *req = Quake_GetRequest(index);

    if (req == NULL) {
        return 0;
    }
    switch (type) {
        case 1:
            req->unk1A = value;
            break;
        case 2:
            req->unkC = value;
            break;
        case 4:
            req->unkE = value;
            break;
        case 8:
            req->unk10 = value;
            break;
        case 0x10:
            req->unk12 = value;
            break;
        case 0x20:
            req->unk14 = value;
            break;
        case 0x40:
            req->unk16 = value;
            break;
        case 0x80:
            req->unk18 = value;
            break;
        case 0x100:
            req->unk1E = value;
            req->unk2 = req->unk1E;
            break;
        case 0x200:
            req->unk1C = value;
            break;
    }
    return 1;
}
