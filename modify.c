/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 23:03:54 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/05 23:03:57 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

FILE			*ft_mopen(char *str)
{
	FILE		*fp;
	char		filename[100];

	sprintf(filename, "./Database/%s", str);
	fp = fopen(filename, "w+");
	return (fp);
}

void			ft_makenewlist(int line, t_ftdb *create, char ***entry)
{
	FILE		*fp;
	int			j;
	int			i;
	int			Flagok;

	Flagok = 0;
	i = 0;
	fp = ft_mopen(create->databasename);
	fprintf(fp, "%d\n", (create->topics));
	fprintf(fp, "%s\n", (create->modtopics));
	while (i < create->dataentry)
	{
		j = 0;
		ft_bzero(create->addline, 1000);
		while (j < create->topics)
		{
			if (strcmp(entry[i][j], REMOVE) != 0)
			{
				ft_csvformat(create->addline, entry[i][j], j, create->topics);
				Flagok = 1;
			}
			j++;
		}
		if (Flagok == 1)
			fprintf(fp, "%s\n", create->addline);
		Flagok = 0;
		i++;
	}
	fclose(fp);
	printf("[Database Name:%s%26s%s]\n\n",
		YELLOW, create->databasename, RESET);
	printf("%sModify complete for line [%d]%s\n", MAGENTA, line, RESET);
	ft_search();
}

void			ft_forbidm(int line, t_ftdb *create, char ***entry)
{
	printf("[%s%40s%s]\n", RED, "Forbidden character ',' found", RESET);
	ft_modify(line, create, entry);
}

void			ft_remove(int line, t_ftdb *create, char ***entry)
{
	int			i;

	i = 0;
	printf("in remove\n");
	while (i < create->topics)
	{
		entry[line][i] = strdup(REMOVE);
		i++;
	}
	ft_makenewlist(line, create, entry);
}

void			ft_modify(int line, t_ftdb *create, char ***entry)
{
	int			i;

	i = 0;
	printf("[Database Name:%s%26s%s]\n\n",
		YELLOW, create->databasename, RESET);
	while (i < create->topics)
	{
		printf("[Topic:%s%34s%s]\n", CYAN, create->topicnames[i], RESET);
		printf("%sEnter modify for line [%d] or      [%sremove%s]%s\n",
			MAGENTA, line, RED, MAGENTA, RESET);
		ft_get_next_line(0, &create->line);
		if (strchr(create->line, ','))
			ft_forbidm(line, create, entry);
		else if (strcmp(create->line, "remove") == 0)
			ft_remove(line, create, entry);
		else
			entry[line][i] = strdup(create->line);
		printf("Data change %s%s%s:\n[%s%40s%s]\n\n",
			CYAN, create->topicnames[i], RESET,
			GREEN, entry[line][i], RESET);
		i++;
	}
	ft_makenewlist(line, create, entry);
}
