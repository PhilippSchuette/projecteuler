#include <stdio.h>
#include <stdlib.h>
#include "../utest.h"
#define  ARR_LENGTH  5


int main(int argc, char **argv)
{
    long    arr1[] = { 1, 2, 3, 4, 5 };
    long    arr2[] = { 1, 2, 3, 4, 5 };
    long    arr3[] = { 1, 2, 3, 4, 4 };

    /* initialize unit testing */
    utest_init(&argc, argv);

    /* assert equality of arrays */
    assert_arr_equal(
            arr1,
            arr2,
            ARR_LENGTH,
            ARR_LENGTH,
            "testing equality of arrays"
    );

    assert_arr_equal(
            arr1,
            arr3,
            ARR_LENGTH,
            ARR_LENGTH,
            "testing equality of arrays"
    );

    /* print test results and clean up */
    print_rslt_tbl();
    utest_free_all();

    return 0;
}
