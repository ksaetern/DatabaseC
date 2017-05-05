/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchstore.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 18:25:50 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/04 18:25:53 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

t_ftdb		*ft_grabinfo(t_ftdb *create, int fd, char **topicnames)
{
	int		data;

	data = 0;
	if (ft_get_next_line(fd, &create->line))
		create->topics = atoi(create->line);
	if (create->topics == 0)
	{
		printf("\n[%40s]\n\n", "Format [error] choose another file");
		ft_search();
	}
	if (ft_get_next_line(fd, &create->line))
		topicnames = ft_strsplit(create->line, ',');
	printf("topics = [%s]\n", create->line);
	while (ft_get_next_line(fd, &create->line))
		data++;
	create->dataentry = data;
	printf("[Number of topics:%23d]\n", create->topics);
	printf("Number of data entry: [%d]\n", create->dataentry);
	close(fd);
	return (create);
}