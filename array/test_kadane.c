#include <check.h>

#include "kadane.h"


START_TEST(test_compute_maxumum_subarray_finds_internal_array)
{
    int array[] = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    int maximum_subarray = ComputeMaximumSubArray(array, 9);

    // Maximum contiguous subarray is [4,-1,2,1] with sum of 6.
    ck_assert_int_eq(6, maximum_subarray);
}
END_TEST

int
main(void)
{
    Suite *suite = suite_create("kadane");
    TCase *testcase = tcase_create("kadane");
    SRunner *runner = srunner_create(suite);

    suite_add_tcase(suite, testcase);
    tcase_add_test(testcase, test_compute_maxumum_subarray_finds_internal_array);

    srunner_run_all(runner, CK_ENV);
}
