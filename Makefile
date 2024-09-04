# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/04 14:36:29 by yokamura          #+#    #+#              #
#    Updated: 2023/04/23 20:18:46 by yokamura         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	so_long
OBJ_DIR		:=	obj
SRC_DIR		:=	src

CC			:=	cc
CFLAGS		:=	-Wall -Werror -Wextra
HEADERS		:=  includes

LIBFT_DIR	:=	lib/libft
LIBFT		:=	$(LIBFT_DIR)/libft.a
HEADERS		+=	$(LIBFT_DIR)/includes

LIBFT_PRINTF_DIR	:=	lib/ft_printf
LIBFT_PRINTF		:=	$(LIBFT_PRINTF_DIR)/libftprintf.a
HEADERS				+=	$(LIBFT_PRINTF_DIR)/includes

LIB_GET_NEXT_LINE_DIR	:=	lib/get_next_line
LIB_GET_NEXT_LINE		:=	$(LIB_GET_NEXT_LINE_DIR)/get_next_line.a
HEADERS					+=	$(LIB_GET_NEXT_LINE_DIR)/includes

LIBMLX_DIR	:=	lib/mlx
LIBMLX		:=	$(LIBMLX_DIR)/libmlx.a
HEADERS		+= $(LIBMLX_DIR)

LXFLAGS		:=	-L/usr/X11R6/lib -lX11 -lXext -framework OpenGL -framework AppKit
INCLUDES	:=	$(addprefix -I , $(HEADERS))

SRCS_NAME	:=	main.c free_and_error.c hook_list.c \
			is_correct_map.c make_init.c make_map.c \
			map_count.c so_long_main.c render_image.c \
			so_long_utils.c

SRCS	:= $(addprefix $(SRC_DIR)/, $(SRCS_NAME))
OBJECTS	:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME):   $(LIBFT) $(LIBMLX) $(LIBFT_PRINTF) $(LIB_GET_NEXT_LINE) $(OBJECTS)
	$(CC) $(CFLAGS) -o $(NAME) $(LIBFT) $(LIBFT_PRINTF) $(LIB_GET_NEXT_LINE) $(LIBMLX) $(LXFLAGS) $(OBJECTS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)
	
$(LIBFT_PRINTF):
	make -C $(LIBFT_PRINTF_DIR)

$(LIB_GET_NEXT_LINE):
	make -C $(LIB_GET_NEXT_LINE_DIR)

$(LIBMLX) : 
	make -C $(LIBMLX_DIR)

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(LIBFT_PRINTF_DIR)
	make clean -C $(LIB_GET_NEXT_LINE_DIR)
	make clean -C $(LIBMLX_DIR)

fclean:	clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	make fclean -C $(LIBFT_PRINTF_DIR)
	make fclean -C $(LIB_GET_NEXT_LINE_DIR)

re: fclean all

.PHONY: all fclean clean re norm test
