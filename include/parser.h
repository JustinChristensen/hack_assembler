#ifndef PARSER_H_
#define PARSER_H_ 1

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct parser;

enum command_type {
    A_COMMAND,
    C_COMMAND,
    L_COMMAND
};

struct parser *init_parser();
void advance(struct parser *parser);
const enum command_type command_type(struct parser *parser);
const char *symbol(struct parser *parser);
const char *dest(struct parser *parser);
const char *comp(struct parser *parser);
const char *jump(struct parser *parser);
void destroy_parser(struct parser *parser);

#endif // PARSER_H_
