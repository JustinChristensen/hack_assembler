#include "../../include/code_generator.h"

#include "../../include/gen_dest.h"
#include "../../include/gen_comp.h"
#include "../../include/gen_jump.h"

enum {
    CG_JUMP_OFFSET = 0,
    CG_DEST_OFFSET = 3,
    CG_COMP_OFFSET = 6
};

#include <stdio.h>

const short cg_dest(const char *mnemonic)
{
    const struct cg_inst *inst_entry = NULL;
    short inst = 0;

    if (mnemonic) {
        inst_entry = lookup_dest(mnemonic, strlen(mnemonic));

        if (inst_entry) {
            inst = inst_entry->inst << CG_DEST_OFFSET;
        }
        else {
            fprintf(stderr, "Invalid dest mnemonic: \"%s\"\n", mnemonic);
            abort();
        }
    }

    return inst;
}

const short cg_comp(const char *mnemonic)
{
    const struct cg_inst *inst_entry = NULL;
    short inst = 0;

    if (mnemonic) {
        inst_entry = lookup_comp(mnemonic, strlen(mnemonic));

        if (inst_entry) {
            inst = inst_entry->inst << CG_COMP_OFFSET;
        }
        else {
            fprintf(stderr, "Invalid comp mnemonic: \"%s\"\n", mnemonic);
            abort();
        }
    }
    else {
        fprintf(stderr, "Comp mnemonic is not optional\n");
        abort();
    }

    return inst;
}

const short cg_jump(const char *mnemonic)
{
    const struct cg_inst *inst_entry = NULL;
    short inst = 0;

    if (mnemonic) {
        inst_entry = lookup_jump(mnemonic, strlen(mnemonic));

        if (inst_entry) {
            inst = inst_entry->inst << CG_JUMP_OFFSET;
        }
        else {
            fprintf(stderr, "Invalid jump mnemonic: \"%s\"\n", mnemonic);
            abort();
        }
    }

    return inst;
}
