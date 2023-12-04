typedef struct s_file
{
	int				*size;
	struct t_file	*next;
}	t_file;

typedef struct s_dir
{
	struct t_dir	*next_dir;
	struct t_file	*next_file;
	struct t_dir	*next_gen_dir;
	struct t_file	*next_gen_file;
}	t_dir;

int create_list()
{
	t_dir	*base;
	t_dir	*current;
	char	*line;
	int		fd;
	int		check;

	current = base;
	check = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strncmp(line, "cd ..", 5))
		{
			move_up();
			check = 0;
		}
		else if (ft_strncmp(line, "cd ", 3))
		{
			move_down();
			check = 0;
		}
		else if (ft_strncmp(line, "dir ", 4) && check == 0)
		{
			create_dir(line, check);
			check = 1;
		}
		else if (ft_strncmp(line, "dir ", 4) && check == 1)
		{
			create_dir(line, check);
		}
		else if (ft_isdigit(line[0]))
		{
			create_file();
		}
	}
}