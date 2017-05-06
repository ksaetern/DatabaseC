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
	create.topicname = create.addline;
	return (create.topicname);
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

int		ft_createuserpicks(void)
{
	char	*choose;
	int		topics;

	ft_get_next_line(0, &choose);
	if (strcmp(choose, "exit") == 0)
		ft_exit();
	topics = atoi(choose);
	if (topics == 0 || topics > 100)
		ft_error();
	return (topics);	
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
	printf("Enter Number of topics: %s1-100%s or    [%sexit%s]\n",
		 GREEN, RESET, RED, RESET);
	topics = atoi(create.str);
	topics = ft_createuserpicks();
	fprintf(fp, "%s\n", (ft_itoa(topics)));
	create.topicname = ft_createnameline(create, topics, fp, create.name);
	tmp = ft_strsplit(create.topicname, ',');
	printf("%d topics created\n", topics);
	ft_adddata(fp, topics, tmp, create.name);
	free (tmp);
	tmp = NULL;
}
