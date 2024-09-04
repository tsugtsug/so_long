/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 17:33:34 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 19:55:40 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	change_the_num_foot(t_vars *vars, int x, int y)
{
	vars->x = x;
	vars->y = y;
	vars->foot++;
	ft_printf("Move:%d\n", vars->foot);
}

void	move(t_vars *vars, char c)
{
	int	x;
	int	y;

	set_xy(vars, c, &x, &y);
	if (x >= 0 && x <= vars->map->width && y >= 0 && y <= vars->map->height
		&& vars->map->line_ptr[y][x] != '1')
	{
		if (vars->map->line_ptr[y][x] == 'E')
			vars->map->line_ptr[y][x] = 'B';
		else
		{
			if (vars->map->line_ptr[y][x] == 'C')
				vars->map->num_c--;
			vars->map->line_ptr[y][x] = 'P';
		}
		if (vars->map->line_ptr[vars->y][vars->x] == 'B')
			vars->map->line_ptr[vars->y][vars->x] = 'E';
		else
			vars->map->line_ptr[vars->y][vars->x] = '0';
		change_the_num_foot(vars, x, y);
		render_image(vars, vars->map, vars->img);
	}
}

void	end_of_game(t_vars *vars)
{
	ft_printf("Félicitation!\n");
	destory_and_exit(vars);
}

int	my_key_hook(int keycode, t_vars *vars)
{
	if (keycode == 65307)
		destory_and_exit(vars);
	else if (keycode == KEYCODE_W)
		move(vars, UP);
	else if (keycode == KEYCODE_A)
		move(vars, LEFT);
	else if (keycode == KEYCODE_S)
		move(vars, DOWN);
	else if (keycode == KEYCODE_D)
		move(vars, RIGHT);
	if ((vars->map->line_ptr[vars->y][vars->x] == 'E'
		|| vars->map->line_ptr[vars->y][vars->x] == 'B')
		&& vars->map->num_c == 0)
		end_of_game(vars);
	return (0);
}

int	my_close_avec_redcross(t_vars *vars)
{
	destory_and_exit(vars);
	return (0);
}
