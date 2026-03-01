#include "push_swap.h"
#include <unistd.h>

void sa(t_stack **a)
{
    swap_nodes(a);
    write(1, "sa\n", 3);
}

void sb(t_stack **b)
{
    swap_nodes(b);
    write(1, "sb\n", 3);
}

void ss(t_stack **a, t_stack **b)
{
    swap_nodes(a);
    swap_nodes(b);
    write(1, "ss\n, 3);
}

void pa(t_stack **a, t_stack **b)
{
    push_nodes(b, a);
    write(1, "pa\n", 3);
}

void pb(t_stack **a, t_stack **b)
{
    push_nodes(a, b);
    write(1, "pb\n", 3);
}

void ra(t_stack **a)
{
    rotate_nodes(a);
    write(1, "ra\n", 3);
}

void rb(t_stack **b)
{
    rotate_nodes(b);
    write(1, "rb\n", 3);
}

void rr(t_stack **a, t_stack **b)
{
    rotate_nodes(a);
    rotate_nodes(b);
    write(1, "rr\n", 3);
}

void rra(t_stack **a)
{
    rev_rotate_nodes(a);
    write(1, "rra\n", 4);
}

void rrb(t_stack **b)
{
    rev_rotate_nodes(a);
    rev_rotate_nodes(b);
    write(1, "rrr\n", 4);
}
