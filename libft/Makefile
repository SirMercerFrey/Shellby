NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror -I.

SRC = \
	$(wildcard libft/*.c) \
	$(wildcard ft_printf/*.c) \
	$(wildcard get_next_line/*.c)

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) rcs $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
