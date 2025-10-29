NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -Ilibft -Iprintf

LFLAGS = -Lresources/libft -Lresources/printf -lft -lftprintf

SRCS = push_swap.c cleaning.c utils.c sort_index.c rotates.c \
		swaps_and_push.c  reverses.c small_case.c \
			radix_logic.c parsing.c \

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = resources/libft

PRINTF_DIR = resources/printf

LIBFT_A = $(LIBFT_DIR)/libft.a

PRINTF_A = $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(LIBFT_A):
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)

$(NAME): $(OBJS) $(LIBFT_A) $(PRINTF_A)
	$(CC) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo "\033[1;32m¡¡Compilación correcta! [✔]: $(NAME)"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

RM = rm -f

clean:
	make -C $(LIBFT_DIR) clean
	make -C $(PRINTF_DIR) clean
	$(RM) $(OBJS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	make -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re