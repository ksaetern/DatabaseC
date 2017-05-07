/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 07:32:37 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/04 07:32:41 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void		ft_searchmenu(char *choose, t_ftdb *create, char ***entry, int line)
{
	if (strcmp(choose, "modify") == 0)
		ft_modify(line, create, entry);
	if (strcmp(choose, "topics") == 0)
		ft_printtopic(entry, create);
	if (strcmp(choose, "menu") == 0)
		ft_mainmenu();
	if (strcmp(choose, "exit") == 0)
		ft_exit();
	else
		ft_error();
}

t_ftdb		*ft_grabinfo(t_ftdb *create, int fd)
{
	int		data;

	data = 0;
	if (ft_get_next_line(fd, &create->line))
		create->topics = atoi(create->line);
	free(create->line);
	if (create->topics == 0)
	{
		printf("\n[%40s]\n\n", "Format [error] choose another file");
		ft_search();
	}
	if (ft_get_next_line(fd, &create->line))
	{
		create->modtopics = ft_strdup(create->line);
		create->topicnames = ft_strsplit(create->line, ',');
	}
	while (ft_get_next_line(fd, &create->line))
	{
		data++;
		free(create->line);
	}
	create->dataentry = data;
	create->line = NULL;
	close(fd);
	return (create);
}

void		ft_parsetopics(char *str)
{
	char	filepath[100];
	int		i;
	FILE	*fp;
	t_ftdb	*create;

	i = 0;
	create = (t_ftdb *)malloc(sizeof(t_ftdb));
	sprintf(filepath, "./Database/%s", str);
	if (!(fp = fopen(filepath, "r+")))
	{
		printf("\n[%40s]\n", "Database name error");
		ft_search();
	}
	create = ft_grabinfo(create, fileno(fp));
	create->databasename = str;
	printf("\n%s[Datasebase info:%24s]\n", YELLOW, create->databasename);
	printf("%s[Number of topics:%23d]\n", CYAN, create->topics);
	printf("%s[Number of data entry:%19d]%s\n\n",
		GREEN, create->dataentry, RESET);
	fp = fopen(filepath, "r+");
	ft_makesinfo(create, fileno(fp), i);
}

void		ft_search(void)
{
	char	*line;

	line = NULL;
	list_dir("./Database/");
	printf("\nPlease choose database [name] or [exit]%s\n", MAGENTA);
	ft_get_next_line(0, &line);
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		line = NULL;
		exit(0);
	}
	ft_parsetopics(line);
}
