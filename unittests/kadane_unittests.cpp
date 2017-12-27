#include "gtest/gtest.h"

#include "kadane.c"


TEST(ArrayTest, testComputeMaxumumSubArrayFindsInternalArray)
{
    int array[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    int maximum_subarray = ComputeMaximumSubArray(array, 9);

    // Maximum contiguous subarray is [4,-1,2,1] with sum of 6.
    ASSERT_EQ(6, maximum_subarray);
}
