NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRC = mainprintf.c ft_printffuncts.c ft_printf_utilis.c

OSRC = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OSRC)
	ar rcs $(NAME) $(OSRC)

clean:
	rm -f $(OSRC)

fclean:
	rm -f $(OSRC) $(NAME)

re: fclean all

.PHONY: all re clean fclean
