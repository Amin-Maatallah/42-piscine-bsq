/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 17:49:43 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/23 15:22:42 by amaatall         ###   ########.fr       */
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

void	test_square_init(t_square_test *test)
{
	test->x = 0;
	test->y = 0;
	test->size = 1;
}

void	change_square(t_square_test *test, t_square *square, int size,
		int size2)
{
	if (size > size2)
	{
		square->x = test->x;
		square->y = test->y;
		square->size = test->size;
		test->size = size + 1;
	}
}

t_square	test_squares(int **grid, int rows, int cols)
{
	t_square		square;
	t_square_test	test;

	test_square_init(&test);
	square.x = 0;
	square.y = 0;
	square.size = 0;
	while (1)
	{
		if ((test.y + test.size - 1) >= cols)
		{
			test.x++;
			test.y = 0;
		}
		if ((test.x + test.size - 1) >= rows)
			break ;
		if (test_square(grid, test.x, test.y, test.size))
		{
			change_square(&test, &square, test.size, square.size);
			continue ;
		}
		test.y++;
	}
	return (square);
}
