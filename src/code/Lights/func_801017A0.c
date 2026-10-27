#include "types.h"

typedef struct {
    u8 unk0;
    u8 pad1;
    s16 unk2;
    s16 unk4;
    s16 unk6;
} LightPoint;

extern void Lights_PointSetColorAndRadius(LightPoint *arg0, u8 arg1, u8 arg2, u8 arg3, s16 arg4);

void Lights_PointSetInfo(LightPoint *arg0, s16 arg1, s16 arg2, s16 arg3, u8 arg4, u8 arg5, u8 arg6, s16 arg7, s32 arg8) {
    arg0->unk0 = arg8;
    arg0->unk2 = arg1;
    arg0->unk4 = arg2;
    arg0->unk6 = arg3;
    Lights_PointSetColorAndRadius(arg0, arg4, arg5, arg6, arg7);
}
