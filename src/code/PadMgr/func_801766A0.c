// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/padmgr.h"

void PadMgr_AdjustInput(Input* input) {
    s32 plus;
    s32 minus;
    s32 pressX;
    s32 pressX2;
    s32 pressY;
    s32 pressY2;
    s32 pad1;
    s32 pad2;
    s32 pad3;
    f32 pad4;
    f32 newX;
    f32 newY;
    f32 magnitude;
    f32 angle;
    s8 curX = input->cur.stick_x;
    s8 curY = input->cur.stick_y;

    if (CHECK_BTN_ANY(input->press.button, BTN_RESET) || (input->press.stick_x == 0)) {
        input->press.stick_x = 61;
        input->press.errno = -61;
        input->press.stick_y = 63;
        input->rel.errno = -63;
    }
    pressX = input->press.stick_x;
    pressX2 = (s8)input->press.errno;
    pressY = input->press.stick_y;
    pressY2 = (s8)input->rel.errno;

    if (CHECK_BTN_ANY(input->cur.button, BTN_RESET)) {
        minus = curX - 7;
        plus = curX + 7;

        if (minus > 0) {
            if (pressX < minus - 3) {
                pressX = minus - 3;
                input->press.stick_x = minus - 3;
            }
        } else if (plus < 0) {
            if (pressX2 > plus + 3) {
                pressX2 = plus + 3;
                input->press.errno = plus + 3;
            }
        }

        minus = curY - 7;
        plus = curY + 7;

        if (minus > 0) {
            if (pressY < minus - 3) {
                pressY = minus - 3;
                input->press.stick_y = minus - 3;
            }
        } else if (plus < 0) {
            if (pressY2 > plus + 3) {
                pressY2 = plus + 3;
                input->rel.errno = plus + 3;
            }
        }
    }

    minus = curX - 7;
    plus = curX + 7;

    if (minus > 0) {
        newX = (pressX < minus) ? 1.0f : (f32)minus / pressX;
    } else if (plus < 0) {
        newX = (pressX2 > plus) ? -1.0f : -(f32)plus / pressX2;
    } else {
        newX = 0.0f;
    }

    minus = curY - 7;
    plus = curY + 7;

    if (minus > 0) {
        newY = (pressY < minus) ? 1.0f : (f32)minus / pressY;
    } else if (plus < 0) {
        newY = (pressY2 > plus) ? -1.0f : -(f32)plus / pressY2;
    } else {
        newY = 0.0f;
    }

    if (1) {
        s32 pad;

        magnitude = sqrtf(SQ(newX) + SQ(newY));
        if (magnitude > 1.0f) {
            magnitude = 1.0f;
        }
        angle = Math_Atan2F_XY(curY, -curX);
        newX = -sinf(angle) * magnitude;
        newY = cosf(angle) * magnitude;
    }
    input->rel.stick_x = newX * 60.5f;
    input->rel.stick_y = newY * 60.5f;
}
