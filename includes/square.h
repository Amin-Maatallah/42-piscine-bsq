/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:18:56 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/22 15:12:39 by amaatall         ###   ########.fr       */
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

int			test_square(int **grid, int x, int y, int size);
t_square	test_squares(int **grid, int rows, int cols);

void		print_solved_map(t_square square, t_map map);

#endif