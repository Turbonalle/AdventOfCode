#include "../Includes/aoc.h"
#include <stdlib.h>

/*
You:				Opponent:
X = rock			A = rock
Y = paper			B = paper
Z = scissors		C = scissors

Using Ascii values, we get the following differences:

X - A = 88 - 65 = 23; DRAW	4
X - B = 88 - 66 = 22; LOSE	1
X - C = 88 - 67 = 21; WIN	7

Y - A = 89 - 65 = 24; WIN	8
Y - B = 89 - 66 = 23; DRAW	5
Y - C = 89 - 67 = 22; LOSE	2

Z - A = 90 - 65 = 25; LOSE	3
Z - B = 90 - 66 = 24; WIN	9
Z - C = 90 - 67 = 23; DRAW	6
*/

int result(int you, int opponent)
{
	int points;
	int result;

	points = 0;
	result = you - opponent;
	if (result == 22 || result == 25)
		points = 0;
	else if (result == 23)
		points = 3;
	else if (result == 21 || result == 24)
		points = 6;
	return (points);
}

int rps(char *line)
{
	int points;

	points = 0;
	if (line[2] == 'X')
		points += 1 + result(line[2], line[0]);
	else if (line[2] == 'Y')
		points += 2 + result(line[2], line[0]);
	else if (line[2] == 'Z')
		points += 3 + result(line[2], line[0]);
	return (points);
}

int main()
{
	int fd;
	int points;
	char *line;
	
	fd = open("InputFiles/i2.txt", O_RDONLY);
	if (fd < 3)
		return (1);
	points = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		points += rps(line);
		line = get_next_line(fd);
	}
	printf("final points = %d\n", points);
	return (0);
}