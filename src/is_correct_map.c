/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_correct_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 14:49:03 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 20:28:55 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	is_nom_map_correct(char *nom)
{
	int	i;

	i = 0;
	while (nom[i])
		i++;
	if (ft_strlen(nom) <= 4)
		print_error_and_exit("The name of map is too short\n");
	i = i - 4;
	if (nom[i] == '.' && nom[i + 1] == 'b'
		&& nom[i + 2] == 'e' && nom[i + 3] == 'r')
		return ;
	else
		print_error_and_exit("The name of map is incorrect\n");
}

void	check_the_parameter(t_map_checker *map)
{
	if (map->num_e == 0)
		print_error_and_exit("The parameter E doesn't exist\n");
	if (map->num_e != 1)
		print_error_and_exit("The number of E is not only one\n");
	if (map->num_p == 0)
		print_error_and_exit("The parameter P doesn't exist\n");
	if (map->num_p != 1)
		print_error_and_exit("The number of P is not only one\n");
	if (map->num_c == 0)
		print_error_and_exit("You need to have at least one C in your map\n");
}

t_map_checker	*check_inside_the_map(int fd, t_map_checker *checker)
{
	char			*line;
	int				count;

	make_init_map_checker(checker);
	count = 0;
	while (1)
	{
		count++;
		line = get_next_line(fd);
		if (!line || *line == '\n')
			break ;
		count_characters(line, checker, count);
		free(line);
	}
	if (count == 1)
		print_error_and_exit("The map should start from the first line\n");
	if (line && *line == '\n')
		free(line);
	if (checker->flag_last_line == 0)
		print_error_and_exit("The walls are not only 1\n");
	check_the_parameter(checker);
	return (checker);
}

void	open_file_and_check(char *nom_map, t_map_checker *checker)
{
	int				fd;

	fd = open(nom_map, O_RDONLY);
	if (fd < 0)
		print_error_and_exit("You couldn't open the file\n");
	check_inside_the_map(fd, checker);
	close(fd);
}
