#include "helper.h"
#include "../include/parser.h"

static struct parser *parser;

START_TEST(test_advance)
{

}
END_TEST

START_TEST(test_command_type)
{

}
END_TEST

START_TEST(test_symbol)
{

}
END_TEST

START_TEST(test_dest)
{

}
END_TEST

START_TEST(test_comp)
{

}
END_TEST

START_TEST(test_jump)
{

}
END_TEST

static void __setup__()
{
    parser = init_parser();

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
    int nf;

    suite_add_tcase(s1, tc1_1);
    tcase_add_checked_fixture(tc1_1, __setup__, __teardown__);
    tcase_add_test(tc1_1, test_advance);
    tcase_add_test(tc1_1, test_command_type);
    tcase_add_test(tc1_1, test_symbol);
    tcase_add_test(tc1_1, test_dest);
    tcase_add_test(tc1_1, test_comp);
    tcase_add_test(tc1_1, test_jump);

    srunner_run_all(sr, CK_ENV);
    nf = srunner_ntests_failed(sr);
    srunner_free(sr);

    return nf == 0 ? 0 : 1;
}
