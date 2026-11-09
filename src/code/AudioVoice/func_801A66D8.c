// FLAGS: -O2 -g0 -mips2
#include "types.h"

typedef struct {
    /* 0x00 */ u8 pad0[4];
    /* 0x04 */ s8 state;
    /* 0x05 */ u8 pad5[3];
    /* 0x08 */ void *active;
    /* 0x0C */ u16 unkC;
    /* 0x0E */ u16 unkE;
    /* 0x10 */ u16 unk10;
    /* 0x12 */ u16 unk12;
    /* 0x14 */ u16 unk14;
} ControllerState;

typedef struct {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 unk2;
    /* 0x04 */ u16 unk4;
    /* 0x06 */ u16 unk6;
    /* 0x08 */ u8 pad8[0xC];
    /* 0x14 */ u16 unk14;
    /* 0x16 */ u8 pad16[8];
} ControllerRequest;

extern ControllerState D_801F4DE0;
extern u8 D_801F4DF8[];
extern u8 D_801F4E04;
extern s8 D_801F4DE4; // same byte as D_801F4DE0.state: written through its own symbol, as the ROM does
extern ControllerRequest D_801F4E08;
extern ControllerRequest D_801F4E28;

extern s32 PadMgr_VoiceAcquireSerialEventQueue(void);
extern void PadMgr_VoiceReleaseSerialEventQueue(s32 queue);
extern s32 func_800965B0(void *arg);
extern s32 func_8008A310(void *arg, void *request);
extern void func_80092460(void *arg);
extern s32 func_801A60C0(s32 arg);

void func_801A66D8(void) {
    s32 result = 0;
    s32 pad; // unused: matches the ROM stack layout
    s32 queue;
    s32 pad2; // unused: matches the ROM stack layout

    switch (D_801F4DE0.state) {
        case 0:
            queue = PadMgr_VoiceAcquireSerialEventQueue();
            result = func_800965B0(D_801F4DF8);
            PadMgr_VoiceReleaseSerialEventQueue(queue);
            D_801F4DE4 = 1;
            break;
        case 1:
            queue = PadMgr_VoiceAcquireSerialEventQueue();
            result = func_8008A310(D_801F4DF8, &D_801F4E08);
            PadMgr_VoiceReleaseSerialEventQueue(queue);
            if (func_801A60C0(result) == 0) {
            switch (D_801F4E04) {
                case 0:
                    D_801F4DE4 = 2;
                    break;
                case 1: // empty cases keep the switch a jump table, as in the ROM
                case 2:
                case 3:
                case 4:
                case 5:
                case 6:
                    break;
                case 7:
                    D_801F4DE4 = 2;
                    break;
            }
            }
            break;
        case 2:
            if (((D_801F4E08.flags & D_801F4DE0.unk10) == 0) && (D_801F4DE0.unkE >= D_801F4E08.unk2) &&
            (D_801F4DE0.unkC >= D_801F4E08.unk14) && (D_801F4E08.unk4 >= D_801F4DE0.unk12) &&
            (D_801F4E08.unk6 >= D_801F4DE0.unk14)) {
            D_801F4E28 = D_801F4E08;
            D_801F4DE0.active = &D_801F4E28;
            }
            queue = PadMgr_VoiceAcquireSerialEventQueue();
            func_80092460(D_801F4DF8);
            PadMgr_VoiceReleaseSerialEventQueue(queue);
            queue = PadMgr_VoiceAcquireSerialEventQueue();
            result = func_800965B0(D_801F4DF8);
            PadMgr_VoiceReleaseSerialEventQueue(queue);
            D_801F4DE4 = 1;
            break;
    }
    func_801A60C0(result);
}
