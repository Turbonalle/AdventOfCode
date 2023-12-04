#include "../Includes/aoc.h"
#include <stdio.h>

void skip_lines(int fd)
{
	int i;

	i = 0;
	while (i++ < 10)
		get_next_line(fd);
}

char **get_stacks(char **stacks)
{
	stacks = malloc(10 * sizeof(char *));
	if (!stacks)
	{
		printf("Failed mallocing stacks");
		return (NULL);
	}
	stacks[0] = "DTWFJSHN";
	stacks[1] = "HRPQTNBG";
	stacks[2] = "LQV";
	stacks[3] = "NBSWRQ";
	stacks[4] = "NDFTVMB";
	stacks[5] = "MDBVHTR";
	stacks[6] = "DBQJ";
	stacks[7] = "DNJVRZHQ";
	stacks[8] = "BNHMS";
	return (stacks);
}

int *get_instructions(char *line)
{
	int *instructions;
	int n;

	instructions = malloc(4 * sizeof(int));
	if (!instructions)
	{
		printf("Malloc failed!\n");
		return (0);
	}
	n = 0;
	while (*line != '\0' && *line != '\n')
	{
		while (!ft_isdigit(*line))
			line++;
		instructions[n++] = atoi(line);
		while (ft_isdigit(*line))
			line++;
	}
	instructions[n] = 0;
	return (instructions);
}

char **follow_instructions(char **stacks, int *instructions)
{
	int reps;
	int from;
	int to;
	int stack_size;
	char *crate;
	
	reps = instructions[0];
	from = instructions[1] - 1;
	to = instructions[2] - 1;
	crate = malloc(2 * sizeof(char));
	if (!crate)
	{
		printf("Malloc failed!\n");
		return (0);
	}
	crate[1] = '\0';
	while (reps-- > 0)
	{
		stack_size = ft_strlen(stacks[from]);
		crate[0] = stacks[from][stack_size - 1];
		stacks[from] = ft_substr(stacks[from], 0, stack_size - 1);
		stacks[to] = ft_strjoin(stacks[to], crate);
	}
	return (stacks);
}

char *get_top_of_stacks(char **stacks)
{
	char *top_of_stacks;
	char *top_crate;
	int stack_size;
	int stack;

	top_of_stacks = malloc(10 * sizeof(char));
	if (!top_of_stacks)
	{
		printf("Malloc failed!\n");
		return (0);
	}
	top_of_stacks[9] = '\0';
	top_crate = malloc(2 * sizeof(char));
	if (!top_crate)
	{
		printf("Malloc failed!\n");
		return (0);
	}
	top_crate[1] = '\0';
	stack = 0;
	while (stacks[stack])
	{
		stack_size = ft_strlen(stacks[stack]);
		printf("\nstack_size[%d] = %d", stack + 1, stack_size);
		top_crate[0] = stacks[stack][stack_size - 1];
		top_of_stacks = ft_strjoin(top_of_stacks, top_crate);
		stack++;
	}
	return (top_of_stacks);
}

int main()
{
	char **stacks;
	char *line;
	int *instructions;
	int fd;

	fd = open("InputFiles/i5.txt", O_RDONLY);
	if (fd < 3)
	{
		printf("Error opening file!\n");
		return (0);
	}
	stacks = get_stacks(stacks);
	skip_lines(fd);
	int j;
	int k;
	int i = 11;
	while ((line = get_next_line(fd)) != NULL)
	{
		j = 0;
		k = 0;
		instructions = get_instructions(line);
		stacks = follow_instructions(stacks, instructions);
		if (i < 600)
			printf("\nmove %d = {%d,%d,%d}\n", i, instructions[0], instructions[1], instructions[2]);
		while (stacks[j] && i < 600)
		{
			printf("stacks[%d] = %s\n", j + 1, stacks[j]);
			j++;
		}
		i++;
	}
	line = get_top_of_stacks(stacks);
	printf("\nTop crates = [%s]\n", line);
	close(fd);
	return (0);
}

/*BRTSWNJHH*/