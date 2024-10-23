/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:18:56 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/23 15:22:29 by amaatall         ###   ########.fr       */
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