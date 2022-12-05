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
	stacks[1] = "HRPQTNGB";
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
		// printf("instructions[%d] = [%d]\n", n - 1, instructions[n - 1]);
		while (ft_isdigit(*line))
			line++;
	}
	instructions[n] = 0;
	printf("instructions = {%d,%d,%d}\n", instructions[0], instructions[1], instructions[2]);
	return (instructions);
}

char **follow_instructions(char **stacks, int *instructions)
{
	int reps;
	int from;
	int to;
	int stack_size;
	char crate;
	
	reps = instructions[0];
	from = instructions[1] - 1;
	to = instructions[2] - 1;

	printf("reps = %d	stacks[from] 	= '%s'\n", reps, stacks[from]);
	printf("reps = %d	stacks[to] 	= '%s'\n", reps, stacks[to]);
	while (reps-- > 0)
	{
		stack_size = ft_strlen(stacks[from]) - 1;
		crate = stacks[from][stack_size];
		printf("crate = %c\n", crate);
		stacks[from] = ft_substr(stacks[from], 0, stack_size);
		stacks[to] = ft_strjoin(stacks[to], &crate);
		printf("reps = %d	stacks[from] 	= '%s'\n", reps, stacks[from]);
		printf("reps = %d	stacks[to] 	= '%s'\n", reps, stacks[to]);
	}
	return (stacks);
}

// char *get_top_of_stacks(char **stacks)
// {
// 	char *top_of_stacks;

// 	return (top_of_stacks);
// }

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
	int i = 0;
	while ((line = get_next_line(fd)) != NULL && i++ < 20)
	{
		printf("\nTASK [ %d ]-------------------------------------------\n", i);
		instructions = get_instructions(line);
		stacks = follow_instructions(stacks, instructions);
		j = 0;
		while (j++ < 9)
			printf("stack[%d] = '%s'\n", j, stacks[j - 1]);
	}
	//line = get_top_of_stacks(stacks);
	close(fd);
	return (0);
}