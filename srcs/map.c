/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:03:24 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/23 15:05:50 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "square.h"

int	solve_map(t_map map)
{
	int			**ob_grid;
	t_square	square;

	ob_grid = get_obstacles_grid(map);
	square = test_squares(ob_grid, map.rows, map.cols);
	free_obstacles_grid(&ob_grid, map.rows);
	if (square.size == 0)
		return (1);
	print_solved_map(square, map);
	return (0);
}
