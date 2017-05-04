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

void	ft_destroyfinal(char *str)
{
	char			*line;
	char			filepath[100];
	int				rem;

	sprintf(filepath, "./Database/%s", str);
	printf("%s[%s]?\n", "Are you sure you want to destroy:", str);
	printf("[%40s]\n[%40s]\n", "yes", "no");
	ft_get_next_line(0, &line);

	if(strcmp(line, "yes") == 0)
	{
		rem = remove(filepath);
		if(rem == 0) 
		{
			list_dir("./Database/");
			printf("\n[%40s]\n\n", "Database destroyed successfully");
		}
		else 
			printf("\n[%40s]\n", "Error: unable to destroy the Database");
	}
	ft_mainmenu();
}

void	ft_destroy(void)
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
	ft_destroyfinal(line);
}
