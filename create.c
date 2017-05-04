/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 03:40:59 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/02 03:41:02 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	ft_adddata(FILE *fp, int topics, char **tmp, char *databasename)
{
	int 		topiccreated;
	int 		j;
	t_ftdb		create;

	j = 0;
	topiccreated = 1;
	ft_bzero(create.addline, 1000);
	while (topiccreated <= topics)
	{
		printf("[Database Name:%26s]\n", databasename);
		printf("[Topic:%34s]\n[%40s]\n", &tmp[j][0],
		 "Enter data for topic:");
		ft_get_next_line(0, &create.line);
		ft_csvformat(create.addline, create.line, topiccreated, topics);
		j++;
		topiccreated++;
	}
	fprintf(fp, "%s\n",	create.addline);
	printf("Would you like to to enter another round of data?\n");
	printf("[%40s]\n[%40s]\n", "yes","no");
	scanf("%s", create.name);
	if (strcmp(create.name, YES) == 0)
		ft_adddata(fp, topics, tmp, databasename);
	else
		ft_mainmenu();
}

char	*ft_createnameline(t_ftdb create, int topics, FILE *fp, char *dbname)
{
	int 			topiccreated;
	char			*line;

	line = NULL;
	topiccreated = 1;
	while (topiccreated <= topics)
	{
		printf("\n[Database:%31s]\n", dbname);
		printf("Enter [Name] of topics %d of %d\n", topiccreated, topics);
		ft_get_next_line(0, &line);
		printf("Enter type of data:\n[%40s]\n", "string");
		printf("[(whole numbers)%25s]\n[(numbers and decimals)%18s]\n\n",
			"int", "float");
		scanf("%s", create.data);
		ft_topicnames(create.addline, line);
		ft_datatype(create.addline, create.data, topiccreated, topics);
		topiccreated++;
	}
	fprintf(fp, "%s\n",	create.addline);
	create.topicnames = create.addline;
	return (create.topicnames);
}

FILE	*ft_open(char *str)
{
	char		filename[100];
	FILE		*fp;
	int			size;

	size = 0;	
	sprintf(filename, "./Database/%s", str);
	fp = fopen (filename, "a+");
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	if (size > 0)
	{
		printf("\nDatabase Name [exists], Please choose another\n\n");
		ft_create();
	}
	rewind(fp);
	return (fp);

}

void	ft_create(void)
{
	int			i;
	int			topics;
	FILE		*fp;
	char		**tmp;
	t_ftdb		create;
	
	i = 1;
	printf("\nEnter New Database Name[30 letter max]:\n\n");
	scanf("%s", create.name);
	fp = ft_open(create.name);
	printf("[Database Named:%25s]\n", create.name);
	printf("Enter Number of topics: 1-10\n");
	scanf("%s", create.str);
	fprintf(fp, "%s\n", create.str);
	topics = atoi(create.str);
	if (topics == 0)
		ft_error();
	create.topicnames = ft_createnameline(create, topics, fp, create.name);
	tmp = ft_strsplit(create.topicnames, ',');
	printf("%d topics created\n", topics);
	ft_adddata(fp, topics, tmp, create.name);
	free (tmp);
	tmp = NULL;
	printf("[%40s]\n", "Database Entry Finished");
	exit(0);
}
