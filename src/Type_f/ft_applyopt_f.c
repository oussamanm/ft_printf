/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyopt_f.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:17:11 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 17:21:46 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_applyopt_f(char *value, t_listopt *st_opt)
{
	char	*n_value;
	char	*resu;
	int		len_v;
	int		index;

	index = 0;
	st_opt->opt_pre = (st_opt->opt_pre == -1) ? 6 : st_opt->opt_pre;
	n_value = ft_applypre_f(value, st_opt->opt_pre, st_opt->opt_flag);
	ft_strdel(&value);
	len_v = ft_strlen(n_value);
	if (st_opt->opt_fwidth > len_v)
	{
		resu = ft_strnew_char(st_opt->opt_fwidth, ' ');
		if (ft_check_char(st_opt->opt_flag, '0') == 1)
			ft_bchar(resu, st_opt->opt_fwidth, '0');
		if (ft_check_char(st_opt->opt_flag, '-') != 1)
			index = st_opt->opt_fwidth - len_v;
	}
	else
		resu = ft_strnew_char(len_v, ' ');
	if (ft_check_char(st_opt->opt_flag, '+') == 1 || n_value[0] == '-')
		ft_appyflagp_f(resu, n_value, &index, st_opt);
	ft_memcpy(&resu[index], n_value, len_v);
	(n_value != NULL) ? ft_strdel(&n_value) : NULL;
	return (resu);
}

char		*ft_correct_pre(char *value, int index)
{
	int		index_p;
	int		rest;

	index--;
	rest = 1;
	index_p = 0;
	if (value[index + 1] != '\0' && value[index + 1] >= '5')
	{
		while (rest != 0)
		{
			index = (value[index] == '.') ? index - 1 : index;
			rest = (value[index] < '9') ? 0 : 1;
			value[index] = (value[index] < '9') ? value[index] + 1 : '0';
			if (index == 0 && rest != 0)
				value = ft_strjoir("1", value, 2);
			index--;
		}
	}
	return (value);
}

char		*ft_applypre_f(char *val, int opt_pr, char *opt_flag)
{
	int		index;
	char	*n_value;
	int		i_sign;
	char	c;

	index = 0;
	i_sign = 0;
	c = 0;
	if ((index = ft_find_char(val, '.')) != -1)
		index += (opt_pr == 0) ? ft_check_char(opt_flag, '#') : (opt_pr + 1);
	else
		index = (int)ft_strlen(val);
	if (ft_check_char(opt_flag, '+') == 1 && val[0] != '-' && (c = '+') != 0)
		i_sign = 1;
	else if (ft_check_char(opt_flag, ' ') == 1 && val[0] != '-')
	{
		c = ' ';
		i_sign = 1;
	}
	n_value = ft_strnew_char(index + i_sign, '0');
	n_value[0] = (c != 0) ? c : 0;
	val = (opt_pr < (int)ft_strlen(val)) ? ft_correct_pre(val, index) : val;
	ft_memcpy(&n_value[i_sign], val, index);
	return (n_value);
}

void		ft_appyflagp_f(char *resu, char *val, int *indx, t_listopt *st_opt)
{
	if (st_opt->opt_fwidth > (int)ft_strlen(val))
	{
		if (ft_check_char(st_opt->opt_flag, '0') == 1)
		{
			resu[0] = (val[0] == '-') ? '-' : '+';
			if (val[0] == '-')
				ft_rmchar(val, '-');
			else if (val[0] == '+')
				ft_rmchar(val, '+');
			(*indx)++;
		}
	}
}
