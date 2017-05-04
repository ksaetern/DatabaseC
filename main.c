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

void	ft_error(void)
{
	printf("User error\n");
	exit (0);
}

void	ft_createdirectory(void)
{
	if (mkdir("Database",0777) == 0)
		printf("\nDatabase directory created\n");
	else if (mkdir("Database",0777) == -1)
	{
		printf("\nDatabase directory exits\n");
		list_dir("./Database/");
	}
	ft_create();
}

void	ft_mainmenu(void)
{
	char		c[2];

	printf("Would you like to:\n");
	printf("\n[%40s]\n[%40s]\n[%40s]\n[%40s]\n[%40s]\n\n",
		"Create:(1)", "Add:(2)", "Search:(3)", "Destroy:(4)", "Exit:(5)");
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
		exit(0);
	else
	{
		printf("bro follow directions\n");
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
		printf("Password Confirmed\n");
		ft_mainmenu();
	}
	else
		printf("Back off Witch!\n");
}

int		main(void)
{
	printf("\n[%40s]\n[%40s]\n\n", "Welcome to the FT_Database",
		"Please enter password(hint:welcome42)");
	password_input();
	return (0);
}
