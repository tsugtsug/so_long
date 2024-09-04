/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yokamura <yokamura@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:13:03 by yokamura          #+#    #+#             */
/*   Updated: 2023/04/23 19:19:16 by yokamura         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_vars			vars;
	t_map			map;
	t_map_checker	checker;
	char			*nom_map;

	if (argc == 2)
	{
		is_nom_map_correct(argv[1]);
		nom_map = ft_strjoin("maps/", argv[1]);
		if (nom_map == NULL)
			print_error_and_exit("The name of map is incorrect\n");
		open_file_and_check(nom_map, &checker);
		make_map(nom_map, &map, &checker);
		so_long_main(&vars, &map);
	}
	exit(0);
}
