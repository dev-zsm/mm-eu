#include "types.h"
#include "actor.h"

void func_80001134(Actor *thisx) {
    (*(void (**)(u8 *))((u8 *)thisx + 0x190))(thisx);
}
