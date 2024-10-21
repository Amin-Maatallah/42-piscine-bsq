/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:04:28 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 12:32:45 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "bsq.h"

/* Converts the dict file into one long string */
int	file_to_str(char *filename, char *str)
{
	int		file;
	int		read_byte;
	char	buffer;
	int		i;

	i = 0;
	file = open(filename, O_RDONLY);
	if (-1 == file)
		return (-1);
	read_byte = read(file, &buffer, 1);
	while (read_byte)
	{
		if (-1 == read_byte)
			return (-1);
		str[i] = buffer;
		i++;
		read_byte = read(file, &buffer, 1);
	}
	close(file);
	str[i] = '\0';
	return (0);
}

int	count_file(char *filename)
{
	int		file;
	int		read_byte;
	char	buffer;
	int		count;

	file = open(filename, O_RDONLY);
	if (-1 == file)
		return (-1);
	read_byte = read(file, &buffer, 1);
	count = 0;
	while (read_byte)
	{
		if (-1 == read_byte)
			return (-1);
		count++;
		read_byte = read(file, &buffer, 1);
	}
	return (count);
}

int	read_map(char *filename)
{
	int	count;
	char	*map_str;

	count = count_file(filename);
	map_str = malloc(sizeof(char) * (count + 1));
	file_to_str(filename, map_str);
	is_valid_map(map_str);
	free(map_str);
	return (0);
}
