/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 19:15:00 by ksaetern          #+#    #+#             */
/*   Updated: 2017/04/27 21:13:25 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	ft_createdirectory(void)
{
	if (mkdir("Database",0777) == 0)
		printf("\n%sDatabase directory created%s\n", GREEN, RESET);
	else if (mkdir("Database",0777) == -1)
	{
		printf("\n%sDatabase directory exits%s\n", BLUE, RESET);
		list_dir("./Database/");
	}
	ft_create();
}

void	ft_mainmenu(void)
{
	char		c[2];

	printf("%sWould you like to:\n", WHITE);
	printf("\n%s[%40s]\n[%40s]\n[%40s]\n[%40s]\n[%40s]%s\n\n",
		GREEN, "Create:(1)", "Add:(2)", "Search:(3)",
		 "Destroy:(4)", "Exit:(5)", RESET);
	scanf("%s", c);
	if (strcmp(c, CREATE) == 0)
		ft_createdirectory();
	else if (strcmp(c, ADD) == 0)
		ft_add();
	else if (strcmp(c, SEARCH) == 0)
		ft_search();
	else if (strcmp(c, DESTROY) == 0)
		ft_destroy();
	else if (strcmp(c, EXIT) == 0)
		ft_exit();
	else
	{
		printf("%sBro follow directions\n", RED);
		ft_mainmenu();
	}
}

void	password_input()
{
	char		password[12];
	const char	pass[12] = "welcome42";
	int			i;

	i = 0;
	scanf("%s", password);
	if (strcmp(pass, password) == 0)
	{
		printf("%sPassword Confirmed%s\n", GREEN, RESET);
		ft_mainmenu();
	}
	else
		printf("%sBack off Witch!%s\n", RED, RESET);
}

int		main(void)
{
	ft_name();
	printf("\n%s[%40s]\n%s[%40s]%s\n\n", GREEN, "Welcome to the Database",
		WHITE, "Please enter password(hint:welcome42)", RESET);
	password_input();
	return (0);
}
