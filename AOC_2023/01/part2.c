#include <stdio.h>
#include <string.h>

int find_num(char **nums, char *line)
{
	int i = -1;
	while (nums[++i] && line)
		if (strncmp(nums[i], line, strlen(nums[i])) == 0)
			return (i % 10);
	return (-1);
}

int main(void)
{
	FILE *file = fopen("input.txt", "r");
	char buf[1024];
	char *nums[21] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "0", "1", "2", "3", "4", "5", "6", "7", "8", "9", NULL };
	int sum = 0;
	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		int i = -1;
		while (find_num(nums, &buf[++i]) == -1) {}
		int first = find_num(nums, &buf[i]);
		i = strlen(buf) - 1;
		while (find_num(nums, &buf[--i]) == -1 && i >= 0) {}
		int last = find_num(nums, &buf[i]);
		sum += first * 10 + last;
	}
	printf("sum = %d\n", sum);
	fclose(file);
	return (0);
}