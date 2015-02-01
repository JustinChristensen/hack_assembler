#ifndef TEST_HELPER_H_
#define TEST_HELPER_H_ 1

#include <check.h>
#include <stdio.h>
#include <stdbool.h>

static FILE *mock_file(const char *s)
{
    FILE *mock = tmpfile();

    if (mock != NULL) {
        if (fprintf(mock, "%s", s) != EOF) {
            rewind(mock);
        }
        else {
            perror(NULL);
            fclose(mock);
            mock = NULL;
        }
    }
    else {
        perror(NULL);
    }

    return mock;
}

#endif // TEST_HELPER_H_
