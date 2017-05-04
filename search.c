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

t_topic		*ft_newlist(t_topic *newlist)
{
	if (!(newlist->next = (t_topic *)malloc(sizeof(t_topic))))
		return (0);
	newlist = newlist->next;
	return (newlist);
}

void	ft_printstruct(t_topic *dbhead)
{
	t_topic		*database;
	int			i;

	i = 0;
	database = dbhead;
	printf("topicname%s\ndata%s\n", database->topicname, database->data[i]);
	exit (0);
}

void	ft_makestruct(char **topicnames, int topics, FILE *fp, int i)
{
	t_ftdb		create;
	t_topic		*dbhead;
	t_topic		*database;
	char		**topicdata;
	int			j;
	int			k;

	k = 0;
	printf("checking topicnames: %s\n", &topicnames[0][0]);
	dbhead = (t_topic *)malloc(sizeof(t_topic));
	database = dbhead;
	rewind(fp);
	while (ft_get_next_line(fileno(fp), &create.line) && k < 2)
		k++;
	while (ft_get_next_line(fileno(fp), &create.line))
	{
		printf("line to be created: %s\n", create.line);
		topicdata = ft_strsplit(create.line, ',');
		j = 0;
		while (j < topics)
		{
			printf("checking topicnames: %s\n", &topicdata[j][0]);
			//database->data[i] = strdup(&topicdata[j][0]);
			//database->topicname = strdup(topicnames[i]);
			j++;
			database = ft_newlist(database);
		}
		i++;
	}
	database->next = NULL;
	ft_printstruct(dbhead);
}

void	ft_parsetopics(char *str)
{
	char			filepath[100];
	int				topics;
	int				i;
	FILE			*fp;
	char			**topicnames;
	t_ftdb			create;
	
	i = 0;
	sprintf(filepath, "./Database/%s", str);
	if(!(fp = fopen (filepath, "r+")))
	{
		printf("\n[%40s]\n", "Database name error");
		ft_search();
	}
	fscanf(fp, "%c %s", create.str, create.addline);
	topics = atoi(create.str);
	if (topics == 0)
	{
		printf("\n[%40s]\n\n", "Format [error] choose another file");
		ft_search();
	}
	printf("[Number of topics:%23d]\n", topics);
	printf("topics = %s\n", create.addline);
	topicnames = ft_strsplit(create.addline, ',');
	ft_makestruct(topicnames, topics, fp, i);
}

void	ft_search(void)
{
	char			*line;

	line = NULL;
	list_dir("./Database/");
	printf("\nPlease choose database [name] or [exit]\n");
	ft_get_next_line(0, &line);
	if(strcmp(line, "exit") == 0)
	{
		free(line);
		line = NULL;
		exit (0);
	}
	ft_parsetopics(line);
}
