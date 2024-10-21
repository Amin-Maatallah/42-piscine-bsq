/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:49:43 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/21 19:20:35 by amaatall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_square.h"
#include <stdlib.h>

int	test_square(int **grid, int x, int y, int size)
{
	int	a;
	int	b;
	int	c;
	int	d;

	size -= 1;
	a = grid[x][y];
	b = grid[x + size][y];
	c = grid[x][y + size];
	d = grid[x + size][y + size];
	if (d - c - b + a > 0)
	{
		return (1);
	}
	return (0);
}

t_square	test_squares(int **grid, int rows, int cols)
{
	t_square square;
	int size;
	int x;
	int y;

	size = 2;
	while (x <= rows && y <= cols)
	{
		x = 0;
		while (x + size <= rows)
		{
			y = 0;
			while (y + size <= cols)
			{
				if (test_square(grid, x, y, size))
				{
					square.x = x;
					square.y = y;
					square.size = size;
					return (square);
				}
				y++;
			}
			x++;
		}
		size--;
	}
	return (square);
};
