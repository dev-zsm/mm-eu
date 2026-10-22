// FLAGS: -O2 -g3 -mips2
#include "types.h"

s32 MapDisp_GetSizeOfMapITex(s32);                             /* extern */

s32 MapData_MapITexSizeTest(s32 arg0) {
    s32 temp_s2;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;

    temp_s2 = arg0 + 1;
    var_s1 = 0;
    var_s0 = 1;
    if (temp_s2 >= 2) {
        do {
            temp_v0 = MapDisp_GetSizeOfMapITex(var_s0 - 1);
            var_s0 += 1;
            var_s1 += temp_v0;
        } while (var_s0 != temp_s2);
    }
    return var_s1;
}
