#include "helper.h"
#include "../include/code_generator.h"

START_TEST(test_cg_dest)
{
    ck_assert_int_eq(0x0, cg_dest(NULL));
    ck_assert_int_eq(0x8, cg_dest("M"));
    ck_assert_int_eq(0x10, cg_dest("D"));
    ck_assert_int_eq(0x18, cg_dest("MD"));
    ck_assert_int_eq(0x20, cg_dest("A"));
    ck_assert_int_eq(0x28, cg_dest("AM"));
    ck_assert_int_eq(0x30, cg_dest("AD"));
    ck_assert_int_eq(0x38, cg_dest("AMD"));
}
END_TEST

START_TEST(test_cg_dest_invalid_input)
{
    cg_dest("Foo");
}
END_TEST

START_TEST(test_cg_comp)
{
    ck_assert_int_eq(0xa80, cg_comp("0"));
    ck_assert_int_eq(0xfc0, cg_comp("1"));
    ck_assert_int_eq(0xe80, cg_comp("-1"));
    ck_assert_int_eq(0x300, cg_comp("D"));
    ck_assert_int_eq(0xc00, cg_comp("A"));
    ck_assert_int_eq(0x340, cg_comp("!D"));
    ck_assert_int_eq(0xc40, cg_comp("!A"));
    ck_assert_int_eq(0x3c0, cg_comp("-D"));
    ck_assert_int_eq(0xcc0, cg_comp("-A"));
    ck_assert_int_eq(0x7c0, cg_comp("D+1"));
    ck_assert_int_eq(0xdc0, cg_comp("A+1"));
    ck_assert_int_eq(0x380, cg_comp("D-1"));
    ck_assert_int_eq(0xc80, cg_comp("A-1"));
    ck_assert_int_eq(0x80, cg_comp("D+A"));
    ck_assert_int_eq(0x4c0, cg_comp("D-A"));
    ck_assert_int_eq(0x1c0, cg_comp("A-D"));
    ck_assert_int_eq(0x0, cg_comp("D&A"));
    ck_assert_int_eq(0x540, cg_comp("D|A"));
    ck_assert_int_eq(0x1c00, cg_comp("M"));
    ck_assert_int_eq(0x1c40, cg_comp("!M"));
    ck_assert_int_eq(0x1cc0, cg_comp("-M"));
    ck_assert_int_eq(0x1dc0, cg_comp("M+1"));
    ck_assert_int_eq(0x1c80, cg_comp("M-1"));
    ck_assert_int_eq(0x1080, cg_comp("D+M"));
    ck_assert_int_eq(0x14c0, cg_comp("D-M"));
    ck_assert_int_eq(0x11c0, cg_comp("M-D"));
    ck_assert_int_eq(0x1000, cg_comp("D&M"));
    ck_assert_int_eq(0x1540, cg_comp("D|M"));
}
END_TEST

START_TEST(test_cg_comp_required)
{
    cg_comp(NULL);
}
END_TEST

START_TEST(test_cg_comp_invalid_input)
{
    cg_comp("Foo");
}
END_TEST

START_TEST(test_cg_jump)
{
    ck_assert_int_eq(0x0, cg_jump(NULL));
    ck_assert_int_eq(0x1, cg_jump("JGT"));
    ck_assert_int_eq(0x2, cg_jump("JEQ"));
    ck_assert_int_eq(0x3, cg_jump("JGE"));
    ck_assert_int_eq(0x4, cg_jump("JLT"));
    ck_assert_int_eq(0x5, cg_jump("JNE"));
    ck_assert_int_eq(0x6, cg_jump("JLE"));
    ck_assert_int_eq(0x7, cg_jump("JMP"));
}
END_TEST

START_TEST(test_cg_jump_invalid_input)
{
    cg_jump("Foo");
}
END_TEST

START_TEST(test_ustobs)
{
    ck_assert_str_eq("1111111111111111", ustobs(65535));
    ck_assert_str_eq("0111111111111111", ustobs(32767));
    ck_assert_str_eq("0011111111111111", ustobs(16383));
    ck_assert_str_eq("0001111111111111", ustobs(8191));
    ck_assert_str_eq("0000111111111111", ustobs(4095));
    ck_assert_str_eq("0000011111111111", ustobs(2047));
    ck_assert_str_eq("0000001111111111", ustobs(1023));
    ck_assert_str_eq("0000000111111111", ustobs(511));
    ck_assert_str_eq("0000000011111111", ustobs(255));
    ck_assert_str_eq("0000000001111111", ustobs(127));
    ck_assert_str_eq("0000000000111111", ustobs(63));
    ck_assert_str_eq("0000000000011111", ustobs(31));
    ck_assert_str_eq("0000000000001111", ustobs(15));
    ck_assert_str_eq("0000000000000111", ustobs(7));
    ck_assert_str_eq("0000000000000011", ustobs(3));
    ck_assert_str_eq("0000000000000001", ustobs(1));
}
END_TEST

int main(void)
{
    Suite *s1 = suite_create("Code Generator");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_test(tc1_1, test_cg_dest);
    tcase_add_test_raise_signal(tc1_1, test_cg_dest_invalid_input, SIGABRT);
    tcase_add_test(tc1_1, test_cg_comp);
    tcase_add_test_raise_signal(tc1_1, test_cg_comp_required, SIGABRT);
    tcase_add_test_raise_signal(tc1_1, test_cg_comp_invalid_input, SIGABRT);
    tcase_add_test(tc1_1, test_cg_jump);
    tcase_add_test_raise_signal(tc1_1, test_cg_jump_invalid_input, SIGABRT);
    tcase_add_test(tc1_1, test_ustobs);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
