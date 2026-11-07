typedef struct A { char pad[0x144]; void (*fn)(struct A *, int); } A;
void func_800B680C();
void EnBu_Update(A *a, int b) { func_800B680C(a); a->fn(a, b); }
