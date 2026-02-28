#include "push_swap.h"
#include <stdlib.h>
#include <string.h>

static int int_cmp(const void *a, const void *b)
{
    int ia = *(const int *)a;
    int ib = *(const int *)b;
    return (ia > ib) - (ia < ib);
}

void index_stack(t_stack *stack)
{
    int size = 0;
    t_stack *tmp = stack;
    while (tmp)
        size++, tmp = tmp->next;
    if (size == 0) return;
    int *arr = stack_to_array(stack, size);
    int *sorted = malloc(sizeof(int) * size);
    if (!arr || !sorted) { free(arr); free(sorted); return; }
    memcpy(sorted, arr, sizeof(int) * size);
    qsort(sorted, size, sizeof(int), int_cmp);
    t_stack *cur = stack;
    while (cur)
    {
        /* find rank */
        int i = 0;
        while (i < size && sorted[i] != cur->value) i++;
        cur->index = i;
        cur = cur->next;
    }
    free(arr);
    free(sorted);
}

void radix_sort(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    int max = 0;
    t_stack *tmp = *a;
    while (tmp)
    {
        if (tmp->index > max) max = tmp->index;
        tmp = tmp->next;
    }
    int max_bits = 0;
    while ((max >> max_bits) != 0)
        max_bits++;

    for (int bit = 0; bit < max_bits; bit++)
    {
        for (int i = 0; i < size; i++)
        {
            if ((((*a)->index >> bit) & 1) == 0)
                pb(a, b);
            else
                ra(a);
        }
        while (*b)
            pa(a, b);
    }
}
