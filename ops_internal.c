#include "push_swap.h"

void swap_nodes(t_stack **stack)
{
    t_stack *a;
    t_stack *b;

    if (!stack || !*stack || !(*stack)->next)
        return;
    a = *stack;
    b = a->next;
    a->next = b->next;
    b->next = a;
    *stack = b;
}

void push_nodes(t_stack **from, t_stack **to)
{
    t_stack *n;
    if (!from || !*from)
        return;
    n = *from;
    *from = n->next;
    n->next = *to;
    *to = n;
}

void rotate_nodes(t_stack **stack)
{
    t_stack *first;
    t_stack *tail;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    *stack = first->next;
    first->next = NULL;
    tail = *stack;
    while (tail->next)
        tail = tail->next;
    tail->next = first;
}

void rev_rotate_nodes(t_stack **stack)
{
    t_stack *prev = NULL;
    t_stack *last = *stack;

    if (!stack || !*stack || !(*stack)->next)
        return;
    while (last->next)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = *stack;
    *stack = last;
}
