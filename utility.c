/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 08:21:49 by ksaetern          #+#    #+#             */
/*   Updated: 2017/01/21 07:02:47 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	list_dir(const char *path)
{
	struct dirent	*entry;
	DIR				*dir;

	dir = opendir(path);
	if (dir == NULL)
	{
		printf("\n%s[%40s]%s\n\n",
			RED, "Database doesn't exist, go to Create(1)", RESET);
		ft_mainmenu();
	}
	printf("\n%sExisting Database:%s\n", GREEN, RESET);
	while ((entry = readdir(dir)) != NULL)
	{
		if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
			;
		else
			printf("[%s%40s%s]\n", MAGENTA, entry->d_name, RESET);
	}
	closedir(dir);
}

void	ft_forbidc(char *line)
{
	if (strchr(line, ','))
	{
		printf("[%s%40s%s]\n", RED, "Forbidden character found", RESET);
		ft_create();
	}
}

void	ft_forbidadd(FILE *fp, int topics, char **tmp, char *databasename)
{
	printf("[%s%40s%s]\n", RED, "Forbidden character ',' found", RESET);
	ft_adddata(fp, topics, tmp, databasename);
}

void	ft_error(void)
{
	printf("%s%40s\n", RED, "User Error");
	ft_mainmenu();
}

void	ft_exit(void)
{
	printf("[%s%40s%s]\n", RED, "Program Exiting", RESET);
	printf("[%s%40s%s]\n", GREEN, "GoodBye", RESET);
	exit(0);
}
