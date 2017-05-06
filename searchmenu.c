/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchmenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:32:31 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/05 01:32:38 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	ft_searchmenu2(char *choose, t_ftdb *create, char ***entry)
{
	if (strcmp(choose, "topics") == 0)
		ft_printtopic(entry, create);
	if (strcmp(choose, "menu") == 0)
		ft_mainmenu();
	if (strcmp(choose, "exit") == 0)
		ft_exit();
	else
		ft_error();
}

void	ft_searcherror(t_topic *dbhead)
{
	t_ftdb		create;

	printf("%s%s\n%s[%s%40s%s]\n[%s%40s%s]\n", RED, "Topic not found",
		RESET, RED, "exit", RESET, GREEN, "search", RESET);
	ft_get_next_line(0, &create.line);
	if (strcmp(create.line, "exit") == 0)
		ft_exit();
	if (strcmp(create.line, "search") == 0)
		ft_searchmenu(dbhead);
	else
		ft_mainmenu();
}

void	ft_topicinfo(t_topic *database, t_topic *dbhead)
{
	int i;

	i = 0;
	printf("\n%s[Datasebase info:%24s]\n", YELLOW, database->databasename);
	printf("%s[Topic info:%29s]%s\n", CYAN, database->topicname, RESET);
	printf("%sData for topic:%s\n", GREEN, RESET);
	printf("[%40s]\n", database->data[i]);
	while (i < database->dataentry)
	{
		printf("[%s%40s%s]\n", GREEN, database->data[i], RESET);
		i++;
	}
	printf("[%40s]\n", database->data[i]);
	printf("\nPlease choose a (%snumber%s)\n", GREEN, RESET);
	ft_exit();
	ft_searcherror(dbhead);
}

void	ft_searchmenu(t_topic *dbhead)
{
	t_topic		*database;
	t_ftdb		create;

	database = dbhead;
	printf("\n%s[Datasebase info:%24s]\n", YELLOW, database->databasename);
	printf("%sTopics:%s\n", CYAN, RESET);
	while (database)
	{
		printf("[%s%40s%s]\n", CYAN, database->topicname, RESET);
		database = database->next;
	}
	database = NULL;
	printf("\n%s[%40s]%s\n\n", GREEN, "Please choose topic", CYAN);
	ft_get_next_line(0, &create.line);
	database = dbhead;
	while (database)
	{
		if (strcmp(database->topicname, create.line) == 0)
			ft_topicinfo(database, dbhead);
		database = database->next;
	}
	ft_searcherror(dbhead);
}