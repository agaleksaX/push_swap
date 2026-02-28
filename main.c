#include "push_swap.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b = NULL;

    if (argc < 2)
    {
        write(1, "Usage: ./push_swap <numbers...>\n", 30);
        return (0);
    }
    a = create_stack_from_args(argc, argv);
    if (!a)
    {
        write(1, "Error: invalid input\n", 22);
        return (1);
    }
    if (check_duplicates(a))
    {
        write(1, "Error\n", 6);
        free_stack(&a);
        return (1);
    }
    index_stack(a);
    if (stack_size(a) <= 100)
        chunk_sort(&a, &b);
    else
        radix_sort(&a, &b);
    free_stack(&a);
    free_stack(&b);
    return (0);
}
