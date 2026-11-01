#include "generated/code_funcs.h"
// FLAGS: -O2 -g3 -mips2

extern unsigned char D_801AF0D4;
u8 func_800A869C(s32 arg0)
{
  if ((arg0 < 0) || (arg0 >= 0x20))
  {
    return 0U;
  }
  return *((&D_801AF0D4) + arg0);
}
