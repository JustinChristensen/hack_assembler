#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "../include/symbol_table.h"
#include "../include/parser.h"
#include "../include/code_generator.h"

int main(int argc, char *argv[])
{
    int exit_status = EXIT_SUCCESS;

    printf("%d\n", INST("AMD=", "1", "JMP"));

    fclose(stdin);
    fclose(stdout);

    return exit_status;
}
