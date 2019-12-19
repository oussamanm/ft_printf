/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 16:59:37 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/12 05:10:56 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_bin_char(unsigned char nbr)
{
	int		resu;
	int		i;

	i = 7;
	resu = 0;
	while (i >= 0)
	{
		if (1 & (nbr >> i))
		{
			ft_putchar('1');
			resu++;
		}
		else
		{
			ft_putchar('0');
			resu++;
		}
		i--;
	}
	if (resu == 0)
		return (ft_putstrr("0", 0));
	return (resu);
}

int		ft_bin_str(char *str)
{
	int		i;
	int		rtn;

	i = 0;
	rtn = 0;
	while (str[i] != '\0')
		rtn += ft_bin_char(str[i++]);
	return (rtn);
}

int		ft_bin_int(int nbr)
{
	int		i;
	int		j;

	i = 31;
	j = 0;
	while (i >= 0)
	{
		if (1 & (nbr >> i))
		{
			ft_putstrr("1", 0);
			j++;
		}
		else if (j != 0)
		{
			ft_putstrr("0", 0);
			j++;
		}
		i--;
	}
	if (j == 0)
		return (ft_putstrr("0", 0));
	return (j);
}

int		ft_type_b(char c, va_list *ap)
{
	int		rtn;

	rtn = 0;
	if (c == 'i')
		rtn = ft_bin_int(va_arg(*ap, int));
	else if (c == 'c')
		rtn = ft_bin_char(va_arg(*ap, int));
	else if (c == 's')
		rtn = ft_bin_str(va_arg(*ap, char*));
	else
	{
		ft_putstr("results in undefined behavior\n");
		return (-1);
	}
	return (rtn);
}
