#include "types.h"

extern void Setup_Init(void);
extern void func_8016B450(void);
extern u8 D_80801B6C[];
extern u8 D_80800768[];
extern u8 D_80803F50[];
extern u8 D_80815250[];
extern u8 D_808176A0[];
extern u8 D_801BE440[];
extern u8 D_801BE470[];
extern u8 D_801BE4A0[];
extern u8 D_801BE4D0[];
extern u8 D_801BE500[];
extern u8 D_801BE530[];
extern u8 D_801BE560[];
extern void *GameState_GetInit(void);

void *Graph_GetNextGameState(void) {
    void *r = GameState_GetInit();

    if (r == Setup_Init) {
        return D_801BE440;
    }
    if (r == D_80801B6C) {
        return D_801BE470;
    }
    if (r == D_80800768) {
        return D_801BE4A0;
    }
    if (r == func_8016B450) {
        return D_801BE4D0;
    }
    if (r == D_80803F50) {
        return D_801BE500;
    }
    if (r == D_80815250) {
        return D_801BE530;
    }
    if (r == D_808176A0) {
        return D_801BE560;
    }
    return 0;
}
