/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:53:37 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 19:49:29 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	so_long_main(t_vars *vars, t_map *map)
{
	t_data_ptr	img_ptr;
	t_data_mini	mini;

	vars_init(vars, map, &img_ptr);
	img_init(vars, &img_ptr, map->width, map->height);
	mini_init(vars, map, &img_ptr, &mini);
	render_image(vars, map, &img_ptr);
	mlx_hook(vars->win, 2, 1, &my_key_hook, vars);
	mlx_hook(vars->win, 17, 1, &my_close_avec_redcross, vars);
	mlx_expose_hook(vars->win, render_for_mini, &mini);
	mlx_loop(vars->mlx);
}
