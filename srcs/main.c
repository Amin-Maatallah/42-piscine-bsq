/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwillis <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 09:56:38 by lwillis           #+#    #+#             */
/*   Updated: 2024/10/21 19:04:43 by lwillis          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (1 == argc)
		solve_map(mock_map());
	else if (2 == argc)
		solve_map(read_map_file(argv[1]));
	return (argc - argc);
}
