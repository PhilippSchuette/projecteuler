/*
 * lexorder.c: generate lexicographic permutations of an ordered char array.
 *
 * Can be used to implement a solution for problem 24.
 */
#include <stdio.h>
#include <stdlib.h>

#define  NUM_CHARS          10
#define  NUM_PERMUTATIONS   1000000

typedef struct permutation {
    char *curr;       /* the current permutation */
    unsigned int len; /* the static length of the permutation buffer */
    unsigned int num; /* the number of the current permutation */
} permutation;

void init_perm(permutation *, unsigned int);
void print_perm(permutation *);
int next_perm(permutation *);
void free_perm(permutation *);
void fail(int, char *);

void _swap(char *, int, int);
void _reverse_perm(permutation *, int);

int main(int argc, char **argv)
{
    int i, err;
    permutation *perm; /* buffer holding the permutations */

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
    print_perm(perm);

    return 0;
}

/* init_perm: generate an initial, ordered array of chars from '0' to len-1. */
void init_perm(permutation *perm, unsigned int len)
{
    int i;

    perm->len = len;
    perm->num = 0;
    perm->curr = (char *)malloc(len*sizeof(char));
    if (!perm->curr)
        fail(1, "Cannot allocate more memory");
    for (i = 0; i < len; i++)
        perm->curr[i] = (char)(i+65);
}

/* print_perm: print a representation of the permutation array to stderr. */
void print_perm(permutation *perm)
{
    int i;
    int len;

    fputs("[ ", stderr);
    for (i = 0, len = perm->len; i < len; i++)
        fprintf(stderr, "%c ", perm->curr[i]);
    fprintf(stderr, "] (number %d)\n", perm->num);
}

/* next_perm: generate the next permutation array, replacing the old one. */
int next_perm(permutation *perm)
{
    int i, len, max_k, max_l;
    max_k = max_l = -1;

    /* find the largest k, such that a[k] < a[k+1] */
    for (i = 0, len = perm->len; i < len-1; i++)
        if ((perm->curr[i] < perm->curr[i+1]) && (i > max_k))
            max_k = i;

    /* find the largest l, such that a[k] < a[l] */
    for (i = 0, len = perm->len; i < len; i++)
        if ((perm->curr[max_k] < perm->curr[i]) && (i > max_l))
            max_l = i;

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
void _swap(char *arr, int i, int j)
{
    char tmp;

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
