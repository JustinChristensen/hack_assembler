#include "../../include/symbol_table.h"

struct symbol_table {
    int size;
};

struct symbol_table *init_symbol_table()
{
    struct symbol_table *st;

    if ((st = malloc(sizeof *st))) {
        st->size = 0;
    }

    return st;
}

void add_entry(struct symbol_table *st, const char *symbol, int address)
{

}

bool contains(struct symbol_table *st, const char *symbol)
{
    return true;
}

int get_address(struct symbol_table *st, const char *symbol)
{
    return 0;
}

void destroy_symbol_table(struct symbol_table *st)
{
    free(st);
}
