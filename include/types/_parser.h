#ifndef TYPE_PARSER_H_
#define TYPE_PARSER_H_ 1

#include <stdio.h>
#include "command_type.h"

struct parser {
    FILE *in;
    char command[BUFSIZ];
    char symbol[BUFSIZ];
    char comp[4];
    char dest[4];
    char jump[4];
    enum command_type command_type;
};

#endif // TYPE_PARSER_H_
