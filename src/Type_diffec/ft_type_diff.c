/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 04:42:14 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 16:56:23 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_o(t_listopt *st_opt, va_list *ap)
{
	unsigned long long int	i_value;
	char					*resu;
	char					*value;

	value = NULL;
	st_opt->c = 'o';
	i_value = ft_apply_lenmod_o(ap, st_opt->opt_len);
	if (i_value == 0)
	{
		if (st_opt->opt_fwidth > st_opt->opt_pre && st_opt->opt_pre <= 0)
			value = ft_strnew_char(1, '0');
		else if (st_opt->opt_pre == 0)
		{
			if (ft_check_char(st_opt->opt_flag, '#') == 1)
				return (ft_putstrr("0", 0));
			return (ft_putstrr("", 0));
		}
	}
	value = (value == NULL) ? ft_conv_base(i_value, 8, 0) : value;
	if (ft_check_char(st_opt->opt_flag, '#') == 1 && ft_strcmp(value, "0") != 0)
		value = ft_strjoir("0", value, 2);
	resu = ft_applywith_d(NULL, value, st_opt);
	resu = ft_applyopt_d(resu, value, st_opt, 0);
	(value != NULL) ? ft_strdel(&value) : NULL;
	return (ft_putstrr(resu, 1));
}

int		ft_type_u(t_listopt *st_opt, va_list *ap)
{
	unsigned long long int	i_value;
	char					*resu;
	char					*value;

	resu = NULL;
	value = NULL;
	i_value = va_arg(*ap, unsigned long long int);
	value = ft_apply_lenmod_u(i_value, st_opt->opt_len);
	if (ft_atoi(value) == 0 && st_opt->opt_pre == 0)
	{
		if (st_opt->opt_fwidth > st_opt->opt_pre && st_opt->opt_pre <= 0)
			value[0] = ' ';
		else if (ft_check_char(st_opt->opt_flag, ' ') == 1)
			return (ft_putstrr(" ", 0));
		else
		{
			ft_strdel(&value);
			return (0);
		}
	}
	resu = ft_applywith_d(resu, value, st_opt);
	resu = ft_applyopt_d(resu, value, st_opt, 0);
	ft_strdel(&value);
	return (ft_putstrr(resu, 1));
}

int		ft_type_x(t_listopt *st_opt, va_list *ap, char c)
{
	unsigned long long int	i_v;
	char					*resu;
	char					*value;
	int						index;

	resu = NULL;
	index = 0;
	st_opt->c = c;
	i_v = va_arg(*ap, unsigned long long int);
	if (st_opt->opt_pre == 0 && i_v == 0)
	{
		if (st_opt->opt_fwidth == -1)
			return (0);
		return (ft_putstrr(ft_strnew_char(st_opt->opt_fwidth, ' '), 1));
	}
	value = ft_conv_base(i_v, 16, (c == 'x') ? 0 : 1);
	ft_correct_flagx(st_opt, st_opt->opt_flag, 'x');
	i_v = ft_applyopt_x(&resu, &value, st_opt, ' ');
	ft_applyflagh_x(&resu, &value, st_opt);
	i_v = ft_strlen(value);
	if (st_opt->opt_fwidth > (int)i_v && !ft_check_char(st_opt->opt_flag, '-'))
		index = st_opt->opt_fwidth - i_v;
	ft_memcpy(&resu[index], value, i_v);
	ft_strdel(&value);
	return (ft_putstrr(resu, 1));
}

int		ft_type_p(t_listopt *st_opt, va_list *ap)
{
	unsigned long long int	i_value;
	char					*resu;
	char					*value;

	resu = NULL;
	value = NULL;
	i_value = va_arg(*ap, unsigned long long int);
	value = ft_conv_base(i_value, 16, 0);
	value = ft_strjoir("0x", value, 2);
	resu = ft_applywith_d(resu, value, st_opt);
	resu = ft_applyopt_d(resu, value, st_opt, 0);
	ft_strdel(&value);
	return (ft_putstrr(resu, 1));
}
