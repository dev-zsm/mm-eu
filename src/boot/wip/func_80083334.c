// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

typedef struct {
    u8 pad0[0xF4];
    u32 sp;
    u8 pad1[0x104 - 0xF8];
    u32 ra;
    u8 pad2[0x11C - 0x108];
    u32 pc;
} Obj80083334;

extern void func_8008198C(void *a0, ...);
extern u32 Fault_ConvertAddress(u32 a0);
extern void Fault_WalkStack(u32 *sp, u32 *pc, u32 *ra);
extern u8 D_80098C5C[];
extern u8 D_80098C68[];
extern u8 D_80098C84[];
extern u8 D_80098C90[];
extern u8 D_80098C9C[];
extern u8 D_80098CAC[];
extern u8 D_800895C0[];

void Fault_LogStackTrace(Obj80083334 *thread, u32 flags) {
    s32 line;
    u32 sp = thread->sp;
    u32 ra = thread->ra;
    u32 pc = thread->pc;

    func_8008198C(D_80098C5C);
    func_8008198C(D_80098C68);
    for (line = 1; line < 0x16 && (ra != 0 || sp != 0) && pc != (u32)D_800895C0; line++) {
        func_8008198C(D_80098C84, sp);
        if (flags & 1) {
            u32 addr = Fault_ConvertAddress(pc);
            if (addr != 0) {
                func_8008198C(D_80098C90, addr);
            }
        } else {
            func_8008198C(D_80098C9C);
        }
        func_8008198C(D_80098CAC);
        Fault_WalkStack(&sp, &pc, &ra);
    }
}
