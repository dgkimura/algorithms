#include "gtest/gtest.h"

#include "manacher.c"


TEST(StringTest, testFindLongestPalindromeAtEnd)
{
    std::string text = "zzzzzaabacabaa";

    ASSERT_STREQ(FindLongestSubStringPalindrome(text.c_str()), "aabacabaa");
}
