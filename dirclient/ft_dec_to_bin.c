/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dec_to_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlehuger <vlehuger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/02/07 18:24:56 by vlehuger          #+#    #+#             */
/*   Updated: 2014/02/07 20:06:04 by vlehuger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char			*ft_dec_to_bin(int dec)
{
	char		*bin;
	int			i;

	bin = (char *)malloc(sizeof(char) * 8);
	if (bin)
	{
		i = 7;
		while (i >= 0)
		{
			if (dec % 2 == 0)
				bin[i] = 0;
			else
				bin[i] = 1;
			dec = dec / 2;
			i--;
		}
		return (bin);
	}
	return (NULL);
}
