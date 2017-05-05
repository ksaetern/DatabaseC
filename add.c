/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 19:06:24 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/03 19:06:27 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void				ft_openapend(char *str)
{
	char			filepath[100];
	int				topics;
	int				i;
	FILE			*fp;
	char			**tmp;
	t_ftdb			create;
	
	i = 0;
	sprintf(filepath, "./Database/%s", str);
	if(!(fp = fopen (filepath, "r+")))
	{
		printf("\n%s[%40s]\n", RED, "Database name error");
		ft_add();
	}
	fscanf(fp, "%c %s", create.str, create.addline);
	topics = atoi(create.str);
	if (topics == 0)
	{
		printf("\n%s[%40s]\n\n",
		RED, "Format [error] choose another file");
		ft_add();
	}
	printf("[Number of topics:%s%23d%s]\n", CYAN, topics, RESET);
	tmp = ft_strsplit(create.addline, ',');
	ft_adddata(fp, topics, tmp, str);
}

void 				ft_add(void)
{
	char			*line;

	line = NULL;
	list_dir("./Database/");
	printf("\n%sPlease choose database    [name] or [%sexit%s]%s\n",
		GREEN, RED, GREEN, RESET);
	ft_get_next_line(0, &line);
	if(strcmp(line, "exit") == 0)
	{
		free(line);
		line = NULL;
		ft_exit();
	}
	ft_openapend(line);
}