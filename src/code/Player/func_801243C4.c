#include "code_funcs.h"
// FLAGS: -O2 -g3 -mips2

s32 func_801243C4(u8 *arg0)
{
  s8 *new_var;
  new_var = (s8 *) (*((u8 **) (((s8 *) arg0) + 0x1CCC)));
  return (*((s32 *) (new_var + 0xA6C))) & 0x800000;
}
