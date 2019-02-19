/*
 * For author and copyright information, see
 * `utest.h'. This file is part of
 * `github.com/PhilippSchuette/projecteuler'.
 */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "utest.h"

char utest_init(int *argc, char **argv)
{
    extern RSLT_TBL  rslt_tbl;
    extern char      prog[BUFSIZE];
    extern boolean   log_silent;

    if (strlen(argv[0]) > (BUFSIZE-1)) {
        fprintf(stderr, "error: filename %s is too long\n", argv[0]);
        exit(1);
    }
    strcpy(prog, argv[0]);

    rslt_tbl.t_total = 0;
    rslt_tbl.t_success = 0;
    rslt_tbl.t_failed = 0;

    /*
     * If command line options were supplied, look for --silent.
     * If it was set, turn off any logging output (errors are still
     * reported, though). To simplify parsing of options in main
     * programs, --silent must be the LAST parameter! It is then
     * removed by resetting argc.
     */
    log_silent = 0;
    if (*argc > 1)
        if (strcmp(argv[(*argc-1)], "--silent") == 0) {
            log_silent = 1;
            (*argc)--;
        }

    for (int i = 0; i < MAX_TESTS; i++) {
        rslt_tbl.test_info[i] = (char *)malloc(BUFSIZE * sizeof(char));
    }

    return 0; /* return success */
}

boolean assert_equal(long test, long comp, const char *msg)
{
    extern char      prog[BUFSIZE];
    extern RSLT_TBL  rslt_tbl;
    char             info_str[BUFSIZE];
    char             rslt_str[BUFSIZE];

    /* create a string that holds test information */
    snprintf(info_str, BUFSIZE, "%s\t%s: %s", DELIM_STD, prog, msg);

    /* update `rslt_tbl', entry offset is always t_total + t_total */
    strcpy(rslt_tbl.test_info[(rslt_tbl.t_total+rslt_tbl.t_total)],
           info_str);
    rslt_tbl.t_total += 1;

    if (rslt_tbl.t_total == MAX_TESTS) {
        fprintf(stderr, "%s: error: too many tests (max: %d)\n",
                prog, MAX_TESTS);
        exit(1);
    }

    if (test == comp) {
        /* create a string that holds success information */
        snprintf(rslt_str, BUFSIZE, "%s %s\t%s: test succeeded\n%s",
                 DELIM_STD, DELIM_SUCCESS, prog, DELIM_END);

        /* update `rslt_tbl', entry offset is always t_total + (t_total-1) */
        strcpy(rslt_tbl.test_info[rslt_tbl.t_total+(rslt_tbl.t_total-1)],
               rslt_str);
        rslt_tbl.t_success += 1;

        return 0;
    } else {
        /* create a string that holds failure information */
        snprintf(rslt_str, BUFSIZE,
                 "%s %s\t%s: test failed: %ld is not equal to %ld\n%s",
                 DELIM_STD, DELIM_FAILURE, prog, test, comp, DELIM_END);

        /* add information to `rslt_tbl' */
        /* update `rslt_tbl', entry offset is always t_total + (t_total-1) */
        strcpy(rslt_tbl.test_info[rslt_tbl.t_total+(rslt_tbl.t_total-1)],
               rslt_str);
        rslt_tbl.t_failed += 1;

        return 1;
    }
}

/*
 * Implementation is identical to `assert_equal',
 * except for the success condition.
 */
boolean assert_not_equal(long test, long comp, const char *msg)
{
    extern char      prog[BUFSIZE];
    extern RSLT_TBL  rslt_tbl;
    char             info_str[BUFSIZE];
    char             rslt_str[BUFSIZE];

    /* create a string that holds test information */
    snprintf(info_str, BUFSIZE, "%s\t%s: %s", DELIM_STD, prog, msg);

    /* update `rslt_tbl', entry offset is always t_total + t_total */
    strcpy(rslt_tbl.test_info[(rslt_tbl.t_total+rslt_tbl.t_total)],
           info_str);
    rslt_tbl.t_total += 1;

    if (rslt_tbl.t_total == MAX_TESTS) {
        fprintf(stderr, "%s: error: too many tests (max: %d)\n",
                prog, MAX_TESTS);
        exit(1);
    }

    if (test != comp) {
        /* create a string that holds success information */
        snprintf(rslt_str, BUFSIZE, "%s %s\t%s: test succeeded\n%s",
                 DELIM_STD, DELIM_SUCCESS, prog, DELIM_END);

        /* update `rslt_tbl', entry offset is always t_total + (t_total-1) */
        strcpy(rslt_tbl.test_info[rslt_tbl.t_total+(rslt_tbl.t_total-1)],
               rslt_str);
        rslt_tbl.t_success += 1;

        return 0;
    } else {
        /* create a string that holds failure information */
        snprintf(rslt_str, BUFSIZE,
                 "%s %s\t%s: test failed: %ld is equal to %ld\n%s",
                 DELIM_STD, DELIM_FAILURE, prog, test, comp, DELIM_END);

        /* add information to `rslt_tbl' */
        /* update `rslt_tbl', entry offset is always t_total + (t_total-1) */
        strcpy(rslt_tbl.test_info[rslt_tbl.t_total+(rslt_tbl.t_total-1)],
               rslt_str);
        rslt_tbl.t_failed += 1;

        return 1;
    }
}

void print_rslt_tbl(void) {
    extern RSLT_TBL  rslt_tbl;
    extern boolean   log_silent;

    if (log_silent) return;

    for (int i = 0; i < (rslt_tbl.t_total*2); i++)
        fprintf(stderr, "%s\n", rslt_tbl.test_info[i]);

    fprintf(stderr, "%s\t%s: tests failed: \t%d\n",
            DELIM_STD, prog, rslt_tbl.t_failed);
    fprintf(stderr, "%s\t%s: tests succeeded: \t%d\n%s\n",
            DELIM_STD, prog, rslt_tbl.t_success, DELIM_END);
}

/* TODO:
boolean assert_true(boolean, const char *msg);
boolean assert_false(boolean, const char *msg);
boolean assert_arr_equal(const long *, const long *, const char *msg);
boolean assert_arr_not_equal(const long *, const long *, const char *msg);
*/
