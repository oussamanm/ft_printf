/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opr_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:36:57 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 02:38:11 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_opr_pow(char *nbr, char *pow, int i_free)
{
	int		i_pow;
	int		i;
	char	*str;

	i = 0;
	i_pow = ft_atoi(pow);
	if (i_pow == 0 || ft_all_zero(nbr))
	{
		(i_free == 1 || i_free == 3) ? ft_strdel(&nbr) : NULL;
		(i_free == 2 || i_free == 3) ? ft_strdel(&pow) : NULL;
		return (ft_strnew_char(1, '1'));
	}
	str = ft_strnew(i_pow);
	i_pow--;
	ft_strcpy(str, nbr);
	while (i < i_pow)
	{
		str = ft_opr_multi(str, nbr, 1);
		i++;
	}
	(i_free == 1 || i_free == 3) ? ft_strdel(&nbr) : NULL;
	(i_free == 2 || i_free == 3) ? ft_strdel(&pow) : NULL;
	return (str);
}

char	*ft_opr_negapower(char *nbr, char *power, int i_free)
{
	int		i_power;
	int		i_lennbr;
	char	*rtn;

	i_lennbr = ft_strlen(nbr);
	i_power = ft_atoi(power);
	rtn = ft_strnew_char(i_power, '0');
	ft_strcpy(&rtn[i_power - i_lennbr], nbr);
	if (i_free == 1)
		ft_strdel(&nbr);
	return (rtn);
}
