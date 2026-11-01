// matching: constant load order differs (3 instructions)
typedef struct { char pad[0xA6C]; int unkA6C; } P;
typedef struct { char pad0[0x1CCC]; P *unk1CCC; char pad1[0x1F08-0x1CD0]; char unk1F08; char pad2[0xF]; unsigned short unk1F18; } G;
void func_80002918(int a, G *g) {
  P *p = g->unk1CCC;
  if (p->unkA6C << 11 < 0) { g->unk1F08 = 1; g->unk1F18 = 0x8000; } else { g->unk1F08 = 1; }
}
