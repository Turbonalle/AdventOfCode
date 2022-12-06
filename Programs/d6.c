#include "../Includes/aoc.h"
#include <stdio.h>

int sequence_check(char *s, int len)
{
	int n;
	int i;

	n = 0;
	while (n < len - 1)
	{
		i = n;
		while (s[++i])
		{
			if (s[i] == s[n])
				return (0);
		}
		n++;
	}
	return (1);
}

int search_sequence(int sequence_size)
{
	char *read_start;
	char *read_char;
	char *sequence;
	int fd;
	int n;

	fd = open("InputFiles/i6.txt", O_RDONLY);
	if (fd < 3)
	{
		printf("Error opening file!\n");
		return (0);
	}

	read_start = malloc((sequence_size + 1) * sizeof(char));
	if (!read_start)
	{
		printf("Failed malloc!\n");
		return (0);
	}

	n = read(fd, read_start, sequence_size);
	read_start[n] = '\0';
	sequence = malloc(1 * sizeof(char));
	if (!sequence)
	{
		printf("Failed malloc!\n");
		return (0);
	}
	sequence[0] = '\0';
	sequence = ft_strjoin(sequence, read_start);
	read_char = malloc(2 * sizeof(char));
	if (!read_char)
	{
		printf("Failed malloc!\n");
		return (0);
	}
	//printf("sequence = '%s'	n = %d\n", sequence, n);

	if (!sequence_check(sequence, sequence_size))
	{
		while (read(fd, read_char, 1) > 0)
		{
			n++;
			read_char[1] = '\0';
			sequence++;
			sequence = ft_strjoin(sequence, read_char);
			//printf("sequence = '%s'	n = %d\n", sequence, n);
			if (sequence_check(sequence, sequence_size))
			{
				printf("Found the marker at position %d\n", n);
				return (n);
			}
		}
		if (sequence_check(sequence, sequence_size))
		{
			printf("Found the marker at position %d\n", n);
			return (n);
		}
	}
	printf("Did not find the marker. Stopped at position %d\n", n);
	return (0);
}

int main()
{
	search_sequence(4);
	search_sequence(14);
	return (0);
}