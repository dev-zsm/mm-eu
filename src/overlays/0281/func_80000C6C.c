#include "types.h"
#include "m2c_compat.h"

typedef struct { u8 pad0[0x18840]; s32 unk18840; } S_arg0;
typedef struct { s16 unk0; s16 unk2; s16 unk4; } S_arg4;
typedef struct { u8 pad0[0x2A2]; s16 unk2A2; s16 unk2A4; s16 unk2A6; s16 unk2A8; } S_arg5;

s32 func_80000C6C(S_arg0 *arg0, s32 arg1, s32 *arg2, M2C_UNK arg3, S_arg4 *arg4, S_arg5 *arg5) {
    S_arg5 *this = arg5;
    if ((arg1 == 0) && (arg0->unk18840 & 1)) {
        *arg2 = 0;
    }
    if (arg1 == 0) {
        arg4->unk0 = (s16) arg4->unk0;
        arg4->unk2 = (s16) arg4->unk2;
        arg4->unk4 = (s16) arg4->unk4;
    }
    switch (arg1) {                                 /* irregular */
        case 8:
            arg4->unk0 = (s16) (arg4->unk0 + arg5->unk2A4);
            arg4->unk4 = (s16) (arg4->unk4 + arg5->unk2A2);
            break;
        case 15:
            arg4->unk0 = (s16) (arg4->unk0 + arg5->unk2A8);
            arg4->unk4 = (s16) (arg4->unk4 + arg5->unk2A6);
            break;
    }
    return 0;
}
