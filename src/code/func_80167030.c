#include "types.h"

typedef struct {
    /* 0x00 */ s16 flags;
    /* 0x02 */ s8 type;
    /* 0x03 */ u8 pad3[0x255];
} TransitionState;

void func_800897D0(void*, s32);
void func_800862F0(void*, s32);
void Transition_Init(TransitionState*);
extern u8 D_801D7290[];
extern u8 D_801D729C[];

void Play_SetupTransition(u8* ctx, s32 flags) {
    TransitionState* trans = (TransitionState*)(ctx + 0x18BF0);
    s32 type;

    func_800897D0(trans, 0x258);
    type = -1;
    if (flags & 0x40) {
        type = 3;
    } else if ((flags & 0x78) == 0x20) {
        type = 4;
    } else if ((flags & 0x60) == 0) {
        switch (flags) {
            case 1:
                type = 1;
                break;
            case 0:
            case 8:
                type = 2;
                break;
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 13:
            case 17:
            case 18:
            case 19:
                type = 0;
                break;
            case 9:
            case 10:
                ctx[0x18B4A] = 4;
                break;
            case 11:
                ctx[0x18B4A] = 10;
                break;
            case 12:
                ctx[0x18B4A] = 7;
                break;
            case 14:
                ctx[0x18B4A] = 12;
                break;
            case 15:
                ctx[0x18B4A] = 14;
                break;
            case 16:
                ctx[0x18B4A] = 16;
                break;
            case 21:
                type = 5;
                break;
            case 22:
                type = 6;
                break;
            default:
                func_800862F0(D_801D7290, 0x5A4);
                break;
        }
    } else {
        func_800862F0(D_801D729C, 0x5A7);
    }
    trans->flags = flags;
    trans->type = type;
    if (type != -1) {
        Transition_Init(trans);
    }
}
