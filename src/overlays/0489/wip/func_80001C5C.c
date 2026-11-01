// matching: ROM copies this into a2 and the u16 argument into a3; 8 instr differ
#include "types.h"
typedef struct { u8 pad0[0x376]; u16 unk376; } A;
extern void func_80151DF4();

void func_80001C5C(A *thisx, s32 play, u16 arg) {
A *this = thisx;
this->unk376 = arg;
func_80151DF4(play, this->unk376 & 0xFFFF);
}
