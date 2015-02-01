#include "../../include/parser.h"
#include "../../include/types/_parser.h"
#include "../../include/parser/_command_parser.h"

static void truncate_parser_fields(struct parser *parser) {
    parser->symbol[0] = '\0';
    parser->comp[0] = '\0';
    parser->dest[0] = '\0';
    parser->jump[0] = '\0';
}

struct parser *init_parser(FILE *in)
{
    struct parser *parser;

    if ((parser = malloc(sizeof *parser))) {
        struct stat stbuf;

        if (fstat(fileno(in), &stbuf) != EOF) {
            if (stbuf.st_size > 0) {
                setbuffer(in, NULL, stbuf.st_size > stbuf.st_blksize ?
                    stbuf.st_blksize : stbuf.st_size);
            }
        }

        parser->in = in;

        char c = getc(in);
        ungetc(c, in);
    }

    return parser;
}

bool has_more_commands(struct parser *parser)
{
    bool found_command = false;

    while (!found_command && fgets(parser->command, BUFSIZ, parser->in)) {
        char *cp = parser->command;

        while (isblank(*cp))
            cp++;

        if (*cp == '@' || *cp == '(' || strchr("AMD01-!", *cp) != NULL)
            found_command = true;
    }

    return found_command;
}

void advance(struct parser *parser)
{
    bool found_command = false;

    truncate_parser_fields(parser);

    do {
        found_command = parse_command(parser);
    }
    while (!found_command && fgets(parser->command, BUFSIZ, parser->in));
}

const enum command_type command_type(struct parser *parser)
{
    return parser->command_type;
}

const char *symbol(struct parser *parser)
{
    return parser->symbol[0] != '\0' ? parser->symbol : NULL;
}

const char *dest(struct parser *parser)
{
    return parser->dest[0] != '\0' ? parser->dest : NULL;
}

const char *comp(struct parser *parser)
{
    return parser->comp[0] != '\0' ? parser->comp : NULL;
}

const char *jump(struct parser *parser)
{
    return parser->jump[0] != '\0' ? parser->jump : NULL;
}

void destroy_parser(struct parser *parser)
{
    free(parser);
}

