/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:49:43 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/21 20:23:50 by amaatall         ###   ########.fr       */
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
		return (0);
	}
	return (1);
}

t_square	test_squares(int **grid, int rows, int cols)
{
	t_square square;
	int size;
	int x;
	int y;

	size = 2;

	x = 0;
	y = 0;

	square.x = 0;
	square.y = 0;
	square.size = 0;

	while (1)
	{
		if (test_square(grid, x, y, size))
		{
			if (size > square.size)
			{
				square.x = x;
				square.y = y;
				square.size = size;
			}
			size++;
		}
		else
		{
			if (y + size < cols)
			{
				y++;
			}
			else if (x + size < rows)
			{
				x++;
				y = 0;
			}
			else
			{
				break ;
			}
		}
	}
	return (square);
};
