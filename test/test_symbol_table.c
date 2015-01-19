#include "helper.h"
#include "../include/symbol_table.h"

static struct symbol_table *st;

START_TEST(test_add_entry)
{
}
END_TEST

START_TEST(test_contains)
{
}
END_TEST

START_TEST(test_get_address)
{
}
END_TEST

static void __setup__()
{
    st = init_symbol_table();

    if (st == NULL) {
        ck_abort_msg("Could not allocate memory for the symbol table.");
    }
}

static void __teardown__()
{
    destroy_symbol_table(st);
}


int main(void)
{
    Suite *s1 = suite_create("Symbol Table");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_checked_fixture(tc1_1, __setup__, __teardown__);
    tcase_add_test(tc1_1, test_add_entry);
    tcase_add_test(tc1_1, test_contains);
    tcase_add_test(tc1_1, test_get_address);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
