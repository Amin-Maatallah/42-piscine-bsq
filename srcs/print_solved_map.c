/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solved_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:01:51 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/22 19:01:58 by amaatall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include <stdio.h>

void	print_solved_map(t_square square, t_map map)
{
	int		x;
	int		y;
	int		size;
	char	filled;
	char	**grid;

	grid = map.grid;
	filled = map.filled;
	x = square.x;
	y = square.y;
	size = square.size;
	if (x >= 0 && x < map.rows && y >= 0 && y < map.cols)
	{
		map.grid[x][y] = map.filled;
	}
	// while (x < square.x + size)
	// {
	// 	while (y < square.y + size)
	// 	{
	// 		map.grid[x][y] = map.filled;
	// 		y++;
	// 	}
	// 	x++;
	// }
	print_grid(grid, map.rows, map.cols);
}
