/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin_to_dec.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 19:46:12 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/08 11:32:54 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
static int	ft_pow(int n, int p)
{
	if (p == 0)
		return (1);
	else
		return (n * ft_pow(n, p - 1));
}

char	ft_bin_to_dec(char *s)
{
	int	i;
	int	j;
	char	res;

	i = 7;
	j = 0;
	res = 0;
	while (i >= 0)
	{
		res += (s[i] - '0') * ft_pow(2, j);
		i--;
		j++;
	}
	return (res);
}
