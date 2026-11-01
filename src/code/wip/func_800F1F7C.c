#include "types.h"

typedef struct {
    /* 0x0 */ u8 pad0[6];
    /* 0x6 */ s16 unk6;
    /* 0x8 */ u8 pad8[3];
    /* 0xB */ u8 unkB;
    /* 0xC */ u8 padC[4];
} Ent;

typedef struct {
    /* 0x0 */ u8 pad0[6];
    /* 0x6 */ u8 unk6;
    /* 0x7 */ u8 pad7;
} Room;

typedef struct {
    /* 0x00000 */ u8 pad0[0x1F24];
    /* 0x01F24 */ u8 unk1F24;
    /* 0x01F25 */ u8 pad1F25[0x4F];
    /* 0x01F74 */ Room *rooms;
    /* 0x01F78 */ u8 pad1F78[0x169D0];
    /* 0x18948 */ u8 pad18948[0x200];
    /* 0x18B48 */ u8 unk18B48;
} Play;

typedef struct {
    /* 0x00 */ u8 pad0[0x10];
    /* 0x10 */ Play *play;
} Gl;

extern Gl D_801BE3E0;
extern Ent *D_801EC670;
extern s16 D_801EC674;

s16 CutsceneManager_FindEntranceCsId(void) {
    s32 i = 0;
    s16 n = D_801EC674;
    Ent *e;

    if (n > 0) {
        e = D_801EC670;
        do {
            if (e->unk6 != -1 && e->unk6 < D_801BE3E0.play->unk1F24 &&
                D_801BE3E0.play->unk18B48 == D_801BE3E0.play->rooms[e->unk6].unk6) {
                return i;
            }
            i++;
            e++;
        } while (i < n);
        i = 0;
    }
    if (n > 0) {
        e = D_801EC670;
        do {
            if (e->unkB >= 0x64 && D_801BE3E0.play->unk18B48 + 0x64 == e->unkB) {
                return i;
            }
            i++;
            e++;
        } while (i < n);
    }
    return -1;
}
