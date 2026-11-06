// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mu_pict.h"

void ref_func_80C06DC8(ObjMuPict* this, PlayState* play) {
    if (this->unk14A == 0) {
        if (this->unk148 == 0) {
            this->unk148 = 1;
            Message_StartTextbox(play, 0x159A, &this->actor);
            this->textId = 0x159A;
        } else {
            Message_StartTextbox(play, 0x159D, &this->actor);
            this->textId = 0x159D;
        }
    } else if (this->unk148 == 0) {
        this->unk148 = 1;
        Message_StartTextbox(play, 0x15A0, &this->actor);
        this->textId = 0x15A0;
    } else {
        Message_StartTextbox(play, 0x15A3, &this->actor);
        this->textId = 0x15A3;
    }
}
