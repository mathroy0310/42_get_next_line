NAME = get_next_line
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ) get_next_line.h
		@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)
fclean: clean
	@$(RM) $(NAME)
re: fclean all