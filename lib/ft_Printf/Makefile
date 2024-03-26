NAME = libftprintf.a
SOURCE = \
	ft_printf.c \
	ft_func.c \
	ft_func2.c

OBJECT = $(SOURCE:.c=.o)
ARCH = ar rc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS) -c

$(NAME): $(OBJECT)
	$(ARCH) $(NAME) $(OBJECT)

all : $(NAME)

clean:
	$(RM) $(OBJECT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
