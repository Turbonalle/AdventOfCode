#include "../Includes/aoc.h"
#include <stdio.h>

int *split_line(char *line)
{
	int *arr;
	char temp[4]; // Should be dynamically allocated in case of bigger numbers. Works for this task, though.
	int i;
	int j;
	int k;

	arr = malloc(5 * sizeof(int));
	if (!arr)
		return (0);
	j = 0;
	k = 0;
	while (line[j])
	{
		i = 0;
		while (ft_isdigit(line[j]))
			temp[i++] = line[j++];
		temp[i] = '\0';
		arr[k++] = atoi(temp);
		if (line[j] != '\0')
			j++;
	}
	arr[k] = '\0';
	return (arr);
}

int overlap(char *line)
{
	int *arr;

	arr = split_line(line);
	return (!(arr[1] < arr[2] || arr[3] < arr[0]));
}

int full_overlap(char *line)
{
	int *arr;

	arr = split_line(line);
	return ((arr[0] <= arr[2] && arr[3] <= arr[1]) || (arr[2] <= arr[0] && arr[1] <= arr[3]));
}

int main()
{
	char *line;
	int fd;
	int f;
	int o;

	fd = open("InputFiles/i4.txt", O_RDONLY);
	f = 0;
	o = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		f += full_overlap(line);
		o += overlap(line);
	}
	printf("Fully overlapping pairs = %d\n", f);
	printf("Overlapping pairs = %d\n", o);
	close(fd);
	return (0);
}