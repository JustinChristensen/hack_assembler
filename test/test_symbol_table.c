#include "helper.h"
#include "../src/symbol_table/symbol_table.h"

int comparator(const void *a, const void *b)
{
    return 0;
}

START_TEST(test_can_init_symbol_table)
{
    struct symbol_table *st = init_symbol_table(NULL);
    ck_assert_ptr_ne(st, NULL);
    destroy_symbol_table(st);
    st = NULL;

    st = init_symbol_table(comparator);
    ck_assert_ptr_ne(st, NULL);
    destroy_symbol_table(st);
}
END_TEST

START_TEST(test_symbol_table_put)
{

}
END_TEST

START_TEST(test_symbol_table_get)
{

}
END_TEST

START_TEST(test_symbol_table_delete)
{

}
END_TEST

START_TEST(test_symbol_table_contains)
{

}
END_TEST

START_TEST(test_symbol_table_is_empty)
{

}
END_TEST

START_TEST(test_symbol_table_size)
{

}
END_TEST

START_TEST(test_symbol_table_iteration)
{

}
END_TEST


int main(void)
{
    Suite *s1 = suite_create("Symbol Table");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_can_init_symbol_table);
    tcase_add_test(tc1_1, test_symbol_table_put);
    tcase_add_test(tc1_1, test_symbol_table_get);
    tcase_add_test(tc1_1, test_symbol_table_delete);
    tcase_add_test(tc1_1, test_symbol_table_contains);
    tcase_add_test(tc1_1, test_symbol_table_is_empty);
    tcase_add_test(tc1_1, test_symbol_table_size);
    tcase_add_test(tc1_1, test_symbol_table_iteration);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
