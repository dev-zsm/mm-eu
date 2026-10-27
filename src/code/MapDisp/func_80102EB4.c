#include "types.h"

extern void MapData_GetMapScale(u16 arg0);
void MapDisp_GetMapScale(u16 *arg0, s32 *arg1) {
    if (1) {
        MapData_GetMapScale(*arg0);
        if ((*arg1) == 0) {
            *arg1 = 0x14;
        }
    }
}
