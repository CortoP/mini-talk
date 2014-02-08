/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:43:39 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/08 12:25:41 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>

void		ft_putnbr(int nb);
void		ft_putchar(char c);
char		ft_bin_to_dec(char *s);

void		ft_string(char bit)
{
  static char	letter[] = "0000000";
  static int	i = 0;
  int		c;

  letter[i] = bit;
  i++;
  if (i == 8)
    {
      c = ft_bin_to_dec(letter) - 4294967088;
      ft_putchar(c);
      i = 0;
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
