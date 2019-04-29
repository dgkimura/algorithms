#include <check.h>

#include "kmp.c"


START_TEST(testSearchIdenticalSubstringAndBaseString)
{
    char *substring = "aabaabaaa";
    char *basestring = "aabaabaaa";

    ck_assert_int_eq(FindSubStringIndex(substring, basestring), 0);
}
END_TEST


START_TEST(testSearchSubstringNotInBaseString)
{
    char *substring = "aaaa";
    char *basestring = "aabaabaaa";

    ck_assert_int_eq(FindSubStringIndex(substring, basestring), -1);
}
END_TEST


START_TEST(testSearchSubstringIsInBaseString)
{
    char *substring = "aabaabaaa";
    char *basestring = "aabaaabaabaaa";

    ck_assert_int_eq(FindSubStringIndex(substring, basestring), 4);
}
END_TEST

int
main(void)
{
    Suite *suite = suite_create("kmp");
    TCase *testcase = tcase_create("kmp");
    SRunner *runner = srunner_create(suite);

    suite_add_tcase(suite, testcase);
    tcase_add_test(testcase, testSearchIdenticalSubstringAndBaseString);
    tcase_add_test(testcase, testSearchSubstringNotInBaseString);
    tcase_add_test(testcase, testSearchSubstringIsInBaseString);

    srunner_run_all(runner, CK_ENV);
}
