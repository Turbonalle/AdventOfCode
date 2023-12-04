#include "../Includes/aoc.h"
#include <stdlib.h>

/*
Opponent:			Condition:
A = rock			X = lose
B = paper			Y = draw
C = scissors		Z = win

A X = rock 		scissors	= 3 + 0 = 3		23
A Y = rock 		rock 		= 1 + 3 = 4		24
A Z = rock 		paper	 	= 2 + 6 = 8		25

B X = paper 	rock 		= 1 + 0 = 1		22
B Y = paper 	paper 		= 2 + 3 = 5		23
B Z = paper 	scissors	= 3 + 6 = 9		24

C X = scissors 	paper 		= 2 + 0 = 2		21
C Y = scissors 	scissors	= 3 + 3 = 6		22
C Z = scissors 	rock 		= 1 + 6 = 7		23

Formula for winning, getting a draw or losing:
	(Condition - 88) * 3;

Formula for calculating your choice:
	((Condition + 2) % 3 + Opponent % 3) % 3 + 1;
*/

int main()
{
	int fd = open("InputFiles/i2.txt", O_RDONLY);
	int points = 0;
	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		points += (line[2] - 88) * 3 + ((line[2] + 2) % 3 + line[0] % 3) % 3 + 1;
		free(line);
	}
	printf("final points = %d\n", points);
	return (0);
}