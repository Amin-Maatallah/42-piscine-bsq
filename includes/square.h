/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:56:30 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/23 20:05:43 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQUARE_H
# define SQUARE_H

# include "bsq.h"

typedef struct s_square
{
	int		y;
	int		x;
	int		size;
}			t_square;

typedef struct s_square_test
{
	int		y;
	int		x;
	int		size;
}			t_square_test;

void		test_square_init(t_square_test *test);
void		change_square(t_square_test *test, t_square *square, int size,
				int size2);

t_square	test_squares(int **grid, int rows, int cols);

void		print_solved_map(t_square square, t_map map);

#endif
