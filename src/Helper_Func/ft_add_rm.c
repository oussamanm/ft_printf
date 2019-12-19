/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:42:45 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/12 04:02:12 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_listopt	*ft_add_lstopt(void)
{
	t_listopt	*st_opt;

	st_opt = (t_listopt *)malloc(sizeof(t_listopt));
	st_opt->opt_flag = NULL;
	st_opt->opt_fwidth = -1;
	st_opt->opt_pre = -1;
	st_opt->opt_len = NULL;
	st_opt->c = 0;
	return (st_opt);
}

t_expdb		*ft_add_lstexp(void)
{
	t_expdb	*st_exp;

	st_exp = (t_expdb *)malloc(sizeof(t_expdb));
	st_exp->sign = 0;
	st_exp->expo = 0;
	st_exp->frac = "";
	return (st_exp);
}

char		*ft_typef_help(t_listopt *st_opt, t_bits *st_bits, va_list *ap)
{
	char	*i_value;

	if (ft_check_char(st_opt->opt_len, 'L') == 1)
		i_value = ft_type_ldf(st_bits, ap);
	else if (ft_check_char(st_opt->opt_len, 'l') == 1)
		i_value = ft_type_lf(st_bits, ap, 1);
	else
		i_value = ft_type_lf(st_bits, ap, 0);
	return (i_value);
}
