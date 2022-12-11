int operation(int worry_level, int monkey)
{
	if (monkey == 0)
		worry_level *= 11;
	else if (monkey == 1)
		worry_level *= worry_level;
	else if (monkey == 2)
		worry_level += 1;
	else if (monkey == 3)
		worry_level += 2;
	else if (monkey == 4)
		worry_level *= 13;
	else if (monkey == 5)
		worry_level += 5;
	else if (monkey == 6)
		worry_level += 6;
	else if (monkey == 7)
		worry_level += 7;
	return (worry_level);
}

int test(int worry_level, int monkey)
{
	if (monkey == 0)
	{
		if (worry_level % 2 == 0)
			return (4);
		else
			return (7);
	}
	else if (monkey == 1)
	{
		if (worry_level % 7 == 0)
			return (3);
		else
			return (6);
	}
	else if (monkey == 2)
	{
		if (worry_level % 13 == 0)
			return (4);
		else
			return (8);
	}
	else if (monkey == 3)
	{
		if (worry_level % 3 == 0)
			return (6);
		else
			return (5);
	}
	else if (monkey == 4)
	{
		if (worry_level % 19 == 0)
			return (1);
		else
			return (7);
	}
	else if (monkey == 5)
	{
		if (worry_level % 17 == 0)
			return (2);
		else
			return (0);
	}
	else if (monkey == 6)
	{
		if (worry_level % 11 == 0)
			return (2);
		else
			return (5);
	}
	else if (monkey == 7)
	{
		if (worry_level % 5 == 0)
			return (1);
		else
			return (3);
	}
}

int *set_inspect(int *inspect)
{
	int i;

	i = 8;
	inspect = malloc((i + 1) * sizeof(int));
	if (!inspect)
	{
		printf("Malloc of 'inspect' failed!\n");
		return (0);
	}
	inspect[i] = 0;
	while (i-- > 0)
		inspect[i] = 0;
	return (inspect);
}

int **set_items(int **items)
{
	items = malloc(9 * sizeof(int *));
	if (!items)
	{
		printf("Malloc of 'items' failed!\n");
		return (0);
	}
	items[0] = {84,66,62,69,88,91,91};
	items[1] = {98,50,76,99};
	items[2] = {72,56,94};
	items[3] = {55,88,90,77,60,67};
	items[4] = {69,72,63,60,72,52,63,78};
	items[5] = {89,73};
	items[6] = {78,68,98,88,66};
	items[7] = {70};
	items[8] = 0;
	return (items);
}

int *recieve(int **items, int monkey, int current_item, int recieving_monkey)
{
	int *new;
	int len;
	int i;

	len = 0;
	while (items[recieving_monkey][len])
		len++;
	new = malloc((len + 2) * sizeof(int));
	new[len + 1] = 0;
	new[len] = items[monkey][current_item];
	i = 0;
	while (items[monkey][i])
	{
		new[i] = items[monkey][i];
		i++;
	}
	items[monkey] = new;
	free(items[monkey]);
	return (new);
}

int *throw(int **items, int monkey)
{
	int *new;
	int len;

	len = 0;
	while (items[monkey][len])
		len++;
	if (len == 0)
		return (0);
	new = malloc(len * sizeof(int));
	new[len - 1] = 0;
	len = 0;
	while (items[monkey][len + 1])
	{
		new[len] = items[monkey][len + 1];
		len++;
	}
	items[monkey] = new;
	free(items[monkey]);
	return (new);
}

int **item_inspection(int **items, int *inspect, int monkey)
{
	int	i;
	int	recieving_monkey;

	i = 0;
	while (items[monkey][i])
	{
		items[monkey][i] /= 3;
		items[monkey][i] = operation(items[monkey][i], monkey);
		recieving_monkey = test(items[monkey][i], monkey);
		items[recieving_monkey] = recieve(items, monkey, i, recieving_monkey);
		items[monkey] = throw(items, monkey);
		i++;
	}
	inspect[monkey] += i;
	return (items);
}

int count_monkey_business(int *inspect)
{
	int monkey_business;
	int most_inspections;
	int second_most_inspections;
	int i;

	i = 0;
	while (inspect[i])
	{
		if (inspect[i] > most_inspections)
		{
			second_most_inspections = most_inspections;
			most_inspections = inspect[i];
		}
		else if (inspect[i] <= most_inspections && inspect[i] > second_most_inspections)
			second_most_inspections = inspect[i];
		i++;
	}
	monkey_business = most_inspections * second_most_inspections;
	return (monkey_business);
}

check_monkey_business(int **items, int rounds)
{
	int *inspect;
	int monkey;
	int monkey_business;

	inspect = set_inspect(inspect);
	while (rounds > 0)
	{
		monkey = 0;
		while (monkey < 8)
		{
			items = item_inspection(items, inspect, monkey);
			monkey++;
		}
		rounds--;
	}
	monkey_business = count_monkey_business(inspect);
	printf("%d\n", monkey_business);
}

int main()
{
	int **items;

	items = set_items(items);
	check_monkey_business(items, 20);
	return (0);
}