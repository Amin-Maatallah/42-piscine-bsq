#include <unistd.h>
#include "bsq.h"

void	print_grid(char **grid, int rows, int cols)
{
	int	i;
	int	j;

	i = -1;
	while (++i < rows)
	{
		j = -1;
		while (++j < cols)
			write(1, &grid[i][j], 1);
		write(1, "\n", 1);
	}
}