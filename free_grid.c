/**
 * free_grid - frees a 2 dimensional grid
 * @grid: 2 dimensional grid
 *
 * Return: void
 */
void free_grid(char **grid)
{
	int i = 0;

	while (grid[i])
	{
		free(grid[i]);
		i++;
	}
	free(grid);
}
