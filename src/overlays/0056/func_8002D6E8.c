#include "types.h"

typedef struct {
    /* 0x0000 */ u8 pad0[0x1CCC];
    /* 0x1CCC */ void *unk1CCC;
} Ovl0056Play;

extern void func_8082D500();
extern void func_80831040();

s32 func_8002D6E8(Ovl0056Play *play) {
    void *player = play->unk1CCC;

    func_8082D500(play, player);
    func_80831040(play, player, 0x5C);
    return 1;
}
