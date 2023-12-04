#include "../Includes/aoc.h"
#include <stdlib.h>
#include <string.h>

int count_value(int x)
{
	int value;

	if ('a' <= x && x <= 'z')
		value = x - 96;
	else
		value = x - 38;
	return (value);
}

int find_badge(char *line1, char *line2, char *line3)
{
	int value;
	int i;

	i = 0;
	while (line1[i])
	{
		if (strchr(line2, line1[i]) != NULL)
		{
			if (strchr(line3, line1[i]) != NULL)
				return (line1[i]);
		}
		i++;
	}
	return (0);
}

int main()
{
	int fd;
	int badge;
	int badge_sum;
	char *line1;
	char *line2;
	char *line3;

	fd = open("InputFiles/i3.txt", O_RDONLY);
	badge_sum = 0;
	while ((line1 = get_next_line(fd)) != NULL && (line2 = get_next_line(fd)) != NULL && (line3 = get_next_line(fd)) != NULL)
	{
		badge = find_badge(line1, line2, line3);
		badge_sum += count_value(badge);
		free(line1);
		free(line2);
		free(line3);
	}
	close(fd);
	printf("badge_sum = %d\n", badge_sum);
	return (0);
}