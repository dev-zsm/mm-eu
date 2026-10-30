#ifndef PADUTILS_H
#define PADUTILS_H

#include "os_cont.h"

/* Controller state of one frame. Only cur, press and rel are read by PadUtils; the field at 0x06 is
 * not touched by it. */
typedef struct {
    /* 0x00 */ OSContPad cur;
    /* 0x06 */ OSContPad prev;
    /* 0x0C */ OSContPad press;  /* buttons pressed this frame */
    /* 0x12 */ OSContPad rel;    /* button field: buttons released this frame; sticks: stick offset past the dead zone */
} Input;

s32 PadUtils_CheckCur(Input *input, u16 key);
s32 PadUtils_CheckPressed(Input *input, u16 key);
s32 PadUtils_CheckReleased(Input *input, u16 key);
u16 PadUtils_GetCurButton(Input *input);
u16 PadUtils_GetPressButton(Input *input);
s8 PadUtils_GetCurX(Input *input);
s8 PadUtils_GetCurY(Input *input);
void PadUtils_SetRelXY(Input *input, s32 x, s32 y);
s8 PadUtils_GetRelXImpl(Input *input);
s8 PadUtils_GetRelYImpl(Input *input);
s8 PadUtils_GetRelX(Input *input);
s8 PadUtils_GetRelY(Input *input);
void PadUtils_UpdateRelXY(Input *input);

#endif
