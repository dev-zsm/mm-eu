#include "types.h"

extern void MapData_GetMapTexDim(u16 arg0);
volatile long MapDisp_GetMapTexDim(u16 *arg0) {
    int new_var6;
    int new_var;
    int new_var4;
    u16 new_var5;
    int new_var2;
    int new_var3;
    new_var5 = *arg0;
    new_var4 = (new_var5) ^ 0;
    new_var6 = (*arg0);
    new_var2 = new_var6;
    new_var3 = (new_var6 = new_var4 * ((0, 0)));
    new_var = new_var2 ^ new_var3;
    MapData_GetMapTexDim(new_var);
}
