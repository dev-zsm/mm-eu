#include "types.h"

typedef struct { u8 pad0[0x7978]; u8 a; u8 b; u8 c; u8 pad1[0x0D]; void *q1; void *q2; void *q3; } Hdr;
extern Hdr D_801F84B0;
extern u8 D_801FFE44[], D_801FFE5C[], D_801FFE74[], D_801FFE8C[], D_801FFE90[], D_801FFE94[];
extern void func_8008F3E0(void *q, void *buf, s32 n);

void AudioThread_InitMesgQueuesInternal(void) {
    D_801F84B0.a = 0;
    D_801F84B0.b = 0;
    D_801F84B0.c = 0;
    D_801F84B0.q2 = D_801FFE44;
    D_801F84B0.q3 = D_801FFE5C;
    D_801F84B0.q1 = D_801FFE74;
    func_8008F3E0(D_801FFE44, D_801FFE8C, 1);
    func_8008F3E0(D_801F84B0.q3, D_801FFE94, 4);
    func_8008F3E0(D_801F84B0.q1, D_801FFE90, 1);
}
