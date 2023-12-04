#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int get_fewest(char *line, char *color)
{
	char copy[1024];
	strcpy(copy, line);
	char *token = strtok(copy, " ");
	int n = 0;
	int fewest = 0;
	while (token != NULL)
	{
		if (n)
			if (!strncmp(token, color, strlen(color)) && n > fewest)
				fewest = n;
		if (strchr("0123456789", token[strlen(token) - 1]))
			n = atoi(token);
		token = strtok(NULL, " ");
	}
	return (fewest);
}

int main(void)
{
	FILE *file = fopen("input.txt", "r");
	char buf[1024];
	int sum = 0;
	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		int r = get_fewest(buf, "red");
		int g = get_fewest(buf, "green");
		int b = get_fewest(buf, "blue");
		sum += r * g * b;
	}
	printf("sum = %d\n", sum);
	fclose(file);
	return (0);
}