#include "types.h"

extern u8 D_801AF270[];
extern u8 D_801AF274[];

extern void EffectSsDust_Spawn(void *play, s32 type, void *arg2, void *arg3, void *arg4, u8 *arg5, u8 *arg6, s16 arg7, s16 arg8, s32 life, s32 flags);

void func_800B1650(void *play, void *arg1, void *arg2, void *arg3) {
    EffectSsDust_Spawn(play, 5, arg1, arg2, arg3, D_801AF270, D_801AF274, 100, 5, 10, 0);
}
