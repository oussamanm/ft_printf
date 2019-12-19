/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:19:08 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/12 05:18:54 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_call_type(char *str, t_listopt *st_opt, va_list *ap)
{
	int		rtn;
	int		c;

	rtn = 0;
	c = str[0];
	if (c == 'b')
		rtn = ft_type_b((str[1]) ? str[1] : 0, ap);
	rtn = (c == 'k') ? ft_type_k(str) : rtn;
	rtn = (c == '%') ? ft_type_perc(st_opt, ap) : rtn;
	rtn = (c == 'c') ? ft_type_c(st_opt, ap) : rtn;
	rtn = (c == 's') ? ft_type_s(st_opt, ap) : rtn;
	rtn = (c == 'i' || c == 'd') ? ft_type_d(st_opt, ap) : rtn;
	rtn = (c == 'o') ? ft_type_o(st_opt, ap) : rtn;
	rtn = (c == 'u') ? ft_type_u(st_opt, ap) : rtn;
	rtn = (c == 'x' || c == 'X') ? ft_type_x(st_opt, ap, c) : rtn;
	rtn = (c == 'p') ? ft_type_p(st_opt, ap) : rtn;
	rtn = (c == 'f') ? ft_type_f(st_opt, ap) : rtn;
	if (st_opt != NULL)
	{
		ft_strdel(&(st_opt->opt_flag));
		ft_strdel(&(st_opt->opt_len));
		free(st_opt);
	}
	return (rtn);
}

int		ft_arg(char *str, t_listopt *st_opt)
{
	int			index_type;
	int			rtn;

	rtn = 0;
	index_type = 0;
	str++;
	st_opt->opt_flag = ft_checkflag(str);
	index_type += (st_opt->opt_flag != NULL) ? ft_strlen(st_opt->opt_flag) : 0;
	st_opt->opt_fwidth = ft_checkfw(&str[index_type]);
	index_type += (st_opt->opt_fwidth >= 0) ? ft_declen(st_opt->opt_fwidth) : 0;
	st_opt->opt_pre = ft_checkpre(&str[index_type], &index_type);
	st_opt->opt_len = ft_checklen(&str[index_type]);
	index_type += (st_opt->opt_len != NULL) ? ft_strlen(st_opt->opt_len) : 0;
	return (index_type);
}

int		ft_check_argv(char *str, int *i, t_listopt *st_opt, va_list *ap)
{
	int		rtn;
	int		j;

	rtn = 1;
	j = 0;
	if (*str == '%')
	{
		st_opt = ft_add_lstopt();
		j = (ft_arg(str, st_opt) + 1);
		rtn = ft_call_type(&str[j], st_opt, ap);
		(*i) += (str[j] == 'b' && str[j + 1] && (str[j + 1] == 'i' ||
			str[j + 1] == 's' || str[j + 1] == 'c')) ? 1 : 0;
		if (str[j] == 'k' && str[j + 1] && str[j + 1] == '{' &&
			ft_find_char(&str[j], '}') != -1)
			(*i) += ft_find_char(&str[j], '}');
		*i += j;
		return (rtn);
	}
	if (*str == '{' && (j = checkcolor((str + 1))))
	{
		*i += j + 1;
		return (0);
	}
	ft_putchar(*str);
	return (rtn);
}

int		ft_printf(char *str_print, ...)
{
	va_list		ap;
	t_listopt	*st_opt;
	int			index;
	int			len;
	int			rtn;

	index = -1;
	rtn = 0;
	st_opt = NULL;
	va_start(ap, str_print);
	len = (int)ft_strlen(str_print);
	while ((++index) < len && str_print[index] != '\0')
	{
		rtn += ft_check_argv(&str_print[index], &index, st_opt, &ap);
	}
	va_end(ap);
	return (rtn);
}
