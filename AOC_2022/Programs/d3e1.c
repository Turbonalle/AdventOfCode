#include "../Includes/aoc.h"
#include <stdlib.h>
#include <string.h>

int find_priority(char *line)
{
	int len;
	int value;
	char *first_half;

	len = ft_strlen(line) / 2;
	first_half = ft_substr(line, 0, len);
	while (line[len] && strchr(first_half, line[len]) == NULL)
		len++;
	if ('a' <= line[len] && line[len] <= 'z')
		value = line[len] - 96;
	else
		value = line[len] - 38;
	return (value);
}

int main()
{
	int fd;
	int priority_sum;
	char *line;

	fd = open("InputFiles/i3.txt", O_RDONLY);
	priority_sum = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		priority_sum += find_priority(line);
		free(line);
	}
	close(fd);
	printf("priority_sum = %d\n", priority_sum);
	return (0);
}