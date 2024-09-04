/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 20:35:30 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 19:55:30 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include "../lib/mlx/mlx.h"
# include "../lib/libft/includes/libft.h"
# include "../lib/ft_printf/includes/ft_printf.h"
# include "../lib/get_next_line/includes/get_next_line.h"

# define WIN_WIDTH 32
# define WIN_HEIGHT 32
# define UP 'W'
# define DOWN 'S'
# define LEFT 'A'
# define RIGHT 'D'
# define KEYCODE_W 119
# define KEYCODE_A 97
# define KEYCODE_S 115
# define KEYCODE_D 100
# define WIDTH_MAX 79
# define HEIGHT_MAX 41

typedef struct s_map
{
	char	*str;
	char	**line_ptr;
	int		width;
	int		height;
	int		num_c;
	int		num_e;
}				t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
}				t_data;

typedef struct s_data_ptr
{
	t_data	*img_0;
	t_data	*img_1;
	t_data	*img_p;
	t_data	*img_c;
	t_data	*img_e;
}				t_data_ptr;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_map		*map;
	t_data_ptr	*img;
	int			y;
	int			x;
	int			foot;
}				t_vars;

typedef struct s_map_checker
{
	int	num_0;
	int	num_1;
	int	num_c;
	int	num_e;
	int	num_p;
	int	num_row;
	int	num_line;
	int	flag_last_line;
}				t_map_checker;

typedef struct s_data_mini
{
	t_vars		*vars;
	t_map		*map;
	t_data_ptr	*img;
}				t_data_mini;

void	print_error_and_exit(char *mes);
void	make_init_map_checker(t_map_checker *map);
void	count_characters(char *line, t_map_checker *map, int count);
void	is_nom_map_correct(char *nom);
void	open_file_and_check(char *nom_map, t_map_checker *checker);
void	vars_init(t_vars *vars, t_map *map, t_data_ptr *img);
int		my_key_hook(int keycode, t_vars *vars);
int		my_close_avec_redcross(t_vars *vars);
void	map_init(t_map *map);
void	make_map(char *nom_map, t_map *map, t_map_checker *checker);
void	img_init(t_vars *vars, t_data_ptr *ptr, int width, int height);
void	so_long_main(t_vars *vars, t_map *map);
void	load_map_and_print(t_vars *vars, t_map *map, t_data_ptr *img);
void	render_image(t_vars *vars, t_map *map, t_data_ptr *img);
void	get_position_player(t_map *map, int *pos);
void	destory_and_exit(t_vars *vars);
char	*ft_strjoin_for_map(char *s1, char *s2);
int		render_for_mini(t_data_mini *data);
void	mini_init(t_vars *vars, t_map *map, t_data_ptr *img, t_data_mini *mini);
void	set_xy(t_vars *vars, char c, int *x, int *y);

#endif
