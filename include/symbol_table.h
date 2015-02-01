#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_ 1

#ifndef SYMBOL_TABLE_SIZE
#define SYMBOL_TABLE_SIZE 256
#endif

#define SYMBOL_NOT_FOUND 0xffff

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct symbol_table;

struct symbol_table *init_symbol_table();
void add_entry(struct symbol_table *st, const char *symbol, unsigned short address);
bool contains(struct symbol_table *st, const char *symbol);
unsigned short get_address(struct symbol_table *st, const char *symbol);
void destroy_symbol_table(struct symbol_table *st);

#endif // SYMBOL_TABLE_H_
