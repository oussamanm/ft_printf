/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funct_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:06:14 by onouaman          #+#    #+#             */
/*   Updated: 2019/02/26 19:06:16 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/// ft_declen : get len of a number
int					ft_declen(int nbr) // Done
{
	int		i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	if (i == 0)
		return (1);
	return (i);
}

///Task : remove one function of power

unsigned long long	ft_power(int nbr, int pwr) // Done
{
	unsigned long long	rtn;

	if (pwr == 0)
		return (1);
	rtn = 1;
	while (pwr > 0)
	{
		rtn *= nbr;
		pwr--;
	}
	return (rtn);
}

unsigned long long	ft_power_nega(int nbr, int pwr)  // Done
{
	unsigned long long	rtn;

	if (pwr == 0)
		return (1);
	rtn = 1;
	while (pwr > 0)
	{
		rtn *= nbr;
		pwr--;
	}
	return (rtn);
}

int     ft_all_zero(char *nbr)  // Done
{
    if (nbr)
    while(*nbr != '\0')
    {
        if (*nbr != '0')
            return (0);
        nbr++;
    }
    return (1);
}