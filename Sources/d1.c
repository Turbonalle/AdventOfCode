#include "../Includes/aoc.h"
#include <stdlib.h>

int *biggest_values(int *cal)
{
	int i;
	int *big;

	big = (int *)malloc(4 * sizeof(int));
	if (!big)
	{
		printf("malloc for big in biggest_values() failed\n");
		return (0);
	}
	i = 0;
	while (i < 3)
		big[i++] = 0;
	i = 0;
	while (cal[i])
	{
		if (cal[i] > big[0])
		{
			big[2] = big[1];
			big[1] = big[0];
			big[0] = cal[i];
		}
		else if (cal[i] > big[1])
		{
			big[2] = big[1];
			big[1] = cal[i];
		}
		else if (cal[i] > big[2])
			big[2] = cal[i];
		i++;
	}
	return (big);
}

int total_power(int fd)
{
	int total;
	char *line;

	line = get_next_line(fd);
	total = 0;
	while (line && line[0] != '\n')
	{
		total += atoi(line);
		line = get_next_line(fd);
	}
	return (total);
}

int search_empty_lines(int fd)
{
	int tomtar;
	char *line;

	tomtar = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line[0] == '\n')
			tomtar++;
		free(line);
	}
	return (tomtar);
}

int main()
{
	int fd1;
	int fd2;
	char *line;
	int elf_amount;
	int *big;
	int *calorie_amount;
	int i;

	fd1 = open("InputFiles/input_d1_e1.txt", O_RDONLY | S_IRUSR);
	fd2 = open("InputFiles/input_d1_e1.txt", O_RDONLY | S_IRUSR);
	i = 0;
	elf_amount = search_empty_lines(fd1);
	calorie_amount = (int *)malloc((elf_amount + 1) * sizeof(int));
	if (!calorie_amount)
	{
		printf("malloc for calorie_amount in main() failed\n");
		return (0);
	}
	calorie_amount[elf_amount] = '\0';
	while (i < elf_amount)
	{
		calorie_amount[i] = total_power(fd2);
		i++;
	}
	big = (int *)malloc(4 * sizeof(int));
	if (!big)
	{
		printf("malloc for big in main() failed\n");
		return (0);
	}
	big[3] = 0;
	big = biggest_values(calorie_amount);
	printf("Biggest calorie amount = %d\n", big[0]);
	printf("Second biggest calorie amount = %d\n", big[1]);
	printf("Third biggest calorie amount = %d\n", big[2]);
	printf("Total calorie amount = %d\n", (big[0] + big[1] + big[2]));
	close(fd1);
	close(fd2);
	return (0);
}