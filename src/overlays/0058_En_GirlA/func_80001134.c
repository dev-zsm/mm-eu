#include "types.h"
#include "actor.h"

void EnGirlA_Update(Actor *thisx) {
    (*(void (**)(u8 *))((u8 *)thisx + 0x190))(thisx);
}
