#include "types.h"

void func_801622F0();
void CutsceneCamera_Interp_None();
void CutsceneCamera_Interp_Set();
void CutsceneCamera_Interp_Linear();
void CutsceneCamera_Interp_Scale();
void CutsceneCamera_Interp_MultiPointCubic();
void CutsceneCamera_Interp_MultiPointQuadratic();
void CutsceneCamera_Interp_Geo();

void *func_8016239C(u8 arg0) {
    switch (arg0) {
        default:
        case 7:
            return func_801622F0;
        case 0:
            return CutsceneCamera_Interp_None;
        case 5:
            return CutsceneCamera_Interp_MultiPointQuadratic;
        case 4:
            return CutsceneCamera_Interp_MultiPointCubic;
        case 1:
            return CutsceneCamera_Interp_Set;
        case 2:
            return CutsceneCamera_Interp_Linear;
        case 3:
            return CutsceneCamera_Interp_Scale;
        case 6:
            return CutsceneCamera_Interp_Geo;
    }
}
