/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacles_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:06:32 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/23 20:06:34 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

void	free_obstacles_grid(int ***obstacles_grid, int rows)
{
	int	i;

	i = -1;
	while (++i < rows)
		free((*obstacles_grid)[i]);
	free(*obstacles_grid);
}

int	**init_obstacles_grid(int ***obstacles_grid, int rows, int cols)
{
	int	i;
	int	j;

	*obstacles_grid = (int **)malloc(rows * sizeof(int *));
	if (*obstacles_grid == NULL)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		(*obstacles_grid)[i] = (int *)malloc(cols * sizeof(int));
		if ((*obstacles_grid)[i] == NULL)
			return (NULL);
		j = -1;
		while (++j < cols)
			(*obstacles_grid)[i][j] = 0;
	}
	return (*obstacles_grid);
}

void	fill_obstacles_grid(int ***obstacles_grid, t_map map)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (++i < map.rows)
	{
		j = -1;
		while (++j < map.cols)
		{
			if (map.grid[i][j] == map.obstacle)
			{
				k = i - 1;
				while (++k < map.rows)
				{
					l = j - 1;
					while (++l < map.cols)
						++(*obstacles_grid)[k][l];
				}
			}
		}
	}
}

int	**get_obstacles_grid(t_map map)
{
	int	**obstacles_grid;

	obstacles_grid = init_obstacles_grid(&obstacles_grid, map.rows, map.cols);
	if (obstacles_grid == NULL)
		return (NULL);
	fill_obstacles_grid(&obstacles_grid, map);
	return (obstacles_grid);
}
