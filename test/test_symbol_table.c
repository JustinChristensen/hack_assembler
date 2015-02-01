#include "helper.h"
#include "../include/symbol_table.h"

static struct symbol_table *st;

START_TEST(test_add_entry)
{
    add_entry(st, "foo", 1);
    add_entry(st, "bar", 2);

    ck_assert(contains(st, "foo") == true);
    ck_assert(contains(st, "bar") == true);
    ck_assert(contains(st, "baz") == false);
}
END_TEST

START_TEST(test_get_address)
{
    add_entry(st, "foo", 15);
    add_entry(st, "bar", 25);

    ck_assert_int_eq(15, get_address(st, "foo"));
    ck_assert_int_eq(25, get_address(st, "bar"));
    ck_assert_int_eq(0xffff, get_address(st, "baz"));
}
END_TEST

START_TEST(test_predefined_symbols)
{
    ck_assert_int_eq(0x0, get_address(st, "SP"));
    ck_assert_int_eq(0x1, get_address(st, "LCL"));
    ck_assert_int_eq(0x2, get_address(st, "ARG"));
    ck_assert_int_eq(0x3, get_address(st, "THIS"));
    ck_assert_int_eq(0x4, get_address(st, "THAT"));
    ck_assert_int_eq(0x0, get_address(st, "R0"));
    ck_assert_int_eq(0x1, get_address(st, "R1"));
    ck_assert_int_eq(0x2, get_address(st, "R2"));
    ck_assert_int_eq(0x3, get_address(st, "R3"));
    ck_assert_int_eq(0x4, get_address(st, "R4"));
    ck_assert_int_eq(0x5, get_address(st, "R5"));
    ck_assert_int_eq(0x6, get_address(st, "R6"));
    ck_assert_int_eq(0x7, get_address(st, "R7"));
    ck_assert_int_eq(0x8, get_address(st, "R8"));
    ck_assert_int_eq(0x9, get_address(st, "R9"));
    ck_assert_int_eq(0xa, get_address(st, "R10"));
    ck_assert_int_eq(0xb, get_address(st, "R11"));
    ck_assert_int_eq(0xc, get_address(st, "R12"));
    ck_assert_int_eq(0xd, get_address(st, "R13"));
    ck_assert_int_eq(0xe, get_address(st, "R14"));
    ck_assert_int_eq(0xf, get_address(st, "R15"));
    ck_assert_int_eq(0x4000, get_address(st, "SCREEN"));
    ck_assert_int_eq(0x6000, get_address(st, "KBD"));
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
    tcase_add_test(tc1_1, test_get_address);
    tcase_add_test(tc1_1, test_predefined_symbols);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
