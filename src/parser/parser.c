#include "../../include/parser.h"

struct parser {
    int size;
};

struct parser *init_parser()
{
    struct parser *parser;

    if ((parser = malloc(sizeof *parser))) {
        parser->size = 0;
    }

    return parser;
}

void advance(struct parser *parser)
{

}

const enum command_type command_type(struct parser *parser)
{
    return A_COMMAND;
}

const char *symbol(struct parser *parser)
{
    return NULL;
}

const char *dest(struct parser *parser)
{
    return NULL;
}

const char *comp(struct parser *parser)
{
    return NULL;
}

const char *jump(struct parser *parser)
{
    return NULL;
}

void destroy_parser(struct parser *parser)
{
    free(parser);
}

