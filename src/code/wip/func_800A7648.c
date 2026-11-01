#include "types.h"

typedef struct {
    /* 0x000 */ u8 pad0[0x1C];
    /* 0x01C */ u16 params;
    /* 0x01E */ s8 slot;
    /* 0x01F */ u8 pad1F[0x12F];
    /* 0x14E */ s16 flagsA;
    /* 0x150 */ s16 flagsB;
    /* 0x152 */ s16 state;
} EnItem00;

typedef struct {
    /* 0x00000 */ u8 pad0[0x17D88];
    /* 0x17D88 */ u8 inventory[1];
} PlayState;

extern void EnItem00_DrawRupee(EnItem00 *this, PlayState *play);
extern void EnItem00_DrawHeartPiece(EnItem00 *this, PlayState *play);
extern void EnItem00_DrawHeartContainer(EnItem00 *this, PlayState *play);
extern void EnItem00_DrawSprite(EnItem00 *this, PlayState *play);
extern s32 Object_GetSlot(void *arg0, s32 arg1);
extern s32 Object_IsLoaded(void *arg0, s32 arg1);
extern void Actor_SetObjectDependency(PlayState *play, EnItem00 *this);
extern void Matrix_Scale(f32 arg0, f32 arg1, f32 arg2, s32 arg3);
extern void GetItem_Draw(PlayState *play, s32 arg1);

void EnItem00_Draw(EnItem00 *this, PlayState *play) {
    s32 pad[2];
    s8 slot;

    if ((this->flagsA & this->flagsB) != 0) {
        return;
    }
    switch (this->params) {
        case 0:
        case 1:
        case 2:
        case 19:
        case 20:
            EnItem00_DrawRupee(this, play);
            break;
        case 6:
            EnItem00_DrawHeartPiece(this, play);
            break;
        case 7:
            EnItem00_DrawHeartContainer(this, play);
            break;
        case 3:
            if (this->state < 0) {
                if (this->state == -1) {
                    slot = Object_GetSlot(play->inventory, 0x90);
                    if (Object_IsLoaded(play->inventory, slot) != 0) {
                        this->slot = slot;
                        Actor_SetObjectDependency(play, this);
                        this->state = -2;
                    }
                } else {
                    Matrix_Scale(16.0f, 16.0f, 16.0f, 1);
                    GetItem_Draw(play, 8);
                }
                break;
            }
        case 4:
        case 5:
        case 8:
        case 9:
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 17:
        case 23:
        case 25:
            EnItem00_DrawSprite(this, play);
            break;
        case 22:
            GetItem_Draw(play, 0x27);
            break;
        case 27:
            GetItem_Draw(play, 0x1B);
            break;
        case 28:
            GetItem_Draw(play, 0xA);
            break;
    }
}
