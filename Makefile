
NAME = minishell

CC = cc
CFLAGS =  -g3 -I. $(INCLUDES)
LDFLAGS = -lreadline

INCLUDES = -Ilibft

SRC =	main.c \
		prodrome.c \
		print_banner.c \
		core.c \
		lexing.c \
		chars_check.c \
		checking.c \
		parsing.c \
		parsing_utils.c \
		quotes.c \
		environment.c \
		libft_utils.c
OBJ = $(SRC:.c=.o)

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@ $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) clean -C $(LIBFT_DIR)
	$(RM) $(OBJ)

fclean: clean
	@$(MAKE) fclean -C $(LIBFT_DIR)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
