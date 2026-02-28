#include "push_swap.h"
#include <stdlib.h>

static int min(int a, int b) { return a < b ? a : b; }

int get_pos_in_range(t_stack *stack, int low, int high)
{
    int pos = 0;
    while (stack)
    {
        if (stack->index >= low && stack->index <= high)
            return pos;
        pos++;
        stack = stack->next;
    }
    return -1;
}

int find_max_pos(t_stack *stack)
{
    int pos = 0;
    int best = 0;
    int best_pos = 0;
    while (stack)
    {
        if (stack->index > best)
        {
            best = stack->index;
            best_pos = pos;
        }
        pos++;
        stack = stack->next;
    }
    return best_pos;
}

void bring_pos_to_top_a(t_stack **a, int pos)
{
    int size = stack_size(*a);
    if (pos <= size / 2)
    {
        while (pos-- > 0)
            ra(a);
    }
    else
    {
        int r = size - pos;
        while (r-- > 0)
            rra(a);
    }
}

void bring_pos_to_top_b(t_stack **b, int pos)
{
    int size = stack_size(*b);
    if (pos <= size / 2)
    {
        while (pos-- > 0)
            rb(b);
    }
    else
    {
        int r = size - pos;
        while (r-- > 0)
            rrb(b);
    }
}

void chunk_sort(t_stack **a, t_stack **b)
{
    int size = stack_size(*a);
    if (size <= 1) return;
    int chunks = 5; /* tuned for 100 elements */
    int chunk_size = (size + chunks - 1) / chunks;

    for (int c = 0; c < chunks; c++)
    {
        int low = c * chunk_size;
        int high = min(size - 1, (c + 1) * chunk_size - 1);
        int pos;
        while ((pos = get_pos_in_range(*a, low, high)) != -1)
        {
            bring_pos_to_top_a(a, pos);
            /* push to b; if index in lower half of chunk, rotate b to help ordering */
            if ((*a)->index <= low + (chunk_size / 2))
            {
                pb(a, b);
                rb(b);
            }
            else
                pb(a, b);
        }
    }

    /* now push back from b to a in descending order */
    while (*b)
    {
        int pos_max = find_max_pos(*b);
        bring_pos_to_top_b(b, pos_max);
        pa(a, b);
    }
}
