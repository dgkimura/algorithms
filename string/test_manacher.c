#include <check.h>

#include "manacher.c"


START_TEST(testFindLongestPalindromeAtEnd)
{
    char *text = "zzzzzaabacabaa";

    ck_assert_str_eq(FindLongestSubStringPalindrome(text), "aabacabaa");
}
END_TEST


START_TEST(testFindLongestPalindromeAtBeginning)
{
    char *text = "aabacabaazzzzz";

    ck_assert_str_eq(FindLongestSubStringPalindrome(text), "aabacabaa");
}
END_TEST


START_TEST(testFindLongestPalindromeAtMiddle)
{
    char *text = "yyyaabacabaazz";

    ck_assert_str_eq(FindLongestSubStringPalindrome(text), "aabacabaa");
}
END_TEST


START_TEST(testAllUniqueLetters)
{
    char *text = "abcdefg";

    ck_assert_str_eq(FindLongestSubStringPalindrome(text), "a");
}
END_TEST


//TODO: Uncomment after adding sentinel begin/end characters
//START_TEST(testSingleLetterPalindrome)
//{
//    char *text = "aaaaa";
//
//    ck_assert_str_eq(FindLongestSubStringPalindrome(text), "aaaaa");
//}
//END_TEST


//TODO: Uncomment after adding support for even palindromes
//      One approach is to add sentinel character between each character
//      during computation to mimic odd palindromes.
//START_TEST(testAllUniqueLetters)
//{
//    char *text = "abba";
//
//    ck_assert_str_eq(FindLongestSubStringPalindrome(text), "abba");
//}
//END_TEST

int
main(void)
{
    Suite *suite = suite_create("manacher");
    TCase *testcase = tcase_create("manacher");
    SRunner *runner = srunner_create(suite);

    suite_add_tcase(suite, testcase);
    tcase_add_test(testcase, testFindLongestPalindromeAtEnd);
    tcase_add_test(testcase, testFindLongestPalindromeAtBeginning);
    tcase_add_test(testcase, testFindLongestPalindromeAtMiddle);
    tcase_add_test(testcase, testAllUniqueLetters);

    srunner_run_all(runner, CK_ENV);
}
