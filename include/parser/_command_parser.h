#ifndef COMMAND_PARSER_H_
#define COMMAND_PARSER_H_ 1

#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#include "../types/_parser.h"

/**

    command     ::= c-command {set command_type} | a-command {set command_type} | l-command {set command_type}
    c-command   ::= dest comp jump
    a-command   ::= '@' symbol {set symbol} | '@' constant {set symbol}
    l-command   ::= '(' symbol {set symbol} ')'
    dest            ::= dest-mnemonic {set dest} '=' | E
    comp            ::= comp-mnemonic {set comp}
    jump            ::= ';' jump-mnemonic {set jump} | E

    symbol
    constant
    dest-mnemonic
    comp-mnemonic
    jump-mnemonic

*/

static char buffer[BUFSIZ];
static const char *cp;

static char *comp_start = "AMD01-!";
static char *comp_sep = "=;";
static char *sym_special = "_.$:";

static void parse_error(const char *error, const char *command)
{
    fprintf(stderr, "Invalid command: %s\n %s\n", error, command);
}

static bool is_symbol(const char c)
{
    return isalpha(c) || strchr(sym_special, c) != NULL;
}

static bool is_comp(const char c)
{
    return strchr(comp_start, c) != NULL;
}

static bool parse_symbol(struct parser *parser)
{
    bool success = false;
    char *bp = buffer;

    while (isalnum(*cp) || strchr(sym_special, *cp) != NULL)
        *bp++ = *cp++;

    *bp = '\0';

    if (isspace(*cp) || *cp == ')')
        success = true;

    return success;
}

static bool parse_constant(struct parser *parser)
{
    bool success = false;
    char *bp = buffer;

    while (isdigit(*cp))
        *bp++ = *cp++;

    if (isspace(*cp))
        success = true;

    *bp = '\0';

    return success;
}

static bool parse_compute(struct parser *parser)
{
    bool success = false;
    char *bp = buffer;
    int n = 3;

    while (n > 0 && !isspace(*cp) && strchr(comp_sep, *cp) == NULL) {
        *bp++ = *cp++;
        n--;
    }

    *bp = '\0';

    if (isspace(*cp) && *cp != '\n') {
        while (*cp != '\n')
            cp++;
    }

    if (parser->dest[0] == '\0' && *cp == '=') {
        strncpy(parser->dest, buffer, 4);
        cp++;
        success = parse_compute(parser);
    }
    else if (parser->comp[0] == '\0' && (*cp == ';' || *cp == '\n')) {
        strncpy(parser->comp, buffer, 4);

        if (*cp == ';') {
            cp++;
            parse_compute(parser);
        }

        success = true;
    }
    else if (parser->jump[0] == '\0' && *cp == '\n') {
        strncpy(parser->jump, buffer, 4);
    }
    else {
        parse_error("malformed compute command", parser->command);
    }

    return success;
}

static bool parse_assign(struct parser *parser)
{
    bool success = false;

    cp++;

    if (isdigit(*cp)) {
        if (parse_constant(parser)) {
            while (isblank(*cp) || *cp == '\r')
                cp++;

            if (*cp == '\n') {
                strncpy(parser->symbol, buffer, BUFSIZ);
                success = true;
            }
            else {
                parse_error("trailing characters remain", parser->command);
            }
        }
        else {
            parse_error("assignment operand must be a valid constant or symbol", parser->command);
        }
    }
    else if (is_symbol(*cp)) {
        if (parse_symbol(parser)) {
            while (isblank(*cp) || *cp == '\r')
                cp++;

            if (*cp == '\n') {
                strncpy(parser->symbol, buffer, BUFSIZ);
                success = true;
            }
            else {
                parse_error("trailing characters remain", parser->command);
            }
        }
        else {
            parse_error("assignment operand must be a valid constant or symbol", parser->command);
        }
    }
    else {
        parse_error("assignment operand must be a valid constant or symbol", parser->command);
    }

    return success;
}

static bool parse_label(struct parser *parser)
{
    bool success = false;

    cp++;

    if (is_symbol(*cp)) {
        if (parse_symbol(parser)) {
            while (isblank(*cp))
                cp++;

            if (*cp == ')') {
                strncpy(parser->symbol, buffer, BUFSIZ);
                success = true;
            }
            else {
                parse_error("expected closing right parenthesis", parser->command);
            }
        }
        else {
            parse_error("label must be a valid symbol", parser->command);
        }
    }
    else {
        parse_error("label must be a valid symbol", parser->command);
    }

    return success;
}

static bool parse_command(struct parser *parser)
{
    bool success = false;
    cp = parser->command;

    while (isblank(*cp))
        cp++;

    if (is_comp(*cp)) {
        success = parse_compute(parser);
        parser->command_type = C_COMMAND;
    }
    else if (*cp == '@') {
        success = parse_assign(parser);
        parser->command_type = A_COMMAND;
    }
    else if (*cp == '(') {
        success = parse_label(parser);
        parser->command_type = L_COMMAND;
    }

    return success;
}

#endif // COMMAND_PARSER_H_
