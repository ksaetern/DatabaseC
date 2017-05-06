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

void	ft_forbidc(void)
{
	printf("[%s%40s%s]\n", RED, "Forbidden character found", RESET);
	ft_create();
}

void	ft_forbidadd(FILE *fp, int topics, char **tmp, char *databasename)
{
	printf("[%s%40s%s]\n", RED, "Forbidden character ',' found", RESET);
	ft_adddata(fp, topics, tmp, databasename);
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
	exit (0);
}

char	*ft_newstr(char *str)
{
	char	*split;
	int		i = 0;
	int		k = 0;

	while (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		i++;
	split = (char *)malloc(sizeof(char) * (i + 1));
	while (k < i)
	{
		split[k] = str[k];
		k++;
	}
	split[k] = '\0';
	return (split);
}

t_topic		*ft_newlist(int topicscount, int dataentry)
{
	int 		i;
	t_topic		*dbhead;
	t_topic		*newlist;

	i = 1;
	//printf("struct count = %d\n", topicscount);
	if (!(dbhead = (t_topic *)malloc(sizeof(t_topic))))
		return (0);
	newlist = dbhead;
	printf("dataentry = %d\n", dataentry);
	while (i < topicscount)
	{
		if (!(newlist->data = (char **)malloc(sizeof(char *) * (dataentry + 1))))
			return (0);
		newlist->data[dataentry] = NULL;
		if (!(newlist->next = (t_topic *)malloc(sizeof(t_topic))))
			return (0);
		i++;
		newlist = newlist->next;
	}
	//printf("i = %d\n", i);
	newlist->next = NULL;
	return (dbhead);
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
