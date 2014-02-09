
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

char		*ft_init_tab(void);
void		ft_putstr(char *str);
int			ft_atoi(char *str);

void		ft_send_to_server(char c, int pid, char *tab)
{
	char	i;

	i = 7;
	while (i)
	{
		usleep(2);
		if (c >= tab[i])
		{
			kill(pid, SIGUSR2);
			c = c - tab[i];
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		i--;
	}
}

void		ft_put_sig(int server, char bit)
{
  if (bit == 0)
    kill(server, SIGUSR1);
  else
    kill(server, SIGUSR2);
}

void		ft_client(char **av)
{
  int		server;
  char		*tab;
  int		i;

  server = ft_atoi(av[1]);
  i = 0;
  tab = ft_init_tab();
  while (av[2][i])
  {
	  ft_send_to_server(av[2][i], server, tab);
	  i++;
  }
  ft_send_to_server('\0', server, tab);  
  free(tab);
}

int		main(int ac, char **av)
{
  if (ac >= 3)
	  ft_client(av);
  else
	  ft_putstr("Usage: ./client pid message\n");
  return (0);
}
