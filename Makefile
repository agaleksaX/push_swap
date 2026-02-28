Cc = gcc
CC = gcc
CFLAGS = -Wall -Wextra -Werror


SRC = main.c stack.c ops.c utils.c sort_radix.c sort_chunks.c ops_internal.c
OBJ = $(SRC:.c=.o)

NAME = push_swap
CHECKER = checker

all: $(NAME) $(CHECKER)

$(NAME): main.o stack.o ops.o utils.o sort_radix.o sort_chunks.o ops_internal.o
	$(CC) $(CFLAGS) -o $(NAME) main.o stack.o ops.o utils.o sort_radix.o sort_chunks.o ops_internal.o

$(CHECKER): checker.o stack.o utils.o sort_radix.o ops_internal.o ops.o
	$(CC) $(CFLAGS) -o $(CHECKER) checker.o stack.o utils.o sort_radix.o ops_internal.o ops.o

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) checker.o

fclean: clean
	rm -f $(NAME) $(CHECKER)

re: fclean all
