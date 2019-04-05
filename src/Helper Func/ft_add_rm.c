/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_rm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/25 17:42:45 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/04 15:43:01 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

st_listopt		*ft_add_lstopt(void)
{
	st_listopt	*st_opt;

	st_opt = (st_listopt *)malloc(sizeof(st_listopt));
	st_opt->opt_flag = NULL;
	st_opt->opt_fwidth = -1;
	st_opt->opt_pre = -1;
	st_opt->opt_len = NULL;
	st_opt->c = 0;
	return (st_opt);
}

st_expdb		*ft_add_lstexp(void)
{
	st_expdb	*st_exp;

	st_exp = (st_expdb *)malloc(sizeof(st_expdb));
	st_exp->sign = 0;
	st_exp->expo = 0;
	st_exp->frac = "";
	return (st_exp);
}

char    *ft_typef_help(st_listopt *st_opt, t_bits *st_bits, va_list *ap)
{
    char    *i_value;
    
    if (ft_check_char(st_opt->opt_len, 'L') == 1)       /// long Double
        i_value = ft_type_Lf(st_bits, ap);
    else if (ft_check_char(st_opt->opt_len, 'l') == 1)   /// float || Double
        i_value = ft_type_lf(st_bits, ap, 1);
    else
        i_value = ft_type_lf(st_bits, ap, 0);
    return (i_value);
}