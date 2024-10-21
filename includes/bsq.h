/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:12:58 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 19:37:10 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	int		is_valid;
	int		cols;
	int		rows;
	char	empty;
	char	obstacle;
	char	filled;
	int		is_solvable;
	char	**grid;
}			t_map;

typedef struct s_solution
{
	int		col;
	int		row;
	int		size;
}			t_solution;

int			ft_atoi(char *str);
t_map		read_map_file(char *filename);
t_map		make_map(char *map_str);
int			is_valid_map(char *map_str);
char		*ft_strdup(char *str, int to);
int			ft_strlen(char *str);
int			solve_map(t_map map);
void		print_grid(char **grid, int rows, int cols);
int			**get_obstacles_grid(t_map map);
t_map		mock_map(void);

#endif
