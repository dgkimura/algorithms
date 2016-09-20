#include "gtest/gtest.h"

#include "kmp.c"


TEST(StringTest, testSearchIdenticalSubstringAndBaseString)
{
    std::string substring = "aabaabaaa";
    std::string basestring = "aabaabaaa";

    ASSERT_EQ(FindSubStringIndex(substring.c_str(), basestring.c_str()), 0);
}


TEST(StringTest, testSearchSubstringNotInBaseString)
{
    std::string substring = "aaaa";
    std::string basestring = "aabaabaaa";

    ASSERT_EQ(FindSubStringIndex(substring.c_str(), basestring.c_str()), -1);
}


TEST(StringTest, testSearchSubstringIsInBaseString)
{
    std::string substring = "aabaabaaa";
    std::string basestring = "aabaaabaabaaa";

    ASSERT_EQ(FindSubStringIndex(substring.c_str(), basestring.c_str()), 4);
}
