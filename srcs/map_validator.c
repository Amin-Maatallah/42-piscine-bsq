/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:45:05 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 14:26:20 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

t_map	parse_first_line(char *map_str)
{
	int		i;
	t_map	map;

	map.rows = ft_atoi(map_str);
	if (map.rows > 0)
	{

	}
	return (map);
}

t_map	make_map(char *map_str)
{
	t_map	map;
	char	*first_line;

//	first_line = get_first_line(map_str);
//	printf("%s\n", first_line);
//	map.rows = ft_atoi(first_line);
//	if (map.rows > 0)
//	{
//		map.cols = (ft_strlen(map_str) - (map.rows) - ft_strlen(first_line) - 1) / map.rows;
//		if (0 != map.cols % map.rows)
//		map.cols = -1;
//		printf("cols: %i\n", map.cols);
//	}
//	free(first_line);
	return (map);
}

int	is_valid_legend(char *map_str)
{
	t_map	map;

	map = make_map(map_str);
	return (1);
}

int	is_valid_map(char *map_str)
{
	int	okay;

	okay = 0;
	okay += is_valid_legend(map_str);
	return (okay);
}
