/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_applyopt_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:11:18 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 17:29:37 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_applywith_d(char *resu, char *value, t_listopt *st_opt)
{
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(value);
	if (st_opt->opt_fwidth > len && st_opt->opt_fwidth > st_opt->opt_pre)
	{
		resu = ft_strnew(st_opt->opt_fwidth);
		ft_bchar(resu, st_opt->opt_fwidth, ' ');
	}
	else if (st_opt->opt_pre > len)
	{
		if (value[0] == '-' || ft_check_char(st_opt->opt_flag, '+') == 1)
			i = 1;
		resu = ft_strnew(st_opt->opt_pre + i);
		ft_bchar(resu, st_opt->opt_pre, '0');
	}
	else
	{
		if (ft_check_char(st_opt->opt_flag, ' ') == 1 && value[0] != '-')
			len++;
		resu = ft_strnew(len);
		ft_bchar(resu, len, ' ');
	}
	return (resu);
}

char	*ft_applypre_d(char *value, int opt_pre, char *opt_flag)
{
	char	*n_value;
	int		len_value;
	int		len_v;
	int		bln_nega;

	n_value = value;
	bln_nega = (value[0] == '-') ? 1 : 0;
	value = (value[0] == '+' || value[0] == '-') ? value + 1 : value;
	len_v = (int)ft_strlen(value);
	if (bln_nega == 1 || ft_check_char(opt_flag, '+') == 1 ||
			(value[0] == 0 && ft_check_char(opt_flag, '+') == 1))
	{
		len_value = opt_pre + 1;
		n_value = ft_strnew(len_value);
		ft_bchar(n_value, len_value, '0');
		n_value[0] = (bln_nega == 0) ? '+' : '-';
	}
	else
	{
		len_value = opt_pre;
		n_value = ft_strnew(len_value);
		ft_bchar(n_value, len_value, '0');
	}
	ft_memcpy(&n_value[len_value - len_v], value, len_v);
	return (n_value);
}

void	ft_applymain_flag(char *r, char *n_v, t_listopt *st_op, int *index)
{
	int		len_value;

	len_value = ft_strlen(n_v);
	if (ft_check_char(st_op->opt_flag, '0') == 1 &&
			st_op->opt_pre == -1 && st_op->opt_fwidth > len_value)
		ft_bchar(r, st_op->opt_fwidth, '0');
	if (st_op->opt_pre == -1 || (st_op->opt_pre < len_value &&
				ft_isdigit(n_v[0]) == 1))
		ft_applyflagp_d(r, &n_v, index, st_op);
	ft_applyflags_d(r, n_v, index, st_op);
}

void	ft_applyflagp_d(char *resu, char **n_v, int *indx, t_listopt *st_opt)
{
	if (ft_check_char(st_opt->opt_flag, '+') == 1 && (*n_v)[0] != '-')
	{
		if (*indx == 0)
			resu[(*indx)++] = '+';
		if (*index != 0 && ft_check_char(st_opt->opt_flag, '0') == 1 &&
				st_opt->opt_fwidth > (int)ft_strlen(*n_v))
			resu[0] = '+';
		else if (*index != 0)
			resu[*indx - 1] = (**n_v != '+') ? '+' : resu[*indx - 1];
	}
	if ((*n_v)[0] == '-' && ft_check_char(st_opt->opt_flag, '0') == 1)
	{
		if (st_opt->opt_fwidth <= (int)ft_strlen(*n_v))
			return ;
		else if ((st_opt->opt_fwidth != -1 && st_opt->opt_pre == -1 &&
					ft_check_char(st_opt->opt_flag, '0') == 1) ||
				st_opt->opt_pre > ((int)ft_strlen(*n_v) - 1))
		{
			resu[0] = '-';
			ft_rmchar(*n_v, '-');
			(*indx)++;
		}
	}
}

void	ft_applyflags_d(char *resu, char *n_v, int *indx, t_listopt *st_opt)
{
	int		len_value;

	len_value = ft_strlen(n_v);
	if (ft_check_char(st_opt->opt_flag, ' ') == 1)
	{
		if (n_v[0] != '-')
		{
			if (*indx == 0)
				resu[(*indx)++] = ' ';
			else
				resu[0] = ' ';
		}
	}
}
