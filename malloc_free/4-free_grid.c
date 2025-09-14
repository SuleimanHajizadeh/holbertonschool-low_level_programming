#include <stdlib.h>
#include "main.h"

/**
 * free_grid - frees a 2 dimensional grid previously created
 * @grid: pointer to the 2D grid
 * @height: height of the grid
 *
 * Return: Nothing
 */
void free_grid(int **grid, int height)
{
	int i;

	if (grid == NULL)
		return;

	for (i = 0; i < height; i++)
		free(grid[i]);

	free(grid);
}
