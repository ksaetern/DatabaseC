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

# define CREATE "1"
# define ADD "2"
# define SEARCH "3"
# define DESTROY "4"
# define EXIT "5"
# define YES "yes"
# define NO "no"
# define REMOVE "987456123remove321654789"
typedef	struct  	s_ftdb
{
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
void				ft_search(void);
void 				list_dir(const char *path);
void				ft_adddata(FILE *fp, int topics, char **tmp, char *databasename);
FILE				*ft_open(char *str);
void				ft_datatype(char *s1, char *s2, int topiccreated, int topics);
void				ft_topicnames(char *s1, char *s2);
void				ft_csvformat(char *s1, char *s2, int topiccreated, int topics);

#endif
