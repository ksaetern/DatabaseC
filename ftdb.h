/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftdb.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/27 21:08:28 by ksaetern          #+#    #+#             */
/*   Updated: 2017/04/27 21:08:37 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FTDB_H
# define FTDB_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "libft/libft.h"

# define CREATE 	"1"
# define ADD 		"2"
# define SEARCH 	"3"
# define DESTROY 	"4"
# define EXIT 		"5"
# define YES 		"yes"
# define NO 		"no"
# define REMOVE 	"987456123remove321654789"

# define RESET  	"\x1B[0m"
# define RED  		"\x1B[31m"
# define GREEN  	"\x1B[32m"
# define YELLOW  	"\x1B[33m"
# define BLUE  		"\x1B[34m"
# define MAGENTA  	"\x1B[35m"
# define CYAN  		"\x1B[36m"
# define WHITE  	"\x1B[37m"

typedef	struct  	s_ftdb
{
	int				dataentry;
	int				topics;
	char			name[100];
	char			data[100];
	char			str[10];
	FILE			*fp;
	char			*line;
	char			*topicnames;
	char			addline[1000];
}					t_ftdb;

typedef struct   	s_topic
{
	char			*topicname;
	char			topictype[20];
	char			**data;
	struct s_topic	*next;
}					t_topic;

int					main(void);
void				ft_error(void);
void				ft_create(void);
void				ft_createdirectory(void);
void				ft_add(void);
void				ft_mainmenu(void);
void				ft_destroy(void);
void				ft_search(void);
void				ft_exit(void);
void				ft_error(void);
void 				list_dir(const char *path);
void				ft_name(void);
t_ftdb				*ft_grabinfo(t_ftdb *create, int fd, char **topicnames);
void				ft_adddata(FILE *fp, int topics, char **tmp, char *databasename);
FILE				*ft_open(char *str);
t_topic				*ft_newlist(t_topic *newlist);
void				ft_datatype(char *s1, char *s2, int topiccreated, int topics);
void				ft_topicnames(char *s1, char *s2);
void				ft_csvformat(char *s1, char *s2, int topiccreated, int topics);

#endif
