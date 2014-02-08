
#include <signal.h>
#include <unistd.h>

char		*ft_dec_to_bin(int nb);
void		ft_putstr(char *str);
int		ft_atoi(char *str);

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
  int		i;
  int		j;
  char		*letter;

  server = ft_atoi(av[1]);
  i = 0;
  while (av[2][i])
    {
      letter = ft_dec_to_bin((int)av[2][i]);
      j = 0;
      while (j < 8)
	{
	  ft_put_sig(server, letter[j]);
	  usleep(25);
	  j++;
	}
      i++;
    }
  free(letter);
}

int		main(int ac, char **av)
{
  if (ac >= 3)
	  ft_client(av);
  else
	  ft_putstr("Usage: ./client pid message\n");
  return (0);
}
