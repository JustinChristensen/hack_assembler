#ifndef PARSER_H_
#define PARSER_H_ 1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/stat.h>

struct parser;

#include "types/command_type.h"

struct parser *init_parser(FILE *in);
bool has_more_commands(struct parser *parser);
void advance(struct parser *parser);
const enum command_type command_type(struct parser *parser);
const char *symbol(struct parser *parser);
const char *dest(struct parser *parser);
const char *comp(struct parser *parser);
const char *jump(struct parser *parser);
void destroy_parser(struct parser *parser);

#endif // PARSER_H_
