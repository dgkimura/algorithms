#include "gtest/gtest.h"

#include "manacher.c"


TEST(StringTest, testFindLongestPalindromeAtEnd)
{
    std::string text = "zzzzzaabacabaa";

    ASSERT_STREQ(FindLongestSubStringPalindrome(text.c_str()), "aabacabaa");
}


TEST(StringTest, testFindLongestPalindromeAtBeginning)
{
    std::string text = "aabacabaazzzzz";

    ASSERT_STREQ(FindLongestSubStringPalindrome(text.c_str()), "aabacabaa");
}


TEST(StringTest, testFindLongestPalindromeAtMiddle)
{
    std::string text = "yyyaabacabaazz";

    ASSERT_STREQ(FindLongestSubStringPalindrome(text.c_str()), "aabacabaa");
}


TEST(StringTest, testAllUniqueLetters)
{
    std::string text = "abcdefg";

    ASSERT_STREQ(FindLongestSubStringPalindrome(text.c_str()), "a");
}


TEST(StringTest, testSingleLetterPalindrome)
{
    std::string text = "aaaaa";

    ASSERT_STREQ(FindLongestSubStringPalindrome(text.c_str()), "aaaaa");
}
