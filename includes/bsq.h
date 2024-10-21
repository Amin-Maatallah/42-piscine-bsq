/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:12:58 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 13:12:22 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	int		cols;
	int		rows;
	char	empty;
	char	obstacle;
	char	filled;
}	t_map;

int		ft_atoi(char *str);
int		read_map(char *filename);
int		is_valid_map(char *map_str);
char	*ft_strdup(char *str, int to);
int		ft_strlen(char *str);

#endif
