#include "../Includes/aoc.h"
#include <stdlib.h>

int biggest_value(int *calorie_amount)
{
	int i;
	int biggest;

	i = 0;
	biggest = 0;
	while (calorie_amount[i])
	{
		if (calorie_amount[i] > biggest)
			biggest = calorie_amount[i];
		i++;
	}
	return (biggest);
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
	int *calorie_amount;
	int i;

	fd1 = open("InputFiles/input_d1_e1.txt", O_RDONLY | S_IRUSR);
	fd2 = open("InputFiles/input_d1_e1.txt", O_RDONLY | S_IRUSR);
	i = 0;
	elf_amount = search_empty_lines(fd1);
	calorie_amount = (int *)malloc((elf_amount + 1) * sizeof(int));
	calorie_amount[elf_amount] = '\0';
	while (i < elf_amount)
	{
		calorie_amount[i] = total_power(fd2);
		i++;
	}
	i = biggest_value(calorie_amount);
	printf("Biggest calorie amount = %d\n", i);
	close(fd1);
	close(fd2);
	return (0);
}