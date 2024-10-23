/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:12:58 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/23 12:35:48 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	char	*filename;
	int		is_valid;
	int		cols;
	int		rows;
	char	empty;
	char	obstacle;
	char	filled;
	int		is_solvable;
	char	**grid;
}			t_map;

typedef	struct s_legend
{
	int		rows;
	char	empty;
	char	obstacle;
	char	filled;
	int		is_valid;
}	t_legend;

int			ft_atoi(char *str);
t_map		read_map_file(char *filename);
char		*ft_strdup(char *str, int to);
int			ft_strlen(char *str);
int			solve_map(t_map map);
void		print_grid(char **grid, int rows, int cols);
void		print_grid_int(int **grid, int rows, int cols);
int			**get_obstacles_grid(t_map map);
t_map		mock_map(void);
t_legend	parse_legend(char *map_str);
void		print_map(t_map map);
t_map		parse_map(char *map_str, t_legend legend);
char		*file_to_str(char *filename);
char		*add_char_to_str(char *str, char c);

#endif
