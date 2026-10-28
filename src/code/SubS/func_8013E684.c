#include "types.h"

s32 func_800F1E2C(); // unprototyped: a0 (play) is forwarded untouched, a prototype would reload it
void func_800F1D6C(s16 a);
void CutsceneManager_Queue(s16 a);
s32 CutsceneManager_IsNext(s16 a);
void func_800F1A08(s16 a, s32 play);
void func_800F1B24(s16 a, s32 play);
void func_800F1A80(s16 a, s32 play);

s32 SubS_StartCutscene(s32 play, s16 csId, s16 csId2, s32 type) {
    s32 ret = 0;

    if (csId2 != -1 && func_800F1E2C() == csId2) {
        func_800F1D6C(csId2);
        CutsceneManager_Queue(csId);
    } else if (CutsceneManager_IsNext(csId) != 0) {
        switch (type) {
            case 0:
                func_800F1A08(csId, play);
                break;
            case 1:
                func_800F1B24(csId, play);
                break;
            case 2:
                func_800F1A80(csId, play);
                break;
        }
        ret = 1;
    } else {
        CutsceneManager_Queue(csId);
    }
    return ret;
}
