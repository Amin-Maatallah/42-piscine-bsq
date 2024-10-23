/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacles_grid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 18:37:12 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/21 18:37:26 by amaatall         ###   ########.fr       */
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

int	**get_obstacles_grid(t_map map)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	**obstacles_grid;

	obstacles_grid = init_obstacles_grid(&obstacles_grid, map.rows, map.cols);
	if (obstacles_grid == NULL)
		return (NULL);
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
						++obstacles_grid[k][l];
				}
			}
		}
	}
	return (obstacles_grid);
}
