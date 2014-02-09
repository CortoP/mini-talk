/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 12:55:04 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/09 13:32:25 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <ft_list.h>

int			ft_strlen(char *s)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

t_list		*ft_create_list(void)
{
	t_list	*list;

	list = (t_list *)malloc(sizeof(t_list));
	if (list)
	{
		list->tab = (char *)malloc(sizeof(char) * 1000);
		if (list->tab)
		{
			list->next = NULL;
			return (list);
		}
	}
	return (NULL);
}

t_list		*ft_add_new_list(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (list->next)
		list = list->next;
	list->next = ft_create_list();
	return (tmp);
}

void		ft_put(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	while (list)
	{
		if (list->next)
			write(1, list->tab, 1000);
		else
			write(1, list->tab, ft_strlen(list->tab));
		free(list->tab);
		if (tmp != list)
		{
			free(tmp);
			tmp = tmp->next;
		}
		list = list->next;
	}
	free(tmp);
}

t_list		*ft_add_char(t_list *list, char c)
{
	static int	i = 0;
	t_list		*tmp;

	if (!list)
		list = ft_create_list();
	tmp = list;
	while (list->next)
		list = list->next;
	list->tab[i] = c;
	if (c == '\0')
	{
		ft_put(tmp);
		i = 0;
		return (NULL);
	}
	i++;
	if (i == 999)
	{
		i = 0;
		list = ft_add_new_list(list);
	}
	return (tmp);
}
