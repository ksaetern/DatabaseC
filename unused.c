/*
void clearScreen()
{
  const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
  write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
}
 currently find someone seg faults.
its how im storing the split(reading line from file) into saved name */
void	find_someone(void)
{
	int 	fd;
	char 	*line;
	char	**split;
	char	***savedname;
	int 	i;
	int 	x;
	int 	y;
	int 	j;
	int  	k;
	int 	lines;

	lines = 0;
	savedname = NULL;
	split = NULL;
	//name = NULL;
	k = 0;
	j = 0;
	x = 0;
	i = 0;
	fd = open("saved.txt", O_RDONLY);
	while (ft_get_next_line(fd, &line) == 1)
		lines += 1;
	printf("lines = %d\n", lines);
	close(fd);
	savedname = (char ***)malloc(sizeof(char **) * (lines + 1));
	savedname[lines] = NULL;
	fd = open("saved.txt", O_RDONLY);
	while (ft_get_next_line(fd, &line) == 1)
	{
		while (savedname[k])
		{
			savedname[k][x] = *(char **)malloc(sizeof(char *) * 3);
			while (savedname[k][x])
			{
				split = ft_strsplit(line, ' ');
				y = 0;
				printf("split = %s\n", &split[0][0]);
				while (x < 2)
				{
					savedname[k][x][y] = *(char*)malloc(sizeof(char) * ft_strlen(&split[x][0]));
					savedname[k][x][y] = *strdup(&split[x][0]);
					x++;
				}
			}
			savedname[k][x] = NULL;
		}
		k++;
		free (split);
		free (line);
	}
}

void	ft_numberoflist(t_topic *dbhead)
{
	int 		i;
	t_topic		*newlist;

	i = 0;
	newlist = dbhead;
	while(newlist)
	{
		i++;
		newlist = newlist->next;
	}
	printf("[lists made 	= %d]\n", i);
}

void	add_someone(void)
{
	FILE 	*fp;
	char	fname[30];
	char	lname[30];
	char	*name;
	char	food[30];
	int 	i;

	name = NULL;
	i = 0;
	printf("Enter firstname:(all lowecase please)\n");
	scanf("%s", fname);
	printf("Enter lastname:(all lowecase please)\n");
	scanf("%s", lname);
	name = ft_strjoin(fname,lname);
	printf("Now what is their favorite food?\n");
	scanf("%s", food);
	printf("Storing info\n");
	fp = fopen ("saved.txt", "a");
	fprintf(fp, "%s %s", name, food);
	printf("Text file made\n");
	printf("%s favorite food is %s\n", name, food);
	free(name);
	name = NULL;
}

void	ft_printdata(char **str, int line, int i)
{
	printf("[%s%37s(%d)%s]\n", GREEN, str[line], i, RESET);
	ft_printdata(entry[i], line, i);

from ft_create
	while (i <= elements)
	{
		printf("Enter name of elements %d of %d\n", i, elements);
		scanf("%s", create.name);
		printf("Enter type of data: int(whole numbers), float, string\n");
		scanf("%s", create.data);
		ft_elementnames(create.addline, create.name, elements);
		ft_datatype(create.addline, create.data);
		i++;
	}
	fprintf(fp, "%s\n",	create.addline);