/* Project Euler Problem 24 Solution
 *
 * Problem statement:
 *A permutation is an ordered arrangement of objects.  For example, 3124
 * is one possible permutation of the digits 1, 2, 3 and 4.  If all of
 * the permutations are listed numerically or alphabetically, we call it
 * lexicographic order.  The lexicographic permutations of 0, 1 and 2
 * are:  012   021   102   120   201   210
 * What is the millionth lexicographic permutation of the digits 0, 1, 2,
 * 3, 4, 5, 6, 7, 8 and 9?
 *
 * Solution description:
 * Brute force.  For the algorithm, check ../py_src/problem024.py.
 *
 * Author: Daniel Schuette, Philipp Schuette
 * Date: 2019/06/13
 * License: MIT (see ../LICENSE.md)
 */
#include <stdio.h>
#include <stdlib.h>
#include "utest/utest.h"

#define  NUM_CHARS          10
#define  NUM_PERMUTATIONS   1000000


const long int EXPECTED_RSLT[10] = {2, 7, 8, 3, 9, 1, 5, 6, 0, 4};
const long int WRONG_RSLT[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

typedef struct permutation {
    long int *curr;       /* the current permutation */
    unsigned int len;     /* the static length of the permutation buffer */
    unsigned int num;     /* the number of the current permutation */
} permutation;

void init_perm(permutation *, unsigned int);
void print_perm(permutation *);
int next_perm(permutation *);
void free_perm(permutation *);
void fail(int, char *);

void _swap(long int *, int, int);
void _reverse_perm(permutation *, int);

int main(int argc, char **argv)
{
    int i, err;
    permutation *perm; /* buffer holding the permutations */

    /* initialize unit testing */
    utest_init(&argc, argv);

    perm = (permutation *)malloc(sizeof(permutation));
    if (!perm)
        fail(1, "Cannot allocate more memory");
    init_perm(perm, NUM_CHARS);

    for (i = 0; i < NUM_PERMUTATIONS; i++) {
        err = next_perm(perm);
        if (err)
            fail(1, "Cannot compute another permutation");
        else
            continue;
    }

    /* assert equality of calculated and expected result */
    assert_arr_equal((perm->curr), EXPECTED_RSLT, 10, 10,
                 "testing equality of calulated and expected result");
    assert_arr_not_equal((perm->curr), WRONG_RSLT, 10, 10,
                     "testing unequality of calculated and wrong result");
    /* print test results and clean up */
    print_rslt_tbl();
    utest_free_all();

    print_perm(perm);
    free_perm(perm);

    return 0;
}

/* init_perm: generate an initial, ordered array of chars from '0' to len-1. */
void init_perm(permutation *perm, unsigned int len)
{
    long int i;

    perm->len = len;
    perm->num = 0;
    perm->curr = (long int *)malloc(len*sizeof(long int));
    if (!perm->curr)
        fail(1, "Cannot allocate more memory");
    for (i = 0; i < len; i++)
        perm->curr[i] = i;
}

/* print_perm: print a representation of the permutation array to stderr. */
void print_perm(permutation *perm)
{
    int i;
    int len;

    fputs("[ ", stderr);
    for (i = 0, len = perm->len; i < len; i++)
        fprintf(stderr, "%ld ", perm->curr[i]);
    fprintf(stderr, "] (number %d)\n", perm->num);
}

/* next_perm: generate the next permutation array, replacing the old one. */
int next_perm(permutation *perm)
{
    int i, max_k, max_l;
    max_k = max_l = -1;

    /* find the largest k, such that a[k] < a[k+1] */
    for (i = perm->len-1; i > 0; i--)
        if (perm->curr[i] > perm->curr[i-1]) {
            max_k = i-1;
            break;
        }

    /* find the largest l, such that a[k] < a[l] */
    for (i = perm->len-1; i > max_k; i--)
        if (perm->curr[max_k] < perm->curr[i]) {
            max_l = i;
            break;
        }

    /* if any of the indices did not change, return error */
    if (max_l < 0 || max_k < 0)
        return -1;

    /* swap a[k] and a[l] */
    _swap(perm->curr, max_k, max_l);

    /* reverse the suffix a[k+1]...a[n] */
    _reverse_perm(perm, max_k+1);
    perm->num++;
    return 0;
}

/* _swap: swap elements `i' and `j' in array `arr'. */
void _swap(long int *arr, int i, int j)
{
    long int tmp;

    tmp = arr[i];
    arr[i] = arr[j];
    arr[j] = tmp;
}

/* _reverse_perm: reverse a permutation array. */
void _reverse_perm(permutation *perm, int idx)
{
    int half, i, len;

    half = (perm->len-idx)/2; /* half of no. of items to revert */
    len = perm->len - 1;
    for (i = 0; i < half; i++)
        _swap(perm->curr, idx+i, len-i);
}

/* free_perm: free a permutation struct. */
void free_perm(permutation *perm)
{
    free(perm->curr);
    free(perm);
}

/* fail: exit with a message to stderr and an error status. */
void fail(int status, char *msg)
{
    fprintf(stderr, "Error: %s.\n", msg);
    exit(status);
}
