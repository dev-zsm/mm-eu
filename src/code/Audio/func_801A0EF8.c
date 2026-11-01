#include "types.h"
#include "code_funcs.h"

typedef struct {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    s32 unkC;
} Fade;

extern Fade D_801F4AB8;
extern u8 D_801D3DE8;

void Audio_PlaySfx_Waterfall(s32 arg0, f32 arg1) {
    if (AudioSfx_IsPlaying(0x2007) == 0) {
        D_801F4AB8.unk0 = arg1;
    } else if (arg1 != D_801F4AB8.unk0) {
        D_801F4AB8.unk4 = arg1;
        D_801F4AB8.unkC = 0x28;
        D_801F4AB8.unk8 = (D_801F4AB8.unk4 - D_801F4AB8.unk0) / 40.0f;
    }
    AudioSfx_PlaySfx(0x2007, arg0, 4, &D_801F4AB8, &D_801F4AB8, &D_801D3DE8);
}
