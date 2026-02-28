#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

static t_stack *new_node(int val)
{
    t_stack *n = malloc(sizeof(t_stack));
    if (!n) return NULL;
    n->value = val;
    n->index = 0;
    n->next = NULL;
    return n;
}

t_stack *create_stack_from_args(int argc, char **argv)
{
    t_stack *head = NULL;
    t_stack *tail = NULL;
    int i;

    for (i = 1; i < argc; i++)
    {
        int v = atoi(argv[i]);
        t_stack *n = new_node(v);
        if (!n)
        {
            free_stack(&head);
            return NULL;
        }
        if (!head)
            head = n, tail = n;
        else
            tail->next = n, tail = n;
    }
    return head;
}

void free_stack(t_stack **stack)
{
    t_stack *tmp;
    if (!stack || !*stack) return;
    while (*stack)
    {
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

void print_stack(t_stack *stack)
{
    while (stack)
    {
        char buf[32];
        int n = snprintf(buf, sizeof(buf), "%d\n", stack->value);
        write(1, buf, n);
        stack = stack->next;
    }
}

int stack_size(t_stack *stack)
{
    int c = 0;
    while (stack)
    {
        c++;
        stack = stack->next;
    }
    return c;
}

int check_duplicates(t_stack *stack)
{
    int size = stack_size(stack);
    int *arr = stack_to_array(stack, size);
    if (!arr) return 1;
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            if (arr[i] == arr[j])
            {
                free(arr);
                return 1;
            }
    free(arr);
    return 0;
}

int *stack_to_array(t_stack *stack, int size)
{
    int *arr = malloc(sizeof(int) * size);
    int i = 0;
    if (!arr) return NULL;
    while (stack && i < size)
    {
        arr[i++] = stack->value;
        stack = stack->next;
    }
    return arr;
}
