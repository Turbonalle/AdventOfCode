#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void)
{
	FILE *file = fopen("input.txt", "r");
	char buf[1024];
	char *num;
	int sum = 0;
	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		char *res = malloc(sizeof(char) * 3);
		int i = -1;
		while (strchr("0123456789", buf[++i]) == NULL) {}
		res[0] = buf[i];
		i = strlen(buf);
		while (strrchr("0123456789", buf[--i]) == NULL && i >= 0) {}
		res[1] = buf[i];
		res[2] = '\0';
		sum += atoi(res);
		free(res);
	}
	printf("sum = %d\n", sum);
	fclose(file);
	return (0);
}