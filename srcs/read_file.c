/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:04:28 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/23 15:16:36 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

/* Converts the file into one long string */
int	read_to_str(char *filename, char *str)
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
		{
			close(file);
			return (-1);
		}
		str[i] = buffer;
		i++;
		read_byte = read(file, &buffer, 1);
	}
	close(file);
	str[i] = '\0';
	return (0);
}

/* Counts how many bytes are in the file */
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
		{
			close(file);
			return (-1);
		}
		count++;
		read_byte = read(file, &buffer, 1);
	}
	close(file);
	return (count);
}

/* Returns NULL on mistakes or empty file */
char	*file_to_str(char *filename)
{
	int		count;
	char	*map_str;
	int		error;

	count = count_file(filename);
	if (count < 1)
		return (NULL);
	map_str = malloc(sizeof(char) * (count + 1));
	if (!map_str)
		return (NULL);
	error = read_to_str(filename, map_str);
	if (1 == error)
		return (NULL);
	return (map_str);
}
