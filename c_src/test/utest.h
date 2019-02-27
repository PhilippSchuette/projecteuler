/*
 * utest.h implements a simple unit testing framework
 * that works in a pipeline with Travis CI and Codecov
 * using gcov and a custom test runner (e.g. a Makefile
 * of a bash script).
 *
 * Author: Daniel Schuette
 * Date: 2019/02/19
 * License: MIT (see `github.com/PhilippSchuette/projecteuler')
 */
#define  MAX_TESTS          255
#define  BUFSIZE            4096
#define  DELIM_STD          "**"
#define  DELIM_SUCCESS      "+++"
#define  DELIM_FAILURE      "---"
#define  DELIM_END          "~~~~~~~~~~~~~~~~~~"

typedef char boolean;

/* `Resulttable' holds test result information. */
typedef struct utest_results {
    /*
     * Number of test run, tests that failed and tests that
     * succeeded.
     */
    int t_total;
    int t_success;
    int t_failed;

    /* Array of names of successful and failed tests. */
    char *test_info[MAX_TESTS];
} RSLT_TBL;

RSLT_TBL    rslt_tbl;
char        prog[BUFSIZE];
boolean     log_silent; /* if set, no results are reported */

/* Initialize `rslt_tbl'. Returns 0 on success, 1 otherwise. */
char utest_init(int *argc, char **argv);

/*
 * Assert equality of two long integers, boolean values and arrays.
 * Test results are added to `rslt_tbl'. All logging output is
 * currently printed to stderr.
 */
boolean assert_equal(long, long, const char *msg);
boolean assert_not_equal(long, long, const char *msg);

boolean assert_true(boolean, const char *msg);
boolean assert_false(boolean, const char *msg);

boolean assert_arr_equal(const long *, const long *, const char *msg);
boolean assert_arr_not_equal(const long *, const long *, const char *msg);

/*
 * Prints `rslt_tbl'. This should always succeed if `utest_init'
 * was called, so no return value.
 */
void print_rslt_tbl(void);

/*
 * Free all used resources.
 * The return value indicates success or failure.
 */
int utest_free_all(void);
