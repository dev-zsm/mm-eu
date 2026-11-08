#include "types.h"
#include "generated/overlays/0109.h"

void DemoKankyo_Update(Actor *thisx) {
    (*(void (**)(u8 *))((u8 *)thisx + 0x1644))(thisx);
}
