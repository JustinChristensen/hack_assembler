#include "symbol_table.h"

struct symbol_table {
    int size;
    int (*comp)(const void *a, const void *b);
};

struct symbol_table *init_symbol_table(int (*comp)(const void *a, const void *b))
{
    struct symbol_table *st = malloc(sizeof *st);

    if (comp != NULL) {
        st->comp = comp;
    }

    st->size = 0;

    return st;
}

void st_put(void *st, const void *key, void *value, int (*comp)(const void *a, const void *b))
{

}

void *st_get(void *st, const void *key, int (*comp)(const void *a, const void *b))
{
    return NULL;
}

void st_delete(void *st, const void *key, int (*comp)(const void *a, const void *b))
{
    st_put(st, key, NULL, comp);
}

bool st_contains(void *st, const void *key, int (*comp)(const void *a, const void *b))
{
    return st_get(st, key, comp) != NULL;
}

bool st_is_empty(void *st)
{
    return st_size(st) == 0;
}

int st_size(void *st)
{
    return ((struct symbol_table *) st)->size;
}

const void *st_next_key(void *st)
{
    return NULL;
}

void destroy_symbol_table(struct symbol_table *st)
{
    free(st);
}
