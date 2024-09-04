/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:47:00 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 17:27:58 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_error_and_exit(char *mes)
{
	ft_printf("Error\n%s", mes);
	exit(0);
}

void	destory_and_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}
