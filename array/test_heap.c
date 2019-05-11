#include <check.h>

#include "heap.h"

START_TEST(test_heap_with_single_value)
{
    struct heap h;
    heap_init(&h);

    heap_insert(&h, 1);

    ck_assert_int_eq(1, heap_minimum(&h));
}
END_TEST

START_TEST(test_heap_with_two_increasing_values)
{
    struct heap h;
    heap_init(&h);

    heap_insert(&h, 1);
    heap_insert(&h, 2);

    ck_assert_int_eq(1, heap_minimum(&h));
}
END_TEST

START_TEST(test_heap_with_two_decreasing_values)
{
    struct heap h;
    heap_init(&h);

    heap_insert(&h, 2);
    heap_insert(&h, 1);

    ck_assert_int_eq(1, heap_minimum(&h));
}
END_TEST

START_TEST(test_heap_with_many_decreasing_values)
{
    struct heap h;
    heap_init(&h);

    heap_insert(&h, 6);
    heap_insert(&h, 5);
    heap_insert(&h, 4);
    heap_insert(&h, 3);
    heap_insert(&h, 2);
    heap_insert(&h, 1);

    ck_assert_int_eq(1, heap_minimum(&h));
}
END_TEST

int
main(void)
{
    Suite *suite = suite_create("heap");
    TCase *testcase = tcase_create("heap");
    SRunner *runner = srunner_create(suite);

    suite_add_tcase(suite, testcase);
    tcase_add_test(testcase, test_heap_with_single_value);
    tcase_add_test(testcase, test_heap_with_two_increasing_values);
    tcase_add_test(testcase, test_heap_with_two_decreasing_values);
    tcase_add_test(testcase, test_heap_with_many_decreasing_values);

    srunner_run_all(runner, CK_ENV);
}
