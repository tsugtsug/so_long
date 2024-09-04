/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 21:26:13 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 20:09:11 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	make_pointer_and_num(t_map *map, int flag)
{
	int	i;

	i = 0;
	map->line_ptr = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (map->line_ptr == NULL)
		print_error_and_exit("malloc Error\n");
	while (i < map->height)
	{
		map->line_ptr[i] = &(map->str[(map->width + 1) * i]);
		i++;
	}
	map->line_ptr[i] = NULL;
	if (flag == 1)
	{
		i = 0;
		while (map->str[i] != '\0')
		{
			if (map->str[i] == 'C')
				map->num_c++;
			if (map->str[i] == 'E')
				map->num_e++;
			i++;
		}
	}
}

void	verifier_map_recur(t_map *map, int x, int y)
{
	if (x >= 0 && x <= map->width && y >= 0
		&& y <= map->height && map->line_ptr[y][x] != '1')
	{
		if (map->line_ptr[y][x] == 'C')
			map->num_c++;
		else if (map->line_ptr[y][x] == 'E')
			map->num_e++;
		map->line_ptr[y][x] = '1';
		verifier_map_recur(map, x - 1, y);
		verifier_map_recur(map, x + 1, y);
		verifier_map_recur(map, x, y - 1);
		verifier_map_recur(map, x, y + 1);
	}
}

void	is_map_available(t_map *map, t_map_checker *checker)
{
	int	pos[2];

	get_position_player(map, pos);
	verifier_map_recur(map, pos[0], pos[1]);
	if (map->num_c != checker->num_c || map->num_e != checker->num_e)
		print_error_and_exit("The number of CPE is incorrect\n");
	free(map->str);
	free(map->line_ptr);
}

void	make_map_and_check(char *nom_map, t_map *map, t_map_checker *checker)
{
	char	*line;
	int		fd;

	fd = open(nom_map, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("You couldn't open the file\n");
	map_init(map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || line[0] == '\n')
			break ;
		if (map->height == 0)
			map->width = ft_strlen(line) - 1;
		map->str = ft_strjoin_for_map(map->str, line);
		map->height++;
		free(line);
	}
	if (line && *line == '\n')
		free(line);
	make_pointer_and_num(map, 0);
	close(fd);
	is_map_available(map, checker);
}

void	make_map(char *nom_map, t_map *map, t_map_checker *checker)
{
	char	*line;
	int		fd;

	make_map_and_check(nom_map, map, checker);
	fd = open(nom_map, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("You couldn't open the map\n");
	map_init(map);
	while (1)
	{
		line = get_next_line(fd);
		if (!line || *line == '\n')
			break ;
		if (map->height == 0)
			map->width = ft_strlen(line) - 1;
		map->str = ft_strjoin_for_map(map->str, line);
		map->height++;
		free(line);
	}
	if (line && *line == '\n')
		free(line);
	make_pointer_and_num(map, 1);
	close(fd);
	free(nom_map);
}
