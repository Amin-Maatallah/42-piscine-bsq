/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solved_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:01:51 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/23 14:34:54 by amaatall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"

void	print_solved_map(t_square square, t_map map)
{
	int	i;
	int	j;

	i = square.x - 1;
	while (++i < square.x + square.size)
	{
		j = square.y - 1;
		while (++j < square.y + square.size)
			map.grid[i][j] = map.filled;
	}
	print_grid(map.grid, map.rows, map.cols);
}
