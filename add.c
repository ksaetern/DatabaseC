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
		printf("\n[%40s]\n", "Database name error");
		ft_add();
	}
	fscanf(fp, "%c %s", create.str, create.addline);
	topics = atoi(create.str);
	if (topics == 0)
	{
		printf("\n[%40s]\n\n", "Format [error] choose another file");
		ft_add();
	}
	printf("[Number of topics:%23d]\n", topics);
	tmp = ft_strsplit(create.addline, ',');
	ft_adddata(fp, topics, tmp, str);
}

void 		list_dir(const char *path)
{
    struct dirent 	*entry;

    DIR *dir = opendir(path);
    if (dir == NULL)
    {
    	printf("\n[%40s]\n\n", "Database doesn't exist please go to Create");
        ft_mainmenu();
    }
    printf("\nExisting Database:\n");
    while ((entry = readdir(dir)) != NULL)
    {
    	if (!strcmp(entry->d_name, ".") || !strcmp(entry->d_name, ".."))
    		;
    	else
    		printf("[%40s]\n",entry->d_name);
    }
    closedir(dir);
}

void 				ft_add(void)
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
	ft_openapend(line);
}