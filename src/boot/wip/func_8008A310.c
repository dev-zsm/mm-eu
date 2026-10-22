// FLAGS: -O2 -g0
#include "types.h"

typedef struct {
    s32 p0;
    s32 p4;
    s32 mode;
    s32 pad;
    u8 bits;
} Ctl;

extern u8 D_8009D330;

s32 __osVoiceGetStatus(s32 a, s32 b, u8 *flag);
s32 __osVoiceContRead2(s32 a, s32 b, s32 c, u8 *out);
s32 __osVoiceContWrite4(s32 a, s32 b, s32 c, u32 *out);
s32 __osVoiceContRead36(s32 a, s32 b, s32 c, u8 *out);

static void unpack(u16 *o, u8 *b) {
    o[0] = (b[1] << 8) | b[0];
    o[1] = b[2];
    o[2] = (b[5] << 8) | b[4];
    o[3] = (b[7] << 8) | b[6];
    o[4] = (b[9] << 8) | b[8];
    o[5] = (b[11] << 8) | b[10];
}

s32 osVoiceGetReadData(Ctl *s, u16 *out) {
    u8 buf[0x20];
    u8 flag;
    u8 bits;
    s32 err;
    u32 word;
    s32 r;

    r = 0;
    switch (s->mode) {
    case 1:
        err = __osVoiceGetStatus(s->p0, s->p4, &flag);
        if (err != 0) {
            return err;
        }
        if (flag & 1) {
            return 0xC;
        }
        err = __osVoiceContRead2(s->p0, s->p4, 0, buf);
        if (err != 0) {
            return err;
        }
        bits = buf[0] & 7;
        s->bits = bits;
        D_8009D330 = bits;
        if (bits == 0) {
            s->mode = 2;
            goto mode2;
        }
        if (bits == 7) {
            s->mode = 2;
            goto mode2;
        }
        return 0xC;
    case 2:
    mode2:
        s->mode = 2;
        err = __osVoiceGetStatus(s->p0, s->p4, &flag);
        if (err != 0) {
            return err;
        }
        if (flag & 2) {
            return 0xF;
        }
        word = 0x600;
        err = __osVoiceContWrite4(s->p0, s->p4, 0, &word);
        if (err != 0) {
            return err;
        }
        s->mode = 3;
        goto mode3;
    case 3:
    mode3:
        s->mode = 3;
        err = __osVoiceGetStatus(s->p0, s->p4, &flag);
        if (err != 0) {
            return err;
        }
        if (flag & 1) {
            return 0xF;
        }
        err = __osVoiceContRead36(s->p0, s->p4, 0, buf);
        if (err != 0) {
            return err;
        }
        unpack(out, buf);
        bits = buf[0x12] & 7;
        s->bits = bits;
        if (bits != 0) {
            s->mode = 4;
        } else {
            s->mode = 0;
        }
        return r;
    case 4:
    default:
        if (s->mode == 4) {
            s->mode = 4;
            err = __osVoiceGetStatus(s->p0, s->p4, &flag);
            if (err != 0) {
                return err;
            }
            if (flag & 1) {
                return 0xC;
            }
            err = __osVoiceContRead2(s->p0, s->p4, 0, buf);
            if (err != 0) {
                return err;
            }
            s->bits = buf[0] & 7;
            s->mode = 0;
            return r;
        }
        return 5;
    }
}
