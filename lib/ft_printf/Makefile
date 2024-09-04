NAME		:= libftprintf.a

SRC_FILE	:= ft_printf.c ft_put_cs.c ft_put_lowerx.c ft_put_upperx.c ft_put_p.c ft_put_diu.c
SRC_DIR		:= src
SRCS		:= $(addprefix $(SRC_DIR)/, $(SRC_FILE))

OBJ_DIR		:= obj
OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRC_FILE:%.c=%.o))

CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror

RM			:= rm -f

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	$(RM) $(OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
