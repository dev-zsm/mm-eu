#include "code_funcs.h"
// FLAGS: -O2 -g3 -mips2

extern s32 D_801E7DB0;
s16 func_8012F5DC(s16 arg0)
{
  if (arg0 == 0x27)
  {
    return (s16) (((u32) (D_801E7DB0 & 0xFFFF0000)) >> 0x10);
  }
  return (s16) (D_801E7DB0 ^ 0);
}
