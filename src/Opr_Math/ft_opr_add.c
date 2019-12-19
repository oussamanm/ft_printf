/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opr_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:24:17 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 16:05:29 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_opradd_h_len(char **nbr1, char **nbr2, int *len, int i_spec_cal)
{
	char	*s1;
	char	*s2;
	int		l1;
	int		l2;
	char	*s;

	l1 = ft_strlen(*nbr1);
	l2 = ft_strlen(*nbr2);
	*len = (l1 > l2) ? l1 : l2;
	s1 = ft_strnew_char(*len, '0');
	s2 = ft_strnew_char(*len, '0');
	if (i_spec_cal != 1)
	{
		(l1 == *len) ? ft_strcpy(s1, *nbr1) : ft_strcpy(&s1[*len - l1], *nbr1);
		(l2 == *len) ? ft_strcpy(s2, *nbr2) : ft_strcpy(&s2[*len - l2], *nbr2);
	}
	(*nbr1 != NULL) ? ft_strdel(nbr1) : NULL;
	(*nbr2 != NULL) ? ft_strdel(nbr2) : NULL;
	*nbr1 = s1;
	*nbr2 = s2;
	*len = (s1[0] == 0 || s2[0] == 0) ? -1 : *len;
	s = ft_strnew_char(*len, '0');
	(*len)--;
	return (s);
}

char	*ft_opr_add(char *nbr1, char *nbr2, int i_free, int i_spec_cal)
{
	int		len;
	int		o_len;
	int		sum;
	int		res;
	char	*str;

	res = 0;
	str = ft_opradd_h_len(&nbr1, &nbr2, &len, i_spec_cal);
	o_len = len++;
	while (--len >= 0)
	{
		sum = (nbr1[len] - '0') + (nbr2[len] - '0') + res;
		res = (sum <= 9) ? 0 : res;
		res = (sum > 9) ? 1 : res;
		sum -= (sum > 9) ? 10 : 0;
		str[len] = sum + '0';
		(len == 0 && res != 0) ? ft_memmove(&str[1], &str[0], o_len + 1) : NULL;
		str[0] = (len == 0 && res != 0) ? (res + '0') : str[0];
	}
	(i_free == 1 || i_free == 3) ? ft_strdel(&nbr1) : NULL;
	(i_free == 2 || i_free == 3) ? ft_strdel(&nbr2) : NULL;
	(i_spec_cal == 0) ? ft_escap_str(str) : NULL;
	return (str);
}
