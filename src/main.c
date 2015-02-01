#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/symbol_table.h"
#include "../include/parser.h"
#include "../include/code_generator.h"

int main(int argc, char *argv[])
{
    int exit_status = EXIT_SUCCESS;
    FILE *in;

    if (argc > 1) {
        if ((in = fopen(argv[1], "r")) == NULL) {
            perror(NULL);
        }
        else {
            in = stdin;
        }
    }
    else {
        in = stdin;
    }

    struct parser *parser = init_parser(in);

    if (parser) {
        struct symbol_table *st = init_symbol_table();

        if (st) {
            int line_no = 0;
            int variable = 0x10;
            const char *s;

            while (has_more_commands(parser)) {
                advance(parser);

                switch (command_type(parser)) {
                    case L_COMMAND:
                        add_entry(st, symbol(parser), line_no);
                        break;
                    case A_COMMAND:
                        line_no++;
                        break;
                    case C_COMMAND:
                        line_no++;
                        break;
                }
            }

            rewind(in);

            while (has_more_commands(parser)) {
                advance(parser);

                switch (command_type(parser)) {
                    case C_COMMAND:
                        printf("%s\n", ustobs(INST(dest(parser), comp(parser), jump(parser))));
                        break;
                    case A_COMMAND:
                        s = symbol(parser);

                        if (s && !isdigit(s[0])) {
                            if (get_address(st, s) == SYMBOL_NOT_FOUND)
                                add_entry(st, s, variable++);
                        }

                        printf("%s\n", ustobs(s && isdigit(s[0]) ? atoi(s) : get_address(st, s)));
                        break;
                    case L_COMMAND:
                        break;
                }
            }

            destroy_symbol_table(st);
            st = NULL;

            destroy_parser(parser);
            parser = NULL;
        }
        else {
            destroy_parser(parser);
            parser = NULL;

            fprintf(stderr, "Could not allocate memory for the parser.\n");
            exit_status = EXIT_FAILURE;
        }
    }
    else {
        fprintf(stderr, "Could not allocate memory for the parser.\n");
        exit_status = EXIT_FAILURE;
    }

    fclose(in);
    fclose(stdout);

    return exit_status;
}
