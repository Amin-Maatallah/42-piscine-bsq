/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaatall <amaatall@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:42:23 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/23 12:34:43 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/* Appends a char to the end of a string */
char	*add_char_to_str(char *str, char c)
{
	int		len;
	int		i;
	char	*output;

	len = ft_strlen(str);
	output = malloc(len + 2);
	i = 0;
	while (str[i])
	{
		output[i] = str[i];
		i++;
	}
	output[i] = c;
	output[i + 1] = '\0';
	free(str);
	return (output);
}

/* Converts a string into an int */
int	ft_atoi(char *str)
{
	int	i;
	int	number;

	number = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (number);
}

/* Copies one str to another, up to a certain point */
char	*ft_strcpy(char *dest, char *src, int to)
{
	int	i;

	i = 0;
	while (src[i] && i < to)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

/* Duplicates a string, up to a certain point  */
char	*ft_strdup(char *src, int to)
{
	int		len;
	char	*ptr;

	len = to;
	ptr = malloc((len + 1) * sizeof(char *));
	ft_strcpy(ptr, src, to);
	ptr[len + 1] = '\0';
	return (ptr);
}
