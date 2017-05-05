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
		printf("[Database Name:%s%26s%s]\n", YELLOW, databasename, RESET);
		printf("[Topic:%s%34s%s]\n[%40s]\n", CYAN, &tmp[j][0], RESET,
		 "Enter data for topic:");
		ft_get_next_line(0, &create.line);
		ft_csvformat(create.addline, create.line, topiccreated, topics);
		j++;
		topiccreated++;
	}
	fprintf(fp, "%s\n",	create.addline);
	printf("%sWould you like to to enter more data?%s\n",
		GREEN, RESET);
	printf("[%40s]\n[%40s]\n", "yes","no");
	scanf("%s", create.name);
	if (strcmp(create.name, YES) == 0)
		ft_adddata(fp, topics, tmp, databasename);
	else
		ft_exit();
}

char	*ft_createnameline(t_ftdb create, int topics, FILE *fp, char *dbname)
{
	int 			topiccreated;
	char			*line;

	line = NULL;
	topiccreated = 1;
	while (topiccreated <= topics)
	{
		printf("\n[Database:%s%31s%s]\n", YELLOW, dbname, RESET);
		printf("Enter [%sName of Topics%s] %d of %d\n",
			CYAN, RESET, topiccreated, topics);
		ft_get_next_line(0, &line);
		printf("Enter type of data:\n[%s%40s%s]\n", GREEN, "string", RESET);
		printf("[(whole numbers)%s%25s%s]\n[(numbers and decimals)%s%18s%s]\n\n",
			GREEN, "int", RESET, GREEN, "float", RESET);
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
		printf("\n%sDatabase Name [exists], Choose another%s\n\n",
			RED, RESET);
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
	printf("\nEnter New %sDatabase Name%s   [30 letter max]:\n\n", MAGENTA, RESET);
	scanf("%s", create.name);
	fp = ft_open(create.name);
	printf("[Database Named:%s%25s%s]\n", YELLOW, create.name, RESET);
	printf("Enter Number of topics: %s1-10%s\n", GREEN, RESET);
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
}
