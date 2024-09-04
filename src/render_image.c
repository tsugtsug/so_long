/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 20:28:21 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 19:49:52 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	render_actuellement(t_vars *vars, t_data_ptr *img,
	int x, int y)
{
	if (vars->map->line_ptr[y][x] == '0')
		mlx_put_image_to_window(vars->mlx,
			vars->win, img->img_0->img, x * WIN_WIDTH, y * WIN_HEIGHT);
	else if (vars->map->line_ptr[y][x] == '1')
		mlx_put_image_to_window(vars->mlx,
			vars->win, img->img_1->img, x * WIN_WIDTH, y * WIN_HEIGHT);
	else if (vars->map->line_ptr[y][x] == 'C')
		mlx_put_image_to_window(vars->mlx,
			vars->win, img->img_c->img, x * WIN_WIDTH, y * WIN_HEIGHT);
	else if (vars->map->line_ptr[y][x] == 'P'
		|| vars->map->line_ptr[y][x] == 'B')
		mlx_put_image_to_window(vars->mlx,
			vars->win, img->img_p->img, x * WIN_WIDTH, y * WIN_HEIGHT);
	else if (vars->map->line_ptr[y][x] == 'E')
		mlx_put_image_to_window(vars->mlx,
			vars->win, img->img_e->img, x * WIN_WIDTH, y * WIN_HEIGHT);
}

void	render_image(t_vars *vars, t_map *map, t_data_ptr *img)
{
	int	y;
	int	x;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			render_actuellement(vars, img, x, y);
			x++;
		}
		y++;
	}
}

int	render_for_mini(t_data_mini *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < data->map->height)
	{
		x = 0;
		while (x < data->map->width)
		{
			render_actuellement(data->vars, data->img, x, y);
			x++;
		}
		y++;
	}
	return (0);
}
