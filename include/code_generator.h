#ifndef CODE_GENERATOR_H_
#define CODE_GENERATOR_H_ 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CG_COMP_INST 0xe000
#define INST(A, B, C) \
    CG_COMP_INST | cg_dest((A)) | cg_comp((B)) | cg_jump((C))

const short cg_dest(const char *mnemonic);
const short cg_comp(const char *mnemonic);
const short cg_jump(const char *mnemonic);
const char *ustobs(const unsigned short instruction);

#endif // CODE_GENERATOR_H_
