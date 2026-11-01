#include "types.h"

typedef struct {
    /* 0x00 */ u8 flags0;
    /* 0x01 */ u8 flags1;
    /* 0x02 */ u8 pad2;
    /* 0x03 */ s8 unk3;
    /* 0x04 */ u8 unk4;
    /* 0x05 */ u8 pad5[3];
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 pad9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 padD[2];
    /* 0x0F */ u8 unkF;
    /* 0x10 */ s8 unk10;
    /* 0x11 */ u8 pad11[5];
    /* 0x16 */ u16 unk16;
    /* 0x18 */ u16 unk18;
    /* 0x1A */ u16 unk1A;
    /* 0x1C */ u16 unk1C;
    /* 0x1E */ u8 pad1E[4];
    /* 0x22 */ u16 unk22;
    /* 0x24 */ u8 pad24[8];
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ u8 pad34[8];
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ u8 pad40[0x88];
    /* 0xC8 */ s8 unkC8[8];
    /* 0xD0 */ s32 unkD0;
    /* 0xD4 */ void *unkD4;
    /* 0xD8 */ u8 unkD8;
    /* 0xD9 */ u8 padD9[3];
    /* 0xDC */ s32 unkDC;
} AudioChannel;

typedef struct {
    /* 0x0 */ u8 op;
    /* 0x1 */ u8 arg1;
    /* 0x2 */ u8 arg2;
    /* 0x3 */ u8 arg3;
    union {
        /* 0x4 */ s32 i;
        /* 0x4 */ f32 f;
        /* 0x4 */ s8 b;
        /* 0x4 */ u8 ub;
        /* 0x4 */ u16 us;
    } data;
} AudioCmd;

extern void AudioHeap_LoadFilter(void *arg0, s32 arg1, s32 arg2);

void AudioThread_ProcessChannelCmd(AudioChannel *channel, AudioCmd *cmd) {
    s32 arg3;
    s32 value;

    switch (cmd->op) {
        case 1:
            if (channel->unk2C != cmd->data.f) {
                channel->unk2C = cmd->data.f;
                channel->flags1 |= 0x40;
            }
            break;
        case 2:
            if (channel->unk30 != cmd->data.f) {
                channel->unk30 = cmd->data.f;
                channel->flags1 |= 0x40;
            }
            break;
        case 3:
            if (channel->unkA != cmd->data.b) {
                channel->unkA = cmd->data.b;
                channel->flags1 |= 0x20;
            }
            break;
        case 7:
            if (channel->unkB != cmd->data.b) {
                channel->unkB = cmd->data.b;
                channel->flags1 |= 0x20;
            }
            break;
        case 4:
            if (channel->unk3C != cmd->data.f) {
                channel->unk3C = cmd->data.f;
                channel->flags1 |= 0x80;
            }
            break;
        case 5:
            if (channel->unk4 != cmd->data.b) {
                channel->unk4 = cmd->data.b;
            }
            break;
        case 17:
            if (channel->unk8 != cmd->data.b) {
                channel->unk8 = cmd->data.b;
            }
            break;
        case 18:
            channel->unk10 = cmd->data.b;
            break;
        case 6:
            if (cmd->arg3 < 8) {
                channel->unkC8[cmd->arg3] = cmd->data.b;
            }
            break;
        case 8:
            channel->flags0 = ((cmd->data.b << 4) & 0x10) | (channel->flags0 & ~0x10);
            break;
        case 9:
            channel->unk3 = cmd->data.b;
            break;
        case 10:
            channel->unk1C = 1;
            channel->unk18 = cmd->data.ub << 3;
            break;
        case 11:
            channel->unk1A = 1;
            channel->unk16 = cmd->data.ub << 5;
            break;
        case 12:
            channel->unkF = cmd->data.ub;
            break;
        case 13:
            channel->unk22 = cmd->data.us;
            break;
        case 14:
            channel->unkD8 = cmd->data.ub;
            break;
        case 15:
            channel->unkDC = cmd->data.i;
            break;
        case 16:
            channel->unkD0 = cmd->data.i;
            break;
        case 19:
            value = cmd->data.i;
            arg3 = cmd->arg3;
            if (value != 0) {
                channel->unkD4 = (void *)value;
            }
            if (channel->unkD4 != NULL) {
                AudioHeap_LoadFilter(channel->unkD4, arg3 >> 4, arg3 & 0xF);
            }
            break;
        case 20:
            channel->unkC = cmd->data.ub;
            break;
    }
}
