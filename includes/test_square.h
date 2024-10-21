/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_square.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 19:18:56 by amaatall          #+#    #+#             */
/*   Updated: 2024/10/21 19:20:27 by amaatall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_SQUARE_H
# define TEST_SQUARE_H

typedef struct s_square
{
	int		y;
	int		x;
	int		size;
}			t_square;

int			test_square(int **grid, int x, int y, int size);
t_square	test_squares(int **grid, int rows, int cols);

#endif