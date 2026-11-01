#include "types.h"
#include "generated/code_funcs.h"


s32 MapData_MapGrandTexSizeTest(s32 count) {
    s32 last = count - 0x100;
    s32 total = 0;
    s32 i = 1;

    if (count - 0xFF >= 2) {
        do {
            total += MapData_GetSizeOfMapGrandTex(i + 0xFF);
            i++;
        } while (i < last + 1);
    }
    return total;
}
