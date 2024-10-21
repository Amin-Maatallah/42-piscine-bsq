#include <stdlib.h>
#include "bsq.h"

char	**init_obstacles_grid(char ***obstacles_grid, int rows, int cols)
{
	int	i;
	int	j;

	*obstacles_grid = (char **)malloc(rows * sizeof(char *));
	if (*obstacles_grid == NULL)
		return (NULL);
	i = -1;
	while (++i < rows)
	{
		(*obstacles_grid)[i] = (char *)malloc(cols * sizeof(char));
		if ((*obstacles_grid)[i] == NULL)
			return (NULL);
		j = -1;
		while (++j < cols)
			(*obstacles_grid)[i][j] = '0';
	}
	return (*obstacles_grid);
}

char    **get_obstacles_grid(t_map map)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**obstacles_grid;

	obstacles_grid = init_obstacles_grid(&obstacles_grid, map.rows, map.cols);
	if (obstacles_grid == NULL)
		return (NULL);
	i = -1;
	while (++i < map.rows)
	{
		j = -1;
		while (++j < map.cols)
		{
			if (map.grid[i][j] == map.obstacle)
			{
				k = i - 1;
				while (++k < map.rows)
				{
					l = j - 1;
					while (++l < map.cols)
						++obstacles_grid[k][l];
				}
			}
		}
	}
	return (obstacles_grid);
}