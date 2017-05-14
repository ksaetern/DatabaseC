/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:06:24 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/03 19:06:27 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void		ft_addmenu(FILE *fp, int topics, char **tmp, char *databasename)
{
	char	*choose;

	ft_get_next_line(0, &choose);
	if (strcmp(choose, "yes") == 0)
		ft_adddata(fp, topics, tmp, databasename);
	if (strcmp(choose, "menu") == 0)
	{
		fclose(fp);
		ft_mainmenu();
	}
	if (strcmp(choose, "exit") == 0)
	{
		fclose(fp);
		ft_exit();
	}
	else
		ft_error();
}

void		ft_adddata(FILE *fp, int topics, char **tmp, char *databasename)
{
	int		topiccreated;
	int		j;
	t_ftdb	create;

	j = 0;
	topiccreated = 1;
	ft_bzero(create.addline, 1000);
	while (topiccreated <= topics)
	{
		printf("[Database Name:%s%26s%s]\n", YELLOW, databasename, RESET);
		printf("[Topic:%s%34s%s]\n[%40s]\n", CYAN, &tmp[j][0], RESET,
			"Enter data for topic:");
		ft_get_next_line(0, &create.line);
		if (strchr(create.line, ','))
			ft_forbidadd(fp, topics, tmp, databasename);
		ft_csvformat(create.addline, create.line, topiccreated, topics);
		j++;
		topiccreated++;
	}
	fprintf(fp, "%s\n", create.addline);
	printf("%sWould you like to to enter more data?%s\n",
		GREEN, RESET);
	printf("[%s%40s%s]\n[%s%40s%s]\n[%s%40s%s]\n", GREEN, "yes",
		RESET, WHITE, "menu", RESET, RED, "exit", RESET);
	ft_addmenu(fp, topics, tmp, databasename);
}

void		ft_openapend(char *str)
{
	char	filepath[100];
	int		topics;
	FILE	*fp;
	char	**tmp;
	t_ftdb	create;

	sprintf(filepath, "./Database/%s", str);
	if (!(fp = fopen(filepath, "r+")))
	{
		printf("\n%s[%40s]\n", RED, "Database name error");
		ft_add();
	}
	fscanf(fp, "%s %s", create.str, create.addline);
	topics = atoi(create.str);
	if (topics == 0)
	{
		printf("\n%s[%40s]\n\n",
		RED, "Format [error] choose another file");
		ft_add();
	}
	printf("[Number of topics:%s%23d%s]\n", CYAN, topics, RESET);
	tmp = ft_strsplit(create.addline, ',');
	ft_adddata(fp, topics, tmp, str);
}

void		ft_add(void)
{
	char	*line;

	line = NULL;
	list_dir("./Database/");
	printf("\n%sPlease choose database    [name] or [%sexit%s]%s\n",
		GREEN, RED, GREEN, RESET);
	ft_get_next_line(0, &line);
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		line = NULL;
		ft_exit();
	}
	ft_openapend(line);
}
