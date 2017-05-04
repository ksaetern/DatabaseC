/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createformat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/03 17:55:12 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/03 17:55:14 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftdb.h"

void	ft_datatype(char *s1, char *s2, int topiccreated, int topics)
{
	/*skips to end of element name, adds a * then datatype*/
	int i;
	int	j;

	i = 0;
	j = 0;
	while (ft_isalnum(s1[j]) || s1[j] == ',' || s1[j] == '*')
		j++;
	s1[j] = '*';
	j++;
	while (s2[i] != '\0')
	{
		s1[j] = s2[i];
		j++;
		i++;
	}
	if (topiccreated < topics)
		s1[j] = ',';
}

void	ft_topicnames(char *s1, char *s2)
{
	/*add each element name*/
	int i;
	int	j;

	j = 0;
	i = 0;
	while((ft_isalnum(s1[j]) || s1[j] == ',' || s1[j] == '*' || ft_wspace_check(s1[j])))
			j++;
	while (s2[i] != '\0')
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
}

void	ft_csvformat(char *s1, char *s2, int topiccreated, int topics)
{
	/*adds value then a comma after each value*/
	int i;
	int	j;

	j = 0;
	i = 0;
	while((ft_isalnum(s1[j]) || s1[j] == ',' || ft_wspace_check(s1[j])))
			j++;
	while (s2[i] != '\0' && s2[i] != '\n')
	{
		s1[j] = s2[i];
		i++;
		j++;
	}
	if (topiccreated < topics)
		s1[j] = ',';
}
