/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funct_help.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 19:06:14 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/16 21:46:30 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_declen(int nbr)
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

unsigned long long	ft_power(int nbr, int pwr)
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

unsigned long long	ft_power_nega(int nbr, int pwr)
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

int					ft_all_zero(char *nbr)
{
	if (nbr)
		while (*nbr != '\0')
		{
			if (*nbr != '0')
				return (0);
			nbr++;
		}
	return (1);
}

int					ft_checkz_f(t_expdb *st_exp, t_bits *st_b)
{
	int rtn;

	rtn = ft_all_zero(&st_exp->frac[1]);
	if (rtn != 1)
		return (0);
	if (st_b->bit_m == 23 && st_exp->expo == -127)
		return (1);
	else if (st_b->bit_m == 52 && st_exp->expo == -1023)
		return (1);
	else if (st_b->bit_m == 63 && st_exp->expo == -16383)
		return (1);
	return (0);
}
