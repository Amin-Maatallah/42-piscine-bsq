/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:45:05 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/22 20:14:20 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char	**fill_grid(char *map_str, int rows, int cols)
{
	int		count;
	char	**grid;

	grid = malloc(sizeof(char *) * rows);
	if (!grid)
		return (NULL);
	count = 0;
	while (count < rows)
	{
		grid[count] = ft_strdup(map_str, cols - 1);
		if (!grid[count])
			return (NULL);
		map_str = &map_str[cols + 1];
		count++;
	}
	return (grid);
}

int	does_grid_match_legend(char *map_str, t_map map)
{
	int		i;
	char	c;

	i = 0;
	while (map_str[i])
	{
		c = map_str[i];
		if (!(c == map.empty || c == map.obstacle || c == map.filled || '\n' == c))
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_grid(char *map_str, t_map map)
{
	int	i;
	int	count;
	int	len;

	if (0 == does_grid_match_legend(map_str, map))
		return (0);
	i = map.cols;
	count = 0;
	len = ft_strlen(map_str);
	while (i < len)
	{	
		if ('\n' == map_str[i])
			count++;
		i += map.cols + 1;
	}
	return (count == map.rows);
}

// TODO remove
void	print_map(t_map map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	printf("%s\n", map.filename);
	printf("Rows: %i cols: %i valid: %i\n", map.rows, map.cols, map.is_valid);
	printf("Empty: %c obstacle: %c filled: %c\n", map.empty, map.obstacle, map.filled);
	while (i < map.rows)
	{
		while (j < map.cols)
		{
			write(1, &map.grid[i][j], 1);
			j++;
			if (j == map.cols)
				write(1, "\n", 1);
		}
		i++;
		j = 0;
	}
}

/* Counts the columns in the first line. This is used to determine validity */
int	count_cols(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i] && '\n' != map_str[i])
		i++;
	return (i);
}

t_map	parse_map(char *map_str, t_legend legend)
{
	int		i;
	t_map	map;

	map.rows = legend.rows;
	map.empty = legend.empty;
	map.obstacle = legend.obstacle;
	map.filled = legend.filled;
	i = 0;
	while ('\n' != map_str[i])
		i++;
	map_str = &map_str[i + 1];
	map.cols = count_cols(map_str);
	map.is_valid = is_valid_grid(map_str, map);
	if (1 == map.is_valid)
	{
		map.grid = fill_grid(map_str, map.rows, map.cols);
		if (NULL == map.grid)
			map.is_valid = 0;
	}
	return (map);
}
