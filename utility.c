/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 17:31:31 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/04 17:31:32 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void 		list_dir(const char *path)
{
	struct dirent 	*entry;

	DIR *dir = opendir(path);
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

void	ft_error(void)
{
	printf("%s%40s\n", RED, "User Error");
	exit (0);
}

void	ft_exit(void)
{
	printf("[%s%40s%s]\n", RED, "Program Exiting", RESET);
	printf("[%s%40s%s]\n", GREEN, "GoodBye", RESET);
	exit(0);
}

t_topic		*ft_newlist(t_topic *newlist)
{
	if (!(newlist->next = (t_topic *)malloc(sizeof(t_topic))))
		return (0);
	newlist = newlist->next;
	return (newlist);
}

void	ft_name(void)
{
	printf("%s            .-') _   _ .-') _ .-. .-')    \n", RED);
	printf("            (  OO) ) ( (  OO) )\\  ( OO )    %s\n", RESET);
	printf("%s   ,------.%s/     '._ \\    .'_ %s;-----.  \n", CYAN, RED, CYAN);
	printf("('-|  .---'|'--...__.,`'--..._.| .-.  |     \n");
	printf("(%sOO%s|  |    '--.  .--'|  |  \\  '| '-' /   \n", RED, CYAN);
	printf("/  |  '--.    |  |   |  |   ' || .-. `.     \n");
	printf("  \\|  |_)     |  |   |  '--'  /| '--'  /   \n");
	printf("   `--'       `--'   `-------' `------'     %s\n", RESET);
}
