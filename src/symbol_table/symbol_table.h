#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_ 1

#include <stdlib.h>
#include <stdbool.h>

struct symbol_table;

struct symbol_table *init_symbol_table(int (*comp)(const void *a, const void *b));
void st_put(void *st, const void *key, void *value, int (*comp)(const void *a, const void *b));
void *st_get(void *st, const void *key, int (*comp)(const void *a, const void *b));
void st_delete(void *st, const void *key, int (*comp)(const void *a, const void *b));
bool st_contains(void *st, const void *key, int (*comp)(const void *a, const void *b));
bool st_is_empty(void *st);
int st_size(void *st);
const void *st_next_key(void *st);
void destroy_symbol_table(struct symbol_table *st);

#endif // SYMBOL_TABLE_H_
