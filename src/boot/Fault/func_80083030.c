// FLAGS: -O2 -g3 -mips2 -nostdinc -Wab,-r4300_mul -D_MIPS_SZLONG=32 -DF3DEX_GBI_2 -DF3DEX_GBI_PL -DGBI_DOWHILE -DMM_VERSION=N64_US -D_LANGUAGE_C -Iinclude/mm -Iinclude/mm/libc -trapuv
#include "generated/mm/fault_ctx.h"

void Fault_WalkStack(uintptr_t* spPtr, uintptr_t* pcPtr, uintptr_t* raPtr) {
    uintptr_t sp = *spPtr;
    uintptr_t pc = *pcPtr;
    uintptr_t ra = *raPtr;
    u32 lastInsn;
    u16 insnHi;
    s16 insnLo;
    u32 imm;

    if ((sp % 4 != 0) || (sp < K0BASE) || (sp >= K2BASE) || (ra % 4 != 0) || (ra < K0BASE) || (ra >= K2BASE)) {
        *spPtr = 0;
        *pcPtr = 0;
        *raPtr = 0;
        return;
    }

    if ((pc % 4 != 0) || (pc < K0BASE) || (pc >= K2BASE)) {
        *pcPtr = ra;
        return;
    }

    lastInsn = 0;
    while (true) {
        insnHi = *(uintptr_t*)pc >> 16;
        insnLo = *(uintptr_t*)pc & 0xFFFF;
        imm = insnLo;

        if (insnHi == 0x8FBF) {


            ra = *(uintptr_t*)(sp + imm);
        } else if (insnHi == 0x27BD) {


            sp += imm;
        } else if (*(uintptr_t*)pc == 0x42000018) {


            sp = 0;
            pc = 0;
            ra = 0;
            goto done;
        }
        if (lastInsn == 0x3E00008) {


            pc = ra;
            goto done;
        } else if (lastInsn >> 26 == 2) {


            pc = (pc >> 28 << 28) | (lastInsn << 6 >> 4);
            goto done;
        }

        lastInsn = *(uintptr_t*)pc;
        pc += sizeof(u32);
    }

    done:
    *spPtr = sp;
    *pcPtr = pc;
    *raPtr = ra;
}
