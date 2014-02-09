/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/09 11:11:56 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/09 11:45:14 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_init_tab(void)
{
	char	*tab;
	char	i;
	char	c;

	tab = (char *)malloc(sizeof(char) * 9);
	if (tab)
	{
		i = 1;
		c = 1;
		while (c < 8)
		{
			tab[c] = i;
			i = i << 1;
			c++;
		}
		tab[0] = 0;
		tab[8] = 7;
		return (tab);
	}
	return (NULL);
}
