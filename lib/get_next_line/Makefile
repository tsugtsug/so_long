NAME		:= get_next_line.a
SRC_FILES	:= get_next_line.c get_next_line_utils.c
SRC_DIR 	:= src
B_SRC_FILES	:= get_next_line_bonus.c get_next_line_utils_bonus.c
B_SRC_DIR 	:= b_src

SRCS		+= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
B_SRCS		+= $(addprefix $(B_SRC_DIR)/, $(B_SRC_FILES))

OBJ_DIR 	:= obj
B_OBJ_DIR	:= $(OBJ_DIR)
OBJS		:= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:%.c=%.o))
B_OBJS		:= $(addprefix $(B_OBJ_DIR)/, $(B_SRC_FILES:%.c=%.o))

CC			:= cc
CFLAGS 		:= -Wall -Wextra -Werror

RM			:= rm -f
AR			:= ar rc

ifdef WITH_BONUS
	OBJS	+= $(B_OBJS)
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(B_OBJ_DIR)/%.o: $(B_SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

bonus:
	make WITH_BONUS=1

clean:
	$(RM) $(OBJS) $(B_OBJS)
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re bonus