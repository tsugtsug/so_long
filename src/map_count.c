/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:07:54 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 17:46:26 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_01cep(char c, t_map_checker *map)
{
	if (c == '0')
		map->num_0++;
	else if (c == '1')
		map->num_1++;
	else if (c == 'C')
		map->num_c++;
	else if (c == 'E')
		map->num_e++;
	else if (c == 'P')
		map->num_p++;
	else
		print_error_and_exit("The number of CPE is incorrect\n");
}

int	is_all_one(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

void	count_characters(char *line, t_map_checker *map, int count)
{
	int	i;

	i = 0;
	map->flag_last_line = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (count == 0 && line[i] != '1')
			print_error_and_exit("The walls are not only 1\n");
		count_01cep(line[i], map);
		i++;
	}
	if (is_all_one(line) == 0)
		map->flag_last_line = 1;
	if (line[0] != '1' || line[i - 1] != '1')
		print_error_and_exit("The side walls are not correct\n");
	if (map->num_row == 0)
		map->num_row = i;
	else if (map->num_row != i)
		print_error_and_exit("The number of row is incorrect\n");
	map->num_line++;
}
