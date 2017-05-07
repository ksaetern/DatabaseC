/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 04:51:04 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/04 04:51:09 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void		ft_destroyfinal(char *str)
{
	char	*line;
	char	filepath[100];
	int		rem;

	sprintf(filepath, "./Database/%s", str);
	printf("[Are you sure you want to %sDestroy%s:%s%s%s]?\n",
		RED, RESET, MAGENTA, str, RESET);
	printf("%s[%40s]\n%s[%40s]\n", RED, "yes", GREEN, "no");
	ft_get_next_line(0, &line);
	if (strcmp(line, "yes") == 0)
	{
		rem = remove(filepath);
		if (rem == 0)
		{
			list_dir("./Database/");
			printf("\n%s[%40s]\n\n", RED, "Database destroyed successfully");
		}
		else
			printf("\n%s[%40s]\n", RED,
			"Error: unable to destroy the Database");
	}
	free(line);
	ft_mainmenu();
}

void		ft_destroy(void)
{
	char	*line;

	line = NULL;
	list_dir("./Database/");
	printf("\nPlease choose database [%sname%s] or [exit]\n",
		MAGENTA, RESET);
	ft_get_next_line(0, &line);
	if (strcmp(line, "exit") == 0)
	{
		free(line);
		line = NULL;
		ft_exit();
	}
	ft_destroyfinal(line);
}
