#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_ 1

#include <stdlib.h>
#include <stdbool.h>

struct symbol_table;

struct symbol_table *init_symbol_table();
void add_entry(struct symbol_table *st, const char *symbol, int address);
bool contains(struct symbol_table *st, const char *symbol);
int get_address(struct symbol_table *st, const char *symbol);
void destroy_symbol_table(struct symbol_table *st);

#endif // SYMBOL_TABLE_H_
