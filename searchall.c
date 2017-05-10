/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchall.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/08 21:39:23 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/08 21:39:28 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

int			ft_userpicks3(t_ftdb *create)
{
	int		line;

	ft_get_next_line(0, &create->line);
	if (ft_isdigit(create->line[0]))
	{
		line = atoi(create->line);
		free (create->line);
		if (line < create->dataentry)
			return (line);
	}
	ft_error();
	return (0);
}


void	ft_searchtopic(t_ftdb *create, char ***entry)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	printf("[Database Name:%s%26s%s]\n", YELLOW, create->databasename, RESET);
	printf("[Topic:%s%34s%s]\n\n", CYAN,
		create->topicnames[create->topicchosen], RESET);
	printf("Enter Search words:\n");
	ft_get_next_line(0, &create->line);
	while (i < create->dataentry)
	{
		if (ft_strstr(entry[i][create->topicchosen], create->line))
		{
			count++;
			printf("[%s%37s(%d)%s]\n", GREEN, entry[i][create->topicchosen], i, RESET);
		}
		i++;
	}
	if (count == 0)
	{
		printf("%sSearch failed.%s\n", RED, RESET);
		free (create->line);
		ft_searchword(create, entry);
	}
	free (create->line);
	printf("%sSearch found %d\nPlease choose a (#)%s\n", GREEN, count, RESET);
	count = ft_userpicks3(create);
	ft_printline(count, create, entry);
}

void	ft_searchword(t_ftdb *create, char ***entry)
{
	printf("Search current [topic]\n");
	ft_searchtopic(create, entry);
	/*ft_get_next_line(0, &create->line);
	if (strcmp(create->line, "topic") == 0)
	{
		ft_searchtopic(create, entry);
	}
	else if (strcmp(create->line, "all") == 0)
	{

	}
	else
		ft_searchword(create, entry);
	*/
}
