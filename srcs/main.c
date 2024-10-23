/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:56:38 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/23 15:39:02 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>

/* Frees any allocated memory */
void	free_all(t_map map)
{
	int	i;

	if (map.cols > 0)
	{
		i = 0;
		while (i < map.rows)
		{
			free(map.grid[i]);
			i++;
		}
		free(map.grid);
	}
}

/* Builds a map from a valid string */
void	make_map(char *map_str, char *filename)
{
	t_legend	legend;
	t_map		map;

	legend = parse_legend(map_str);
	if (1 == legend.is_valid)
	{
		map = parse_map(map_str, legend);
		if (map.is_valid)
		{
			map.filename = filename;
			if (1 == solve_map(map))
				write(2, "map error\n", 10);
			free_all(map);
		}
		else
			write(2, "map error\n", 10);
	}
	else
		write(2, "map error\n", 10);
	free(map_str);
}

/* Enter a map from the keybaord instead of a file */
void	use_kb(void)
{
	char	buffer;
	int		bytes_read;
	char	*str;
	int		len;

	str = malloc(1);
	str[0] = '\0';
	bytes_read = read(1, &buffer, 1);
	while (bytes_read)
	{
		str = add_char_to_str(str, buffer);
		bytes_read = read(1, &buffer, 1);
	}
	len = ft_strlen(str);
	if (len > 0 && '\n' != str[len - 1])
	{
		str = add_char_to_str(str, '\n');
		write(1, "\n", 1);
	}
	make_map(str, "From kb");
}

/* No args = stdin, otherwise a list of map files */
int	main(int argc, char *argv[])
{
	char		*map_str;
	int			i;

	if (1 == argc)
		use_kb();
	else if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			map_str = file_to_str(argv[i]);
			if (NULL == map_str)
				write(2, "map error\n", 10);
			else
				make_map(map_str, argv[i]);
			i++;
		}
	}
	return (0);
}
