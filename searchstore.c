/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchstore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:25:50 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/04 18:25:53 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void		ft_printline(int line, t_ftdb *create, char ***entry)
{
	int		i;

	i = 0;
	printf("[Database Name:%s%26s%s]\n%sLine [%d] info:%s\n", YELLOW,
		create->databasename, RESET, MAGENTA, line, RESET);
	while (i < create->topics)
	{
		printf("[Topic:%s%34s%s]\n", CYAN, create->topicnames[i], RESET);
		printf("[Data:%s%35s%s]\n", GREEN, entry[line][i], RESET);
		i++;
	}
	printf("\n%sChoose:%s\n", GREEN, RESET);
	printf("[%s%40s%s]\n[%s%40s%s]\n[%s%40s%s]\n[%s%40s%s]\n",
		GREEN, "modify", RESET, GREEN, "topics",
		RESET, WHITE, "menu", RESET, RED, "exit", RESET);
	ft_get_next_line(0, &create->line);
	ft_searchmenu(create->line, create, entry, line);
}

int			ft_userpicks(t_ftdb *create, char *s1)
{
	int		line;

	printf("\n%sPlease choose Number(#)%s\n", GREEN, RESET);
	ft_get_next_line(0, &create->line);
	line = atoi(create->line);
	if (strcmp(s1, "topics") == 0)
	{
		if (line < create->topics)
			return (line);
	}
	else if (strcmp(s1, "data") == 0)
	{
		if (line < create->dataentry)
			return (line);
	}
	ft_error();
	return (0);
}

void		ft_printtopic(char ***entry, t_ftdb *create)
{
	int		i;
	int		j;
	int		line;

	j = 0;
	i = 0;
	while (j < create->topics)
	{
		printf("[%s%37s(%d)%s]\n", CYAN, create->topicnames[j], j, RESET);
		j++;
	}
	line = ft_userpicks(create, "topics");
	printf("[Database Name:%s%26s%s]\n", YELLOW, create->databasename, RESET);
	printf("[Topic:%s%34s%s]\n%s%s%s\n\n", CYAN,
		create->topicnames[line], RESET, GREEN, "Data for topic:", RESET);
	while (i < create->dataentry)
	{
		printf("[%s%37s(%d)%s]\n", GREEN, entry[i][line], i, RESET);
		i++;
	}
	line = ft_userpicks(create, "data");
	ft_printline(line, create, entry);
}

void		ft_makesinfo(t_ftdb *create, int fd, int k)
{
	char	**topicdata;
	char	***entry;
	int		i;

	i = 0;
	topicdata = NULL;
	entry = (char ***)malloc(sizeof(char **) * (create->dataentry + 1));
	entry[create->dataentry] = NULL;
	while (ft_get_next_line(fd, &create->line) && k < 1)
	{
		k++;
		free(create->line);
	}
	free(create->line);
	while (ft_get_next_line(fd, &create->line))
	{
		topicdata = ft_strsplit(create->line, ',');
		entry[i] = topicdata;
		free(create->line);
		i++;
	}
	close(fd);
	ft_printtopic(entry, create);
}
