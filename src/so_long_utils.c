/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 11:35:03 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 19:55:20 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_strjoin_for_map(char *s1, char *s2)
{
	char	*rtn;
	int		i;
	int		j;

	rtn = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (rtn == NULL)
		print_error_and_exit("malloc Error\n");
	i = 0;
	j = 0;
	if (s1)
	{
		while (s1[i] != '\0')
			rtn[j++] = s1[i++];
	}
	while (*s2)
		rtn[j++] = *s2++;
	rtn[j] = '\0';
	if (s1 != NULL)
		free(s1);
	return (rtn);
}

void	get_position_player(t_map *map, int *pos)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->line_ptr[y][x] == 'P')
			{
				pos[0] = x;
				pos[1] = y;
			}
			x++;
		}
		y++;
	}
}

void	set_xy(t_vars *vars, char c, int *x, int *y)
{
	if (c == UP)
	{
		*y = vars->y - 1;
		*x = vars->x;
	}
	else if (c == LEFT)
	{
		*x = vars->x - 1;
		*y = vars->y;
	}
	else if (c == DOWN)
	{
		*y = vars->y + 1;
		*x = vars->x;
	}
	else if (c == RIGHT)
	{
		*x = vars->x + 1;
		*y = vars->y;
	}
	else
	{
		*x = vars->x;
		*y = vars->y;
	}
}
