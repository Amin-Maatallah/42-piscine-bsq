/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_legend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:40:04 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/22 20:10:23 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

char	*trim_start(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9'))
		i++;
	return (&str[i]);
}

int	get_rows(char *map_str, int len)
{
	int	i;
	int	number;

	number = 0;
	i = 0;
	while (map_str[i] >= '0' && map_str[i] <= '9' && i < len - 3)
	{
		number = (number * 10) + (map_str[i] - '0');
		i++;
	}
	return (number);
}

int	is_valid_legend(t_legend legend, char *map_str)
{
	int	rows;

	if (legend.empty == legend.obstacle)
		return (0);
	if (legend.empty == legend.filled)
		return (0);
	if (legend.obstacle == legend.filled)
		return (0);
	return (1);
}

int	count_first_line(char *map_str)
{
	int	i;

	i = 0;
	while (map_str[i] && '\n' != map_str[i])
	{
		i++;
	}
	return (i);
}

//TODO remove
void	print_legend(t_legend legend)
{
	printf("Rows: %i empty: %c obstacle: %c filled: %c is_valid: %i\n", legend.rows, legend.empty, legend.obstacle, legend.filled, legend.is_valid);
}

t_legend	parse_legend(char *map_str)
{
	int			count;
	t_legend	legend;

	map_str = trim_start(map_str);
	count = count_first_line(map_str);
	if (count < 4)
	{
		legend.is_valid = 0;
		return (legend);
	}
	legend.rows = get_rows(map_str, count);
	legend.filled = map_str[--count];
	legend.obstacle = map_str[--count];
	legend.empty = map_str[--count];
	legend.is_valid = is_valid_legend(legend, map_str);
	return (legend);
}
