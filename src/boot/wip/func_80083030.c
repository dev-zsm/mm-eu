// FLAGS: -O2 -g3 -mips2 -trapuv
#include "types.h"

void Fault_WalkStack(u32 *spPtr, u32 *pcPtr, u32 *raPtr) {
    u32 sp = *spPtr;
    u32 pc = *pcPtr;
    u32 ra = *raPtr;
    u32 lastInstruction;
    u32 instruction;
    u16 opcode;
    s16 imm;

    if ((sp & 3) || sp < 0x80000000 || sp >= 0xC0000000 || (ra & 3) || ra < 0x80000000 || ra >= 0xC0000000) {
        *spPtr = 0;
        *pcPtr = 0;
        *raPtr = 0;
        return;
    }
    if ((pc & 3) || pc < 0x80000000 || pc >= 0xC0000000) {
        *pcPtr = ra;
        return;
    }
    lastInstruction = 0;
    while (1) {
        instruction = *(u32 *)pc;
        opcode = instruction >> 16;
        imm = instruction;
        if (opcode == 0x8FBF) {
            ra = *(u32 *)(sp + imm);
        } else if (opcode == 0x27BD) {
            sp += imm;
        } else if (instruction == 0x42000018) {
            sp = 0;
            pc = 0;
            ra = 0;
            break;
        }
        if (lastInstruction == 0x03E00008) {
            pc = ra;
            break;
        }
        if ((lastInstruction >> 26) == 2) {
            pc = (pc & 0xF0000000) | ((lastInstruction << 6) >> 4);
            break;
        }
        lastInstruction = instruction;
        pc += 4;
    }
    *spPtr = sp;
    *pcPtr = pc;
    *raPtr = ra;
}
