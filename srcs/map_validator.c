/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:45:05 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 19:55:39 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

t_map	parse_first_line(char *map_str)
{
	int		i;
	t_map	map;

	i = 0;
	while (map_str[i] && '\n' != map_str[i])
		i++;
	map.filled = map_str[--i];
	map.obstacle = map_str[--i];
	map.empty = map_str[--i];
	map.rows = ft_atoi(map_str);
	return (map);
}

char	**make_grid(char *map_str, int rows, int cols)
{
	int		i;
	int		j;
	int		count;
	char	**grid;

	i = 0;
	count = 0;
	grid = malloc(sizeof(char *) * (rows + 1));
	while (count < rows)
	{
		grid[count] = ft_strdup(map_str, 14);
		map_str = &map_str[16];
		count++;
	}
	return (grid);
}

t_map	make_map(char *map_str)
{
	t_map	map;
	int		i;

	map = parse_first_line(map_str);
	i = 0;
	while (map_str[i] && '\n' != map_str[i])
		i++;
	if (map.rows > 0)
	{
		map_str = &map_str[i + 1];
		map.cols = (ft_strlen(map_str) - map.rows) / map.rows;
		if (0 != map.cols % map.rows)
			map.cols = -1;
		if (map.cols > 0)
			map.grid = make_grid(map_str, map.rows, map.cols);
	}
	else
		map.cols = -1;
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
