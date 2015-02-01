#include "helper.h"
#include "../include/parser.h"

static FILE *sample_assembly_program;
static struct parser *parser;

START_TEST(test_has_more_commands_and_advance)
{
    ck_assert_int_eq(1, has_more_commands(parser));

    while (has_more_commands(parser)) {
        advance(parser);
    }

    ck_assert_int_eq(0, has_more_commands(parser));
}
END_TEST

START_TEST(test_command_type)
{
    if (has_more_commands(parser)) {
        advance(parser);
    }

    ck_assert_int_eq(L_COMMAND, command_type(parser));

    if (has_more_commands(parser)) {
        advance(parser);
    }

    ck_assert_int_eq(A_COMMAND, command_type(parser));

    if (has_more_commands(parser)) {
        advance(parser);
    }

    ck_assert_int_eq(C_COMMAND, command_type(parser));
}
END_TEST

START_TEST(test_symbol)
{
    if (has_more_commands(parser))
        advance(parser);

    ck_assert_str_eq("FOO", symbol(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_str_eq("R1", symbol(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_ptr_eq(NULL, symbol(parser));
}
END_TEST

START_TEST(test_dest)
{
    if (has_more_commands(parser))
        advance(parser);

    ck_assert_ptr_eq(NULL, dest(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_ptr_eq(NULL, dest(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_str_eq("M", dest(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_str_eq("D", dest(parser));
}
END_TEST

START_TEST(test_comp)
{
    if (has_more_commands(parser))
        advance(parser);

    ck_assert_ptr_eq(NULL, comp(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_ptr_eq(NULL, comp(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_str_eq("0", comp(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_str_eq("M", comp(parser));
}
END_TEST

START_TEST(test_jump)
{
    if (has_more_commands(parser))
        advance(parser);

    ck_assert_ptr_eq(NULL, jump(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_ptr_eq(NULL, jump(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_ptr_eq(NULL, jump(parser));

    if (has_more_commands(parser))
        advance(parser);

    ck_assert_str_eq("JGT", jump(parser));
}
END_TEST

static void __setup__()
{
    rewind(sample_assembly_program);
    parser = init_parser(sample_assembly_program);

    if (parser == NULL) {
        ck_abort_msg("Could not allocate memory for the parser.");
    }
}

static void __teardown__()
{
    destroy_parser(parser);
}

int main(void)
{
    Suite *s1 = suite_create("Parser");
    TCase *tc1_1 = tcase_create("Core");
    SRunner *sr = srunner_create(s1);
    int nf = 0;

    suite_add_tcase(s1, tc1_1);
    tcase_add_checked_fixture(tc1_1, __setup__, __teardown__);
    tcase_add_test(tc1_1, test_has_more_commands_and_advance);
    tcase_add_test(tc1_1, test_command_type);
    tcase_add_test(tc1_1, test_symbol);
    tcase_add_test(tc1_1, test_dest);
    tcase_add_test(tc1_1, test_comp);
    tcase_add_test(tc1_1, test_jump);

    sample_assembly_program = fopen("resources/sample_assembly.asm", "r");

    if (sample_assembly_program) {
        srunner_run_all(sr, CK_ENV);
        nf = srunner_ntests_failed(sr);
        fclose(sample_assembly_program);
    }

    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
