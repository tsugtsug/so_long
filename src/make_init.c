/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:02:03 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 19:48:02 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	make_init_map_checker(t_map_checker *map)
{
	map->num_1 = 0;
	map->num_0 = 0;
	map->num_c = 0;
	map->num_e = 0;
	map->num_p = 0;
	map->num_row = 0;
	map->num_line = 0;
	map->flag_last_line = 0;
}

void	vars_init(t_vars *vars, t_map *map, t_data_ptr *img)
{
	int	pos[2];

	vars->mlx = mlx_init();
	if (!vars->mlx)
		print_error_and_exit("mlx_init function Error\n");
	vars->win = mlx_new_window(vars->mlx, map->width * WIN_WIDTH,
			map->height * WIN_HEIGHT, "so_long");
	if (!vars->win)
		print_error_and_exit("mlx_new_window function Error\n");
	vars->map = map;
	vars->img = img;
	get_position_player(map, pos);
	vars->y = pos[1];
	vars->x = pos[0];
	vars->foot = 0;
}

void	map_init(t_map *map)
{
	map->str = NULL;
	map->line_ptr = NULL;
	map->width = 0;
	map->height = 0;
	map->num_c = 0;
	map->num_e = 0;
}

void	img_init(t_vars *vars, t_data_ptr *ptr, int width, int height)
{
	ptr->img_0 = (t_data *)malloc(sizeof(t_data));
	ptr->img_1 = (t_data *)malloc(sizeof(t_data));
	ptr->img_c = (t_data *)malloc(sizeof(t_data));
	ptr->img_p = (t_data *)malloc(sizeof(t_data));
	ptr->img_e = (t_data *)malloc(sizeof(t_data));
	if (!ptr->img_0 || !ptr->img_1 || !ptr->img_c
		|| !ptr->img_p || !ptr->img_e)
		print_error_and_exit("malloc Error\n");
	ptr->img_0->img = mlx_xpm_file_to_image(vars->mlx,
			"textures/blan.xpm", &width, &height);
	ptr->img_1->img = mlx_xpm_file_to_image(vars->mlx,
			"textures/block.xpm", &width, &height);
	ptr->img_c->img = mlx_xpm_file_to_image(vars->mlx,
			"textures/coin.xpm", &width, &height);
	ptr->img_e->img = mlx_xpm_file_to_image(vars->mlx,
			"textures/pipe.xpm", &width, &height);
	ptr->img_p->img = mlx_xpm_file_to_image(vars->mlx,
			"textures/mario.xpm", &width, &height);
}

void	mini_init(t_vars *vars, t_map *map,
	t_data_ptr *img, t_data_mini *mini)
{
	mini->vars = vars;
	mini->map = map;
	mini->img = img;
}
