#include <check.h>

#include "heap.h"

START_TEST(x)
{
}
END_TEST

int
main(void)
{
    Suite *suite = suite_create("heap");
    TCase *testcase = tcase_create("heap");
    SRunner *runner = srunner_create(suite);

    suite_add_tcase(suite, testcase);
    tcase_add_test(testcase, x);

    srunner_run_all(runner, CK_ENV);
}
