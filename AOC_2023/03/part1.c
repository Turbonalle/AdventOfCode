#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int find_num(char *line, int *i)
{
	while (line[*i])
	{
		if (strchr("0123456789", line[*i]))
			return (*i);
		(*i)++;
	}
	return (-1);
}

int part(char **grid, int row, int col)
{
	int num = 0;
	int len = 0;
	int x, y, x_end;
	x = col;
	while(strchr("0123456789", grid[row][x]))
	{
		num = num * 10 + grid[row][x] - '0';
		x++;
		len++;
	}
	if (row > 0)
	{
		x = (col > 0) ? col - 2 : col - 1;
		x_end = (grid[row][col + len] != '\n' && grid[row][col + len] != '\0') ? col + len + 1 : col + len;
		while (++x < x_end)
			if (!strchr("0123456789.", grid[row][x]) || !strchr("0123456789.", grid[row - 1][x]))
				return (num);
	}
	if (grid[row + 1] != NULL)
	{
		x = (col > 0) ? col - 2 : col - 1;
		x_end = (grid[row][col + len] != '\n' && grid[row][col + len] != '\0') ? col + len + 1 : col + len;
		while (++x < x_end)
			if (!strchr("0123456789.", grid[row][x]) || !strchr("0123456789.", grid[row + 1][x]))
				return (num);
	}
	return (0);
}

int main(void)
{
	int fd = open("input.txt", O_RDONLY);
	char buf[1024];
	int lines = 1;
	while (read(fd, buf, 1) > 0)
		if (buf[0] == '\n')
			lines++;
	char *grid[lines + 1];
	grid[lines] = NULL;
	close(fd);
	FILE *file = fopen("input.txt", "r");
	int i = -1;
	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		grid[++i] = malloc(sizeof(char) * (strlen(buf) + 1));
		strncpy(grid[i], buf, strlen(buf));
	}
	int sum = 0;
	i = -1;
	while (grid[++i])
	{
		int j = 0;
		while (grid[i][j] && find_num(grid[i], &j) != -1)
		{
			sum += part(grid, i, j);
			while (strchr("0123456789", grid[i][j++])) {}
		}
	}
	printf("sum = %d\n", sum);
	return (0);
}