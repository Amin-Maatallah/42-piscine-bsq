/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solved_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:07:17 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/23 20:07:19 by lwillis          ###   ########.fr       */
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
