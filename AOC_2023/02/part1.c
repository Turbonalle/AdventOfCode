#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int valid_game(char *line)
{
	char *token = strtok(line, " ");
	int n = 0;
	while (token != NULL)
	{
		if (n)
			if ((n > 12 && !strncmp("red", token, 3)) || (n > 13 && !strncmp("green", token, 5)) || (n > 14 && !strncmp("blue", token, 4)))
				return (0);
		if (strchr("0123456789", token[strlen(token) - 1]))
			n = atoi(token);
		token = strtok(NULL, " ");
	}
	return (1);
}

int main(void)
{
	FILE *file = fopen("input.txt", "r");
	char buf[1024];
	int sum = 0;
	int i = 1;
	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		if (valid_game(buf))
			sum += i;
		i++;
	}
	printf("sum = %d\n", sum);
	fclose(file);
	return (0);
}