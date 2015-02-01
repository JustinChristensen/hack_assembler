#include "../../include/symbol_table.h"
#include <strhash.h>

struct symbol_table {
    hash_table *table;
};

struct symbol_table *init_symbol_table()
{
    struct symbol_table *st;

    if ((st = malloc(sizeof *st))) {
        st->table = hash_create(SYMBOL_TABLE_SIZE);

        if (st->table) {
            add_entry(st, "SP", 0x0);
            add_entry(st, "LCL", 0x1);
            add_entry(st, "ARG", 0x2);
            add_entry(st, "THIS", 0x3);
            add_entry(st, "THAT", 0x4);
            add_entry(st, "R0", 0x0);
            add_entry(st, "R1", 0x1);
            add_entry(st, "R2", 0x2);
            add_entry(st, "R3", 0x3);
            add_entry(st, "R4", 0x4);
            add_entry(st, "R5", 0x5);
            add_entry(st, "R6", 0x6);
            add_entry(st, "R7", 0x7);
            add_entry(st, "R8", 0x8);
            add_entry(st, "R9", 0x9);
            add_entry(st, "R10", 0xa);
            add_entry(st, "R11", 0xb);
            add_entry(st, "R12", 0xc);
            add_entry(st, "R13", 0xd);
            add_entry(st, "R14", 0xe);
            add_entry(st, "R15", 0xf);
            add_entry(st, "SCREEN", 0x4000);
            add_entry(st, "KBD", 0x6000);
        }
        else {
            destroy_symbol_table(st);
            st = NULL;
        }
    }

    return st;
}

static void __replace__(void *datum)
{
    free(datum);
}

void add_entry(struct symbol_table *st, const char *symbol, unsigned short address)
{
    if (address != SYMBOL_NOT_FOUND) {
        unsigned short *entry = malloc(sizeof *entry);

        if (entry) {
            *entry = address;
            hash_search(st->table, (char *) symbol, entry, __replace__);
        }
        else {
            fprintf(stderr, "Could not allocate memory for entry.\n");
        }
    }
}

bool contains(struct symbol_table *st, const char *symbol)
{
    return get_address(st, symbol) != SYMBOL_NOT_FOUND;
}

unsigned short get_address(struct symbol_table *st, const char *symbol)
{
    short *address = hash_search(st->table, (char *) symbol, NULL, NULL);
    return address ? *address : SYMBOL_NOT_FOUND;
}

static void __destroy__(char *key, void *datum)
{
    free(key);
    free(datum);
}

void destroy_symbol_table(struct symbol_table *st)
{
    if (st->table) {
        hash_purge(st->table, __destroy__);
        free(st->table->buckets);
    }

    free(st->table);
    free(st);
}
