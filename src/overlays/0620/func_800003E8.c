// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc
#include "generated/mm/z_obj_mu_pict.h"

void ref_func_80C06E88(ObjMuPict* this, PlayState* play) {
    if (Message_ShouldAdvance(play)) {
        switch (this->textId) {
            case 0x159A:
                Message_StartTextbox(play, 0x159B, &this->actor);
                this->textId = 0x159B;
                break;

            case 0x159B:
                Message_StartTextbox(play, 0x159C, &this->actor);
                this->textId = 0x159C;
                break;

            case 0x159D:
                Message_StartTextbox(play, 0x159E, &this->actor);
                this->textId = 0x159E;
                break;

            case 0x159E:
                Message_StartTextbox(play, 0x159F, &this->actor);
                this->textId = 0x159F;
                break;

            case 0x15A0:
                Message_StartTextbox(play, 0x15A1, &this->actor);
                this->textId = 0x15A1;
                break;

            case 0x15A1:
                Message_StartTextbox(play, 0x15A2, &this->actor);
                this->textId = 0x15A2;
                break;

            case 0x15A3:
                Message_StartTextbox(play, 0x15A4, &this->actor);
                this->textId = 0x15A4;
                break;
        }
    }
}
