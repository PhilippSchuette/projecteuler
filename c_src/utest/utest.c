/*
 * This file is part of `github.com/PhilippSchuette/projecteuler'.
 * For author and copyright information, see `utest.h'.
 * Documentation is mainly in the header file, too.
 *
 * FIXME:   Move boilerplate code into a separate
 *          function, e.g.`_test_setup()'.
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
    strcpy(prog, argv[0]); /* save program name for fmt strings */

    /* initialize total, failed and successful tests counts */
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

    for (int i = 0; i < MAX_TESTS; i++)
        rslt_tbl.test_info[i] = (char *)malloc(BUFSIZE * sizeof(char));

    return 0; /* return success */
}

int utest_free_all(void) {
    extern RSLT_TBL  rslt_tbl;

    for (int i = 0; i < MAX_TESTS; i++)
        free(rslt_tbl.test_info[i]);

    return 0;
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

        /*
         * Add information to `rslt_tbl', then update `rslt_tbl',
         * entry offset is always t_total + (t_total-1)
         */
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

boolean assert_true(boolean success, const char *msg)
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

    if (success) {
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
                 "%s %s\t%s: test failed: false is not true\n%s",
                 DELIM_STD, DELIM_FAILURE, prog, DELIM_END);

        /*
         * Add information to `rslt_tbl', then update `rslt_tbl',
         * entry offset is always t_total + (t_total-1)
         */
        strcpy(rslt_tbl.test_info[rslt_tbl.t_total+(rslt_tbl.t_total-1)],
               rslt_str);
        rslt_tbl.t_failed += 1;

        return 1;
    }
}

boolean assert_false(boolean success, const char *msg)
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

    if (!success) {
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
                 "%s %s\t%s: test failed: true is not false\n%s",
                 DELIM_STD, DELIM_FAILURE, prog, DELIM_END);

        /*
         * Add information to `rslt_tbl', then update `rslt_tbl',
         * entry offset is always t_total + (t_total-1)
         */
        strcpy(rslt_tbl.test_info[rslt_tbl.t_total+(rslt_tbl.t_total-1)],
               rslt_str);
        rslt_tbl.t_failed += 1;

        return 1;
    }
}

boolean assert_arr_equal(const long *arr1, const long *arr2,
                         long len1, long len2, const char *msg)
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

    if (__is_ident_arr(arr1, arr2, len1, len2)) {
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
        int     err1, err2;
        char    *arr1_str, *arr2_str;

        arr1_str = (char *)malloc(BUFSIZE*sizeof(char));
        err1 = __print_arr(arr1, len1, BUFSIZE, arr1_str);

        arr2_str = (char *)malloc(BUFSIZE*sizeof(char));
        err2 = __print_arr(arr2, len2, BUFSIZE, arr2_str);

        /* if no errors occured, print with array information */
        if (!err1 && !err2)
            snprintf(rslt_str, BUFSIZE,
                     "%s %s\t%s: test failed: %s is not %s\n%s",
                     DELIM_STD, DELIM_FAILURE, prog,
                     arr1_str, arr2_str, DELIM_END);
        /* else, print general diagnostics */
        else
            snprintf(rslt_str, BUFSIZE,
                     "%s %s\t%s: test failed: arrays not identical\n%s",
                     DELIM_STD, DELIM_FAILURE, prog, DELIM_END);


        /* free resources */
        free(arr1_str);
        free(arr2_str);

        /*
         * Add information to `rslt_tbl', then update `rslt_tbl',
         * entry offset is always t_total + (t_total-1)
         */
        strcpy(rslt_tbl.test_info[rslt_tbl.t_total+(rslt_tbl.t_total-1)],
               rslt_str);
        rslt_tbl.t_failed += 1;

        return 1;
    }
}

boolean assert_arr_not_equal(const long *arr1, const long *arr2,
                             long len1, long len2, const char *msg)
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

    if (!__is_ident_arr(arr1, arr2, len1, len2)) {
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
        int     err1, err2;
        char    *arr1_str, *arr2_str;

        arr1_str = (char *)malloc(BUFSIZE*sizeof(char));
        err1 = __print_arr(arr1, len1, BUFSIZE, arr1_str);

        arr2_str = (char *)malloc(BUFSIZE*sizeof(char));
        err2 = __print_arr(arr2, len2, BUFSIZE, arr2_str);

        /* if no errors occured, print with array information */
        if (!err1 && !err2)
            snprintf(rslt_str, BUFSIZE,
                     "%s %s\t%s: test failed: %s is not %s\n%s",
                     DELIM_STD, DELIM_FAILURE, prog,
                     arr1_str, arr2_str, DELIM_END);
        /* else, just print some general diagnostics */
        else
            snprintf(rslt_str, BUFSIZE,
                     "%s %s\t%s: test failed: arrays not identical\n%s",
                     DELIM_STD, DELIM_FAILURE, prog, DELIM_END);


        /* free resources */
        free(arr1_str);
        free(arr2_str);

        /*
         * Add information to `rslt_tbl', then update `rslt_tbl',
         * entry offset is always t_total + (t_total-1)
         */
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

    fprintf(stderr, "%s\t%s: tests failed: %d\n",
            DELIM_STD, prog, rslt_tbl.t_failed);
    fprintf(stderr, "%s\t%s: tests succeeded: %d\n%s\n",
            DELIM_STD, prog, rslt_tbl.t_success, DELIM_END);
}

/*
 * Helper function implementations.
 */

/* Returns 1 if input arrays are identical. */
boolean __is_ident_arr(const long *arr1, const long *arr2, long len1, long len2)
{
    /* check equal length of inputs */
    if (len1 != len2)
        return 0;

    /* iterate over arrays to test deep equality */
    for (int i = 0; i < len1; i++)
        if (arr1[i] != arr2[i])
            return 0;

    return 1;
}

/* Pretty-prints an array into a buffer. */
int __print_arr(const long *arr, unsigned long len, unsigned long bufsize, char *buf)
{
    /* copy starting delimiter to `buf' */
    snprintf(buf, len, "[ ");

    /* iterate over array, printing content to `buf' */
    for (unsigned long i = 0; i < len; i++) {
        char    *str;
        if ((str = (char *)malloc(BUFSIZE*sizeof(char))) != NULL) {
            snprintf(str, BUFSIZE, "%ld ", arr[i]);
            if ((strlen(str)+strlen(buf)+1) < bufsize)
                strcat(buf, str);
            else
                return 1;
        } else {
            return 1;
        }
    }

    /* print ending delimiter to `buf' */
    if (strlen(buf)+2 < bufsize) /* holds one more char and '\0' */
        strcat(buf, "]");
    else
        return 1;

    return 0; /* return success */
}
