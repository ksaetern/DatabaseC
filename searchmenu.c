/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchmenu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksaetern <ksaetern@student.42.us.org       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 01:32:31 by ksaetern          #+#    #+#             */
/*   Updated: 2017/05/05 01:32:38 by ksaetern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_searchmenu2(char *choose, t_ftdb *create, char ***entry)
{
	if (strcmp(choose, "topics") == 0)
		ft_printtopic(entry, create);
	if (strcmp(choose, "menu") == 0)
		ft_mainmenu();
	if (strcmp(choose, "exit") == 0)
		ft_exit();
	else
		ft_error();
}

void	ft_searcherror(t_topic *dbhead)
{
	t_ftdb		create;

	printf("%s%s\n%s[%s%40s%s]\n[%s%40s%s]\n", RED, "Topic not found",
		RESET, RED, "exit", RESET, GREEN, "search", RESET);
	ft_get_next_line(0, &create.line);
	if (strcmp(create.line, "exit") == 0)
		ft_exit();
	if (strcmp(create.line, "search") == 0)
		ft_searchmenu(dbhead);
	else
		ft_mainmenu();
}
