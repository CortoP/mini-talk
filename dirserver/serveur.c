/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:43:39 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/09 13:28:33 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <ft_list.h>

void		ft_putnbr(int nb);
void		ft_putchar(char c);
char		*ft_init_tab(void);
t_list		*ft_add_char(t_list *list, char c);

void		ft_string(char bit)
{
	static char		*tab = NULL;
	static t_list	*list = NULL;

	if (tab == NULL)
		tab = ft_init_tab();
	tab[0] = tab[0] + tab[tab[8]] * bit;
	tab[8]--;
	if (tab[8] == 0)
	{
		list = ft_add_char(list, tab[0]);
		tab[0] = 0;
		tab[8] = 7;
	}
}

void		ft_sigusr1(int bit)
{
  ft_string(0);
 }

void		ft_sigusr2(int bit)
{
  ft_string(1);
}

int		main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	ft_putchar('\n');
	signal(SIGUSR1, ft_sigusr1);
	signal(SIGUSR2, ft_sigusr2);
	while (42)
	{
		continue ;
	}
	return (0);
}
