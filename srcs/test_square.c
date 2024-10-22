/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:49:43 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/22 15:09:54 by amaatall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "square.h"
#include <stdlib.h>

int	test_square(int **grid, int x, int y, int size)
{
	int	a;
	int	b;
	int	c;
	int	d;

	if (x == 0 || y == 0)
		a = 0;
	else
		a = grid[x - 1][y - 1];
	if (y == 0)
		b = 0;	
	else
		b = grid[x + size - 1][y - 1];
	if (x == 0)
		c = 0;
	else
		c = grid[x - 1][y + size - 1];
	d = grid[x + size - 1][y + size - 1];
	return (!(d - c - b + a > 0));
}

t_square	test_squares(int **grid, int rows, int cols)
{
	t_square square;
	int size;
	int x;
	int y;

	x = 0;
	y = 0;
	size = 1;

	square.x = 0;
	square.y = 0;
	square.size = 0;

	while (1)
	{
		if (test_square(grid, x, y, size))
		{
			square.x = x;
			square.y = y;
			square.size = size;
			size++;
			continue;
		}
		y++;
		if ((y + size - 1) >= cols)
		{
			x++;
			y = 0;
		}
		if ((x + size - 1) >= rows)
			break ;
	}
	return (square);
};
