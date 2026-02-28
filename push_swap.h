#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
    int value;
    int index;
    struct s_stack *next;
} t_stack;

t_stack *create_stack_from_args(int argc, char **argv);
void free_stack(t_stack **stack);
void print_stack(t_stack *stack);

int stack_size(t_stack *stack);
int check_duplicates(t_stack *stack);
int *stack_to_array(t_stack *stack, int size);

/* indexed + sorting */
void index_stack(t_stack *stack);
void radix_sort(t_stack **a, t_stack **b);
void chunk_sort(t_stack **a, t_stack **b);

int get_pos_in_range(t_stack *stack, int low, int high);
int find_max_pos(t_stack *stack);
void bring_pos_to_top_a(t_stack **a, int pos);
void bring_pos_to_top_b(t_stack **b, int pos);

/* printed operations */
void sa(t_stack **a);
void sb(t_stack **b);
void pa(t_stack **a, t_stack **b);
void pb(t_stack **a, t_stack **b);
void ra(t_stack **a);
void rb(t_stack **b);
void rra(t_stack **a);
void rrb(t_stack **b);

/* internal node operations (used by checker too) */
void swap_nodes(t_stack **stack);
void push_nodes(t_stack **from, t_stack **to);
void rotate_nodes(t_stack **stack);
void rev_rotate_nodes(t_stack **stack);

#endif
