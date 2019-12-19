/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_sim.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:42:17 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 05:37:41 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_perc(t_listopt *st_opt, va_list *ap)
{
	char	*resu;

	UNUSED(ap);
	resu = NULL;
	if (st_opt->opt_fwidth > 1)
	{
		resu = ft_apply_with(resu, "a", st_opt);
		if (ft_check_char(st_opt->opt_flag, '0') == 1)
			ft_bchar(resu, ft_strlen(resu), '0');
		if (st_opt->opt_flag != NULL &&
				ft_check_char(st_opt->opt_flag, '-') == 1)
			resu[0] = '%';
		else
			resu[st_opt->opt_fwidth - 1] = '%';
	}
	else
	{
		resu = ft_strnew(1);
		resu[0] = '%';
		resu[1] = '\0';
	}
	return (ft_putstrr(resu, 1));
}

int		ft_type_c(t_listopt *st_opt, va_list *ap)
{
	int		value;
	char	*resu;

	resu = NULL;
	value = va_arg(*ap, int);
	if (st_opt->opt_fwidth > 1)
	{
		if (value == 0)
			st_opt->opt_fwidth--;
		resu = ft_apply_with(resu, "a", st_opt);
		if (ft_check_char(st_opt->opt_flag, '-') == 1)
			resu[0] = (value == 0) ? ' ' : value;
		else
			resu[st_opt->opt_fwidth - 1] = (value == 0) ? ' ' : value;
	}
	else
	{
		resu = ft_strnew(1);
		resu[0] = value;
		resu[1] = '\0';
	}
	return ((value == 0) ? (ft_putstrr(resu, 1) + 1) : ft_putstrr(resu, 1));
}

int		ft_type_s(t_listopt *st_opt, va_list *ap)
{
	char	*value;
	char	i_null;
	char	*resu;

	resu = NULL;
	value = va_arg(*ap, char *);
	i_null = 0;
	if (value == NULL)
	{
		value = ft_strdup("(null)");
		i_null = 1;
	}
	resu = ft_apply_with(resu, value, st_opt);
	ft_applypre_s(resu, value, st_opt);
	if (i_null == 1)
		ft_strdel(&value);
	return (ft_putstrr(resu, 1));
}
