/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 19:19:08 by onouaman          #+#    #+#             */
/*   Updated: 2019/02/25 23:02:38 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/// ft_call_type : call type and return len read
int		ft_call_type(char c, st_listopt *st_opt, va_list *ap) 
{
	int		rtn;

	rtn = 0;
	rtn = (c == '%') ? ft_type_perc(st_opt, ap) : rtn; // %%
	rtn = (c == 'c') ? ft_type_c(st_opt, ap) : rtn;  // char
	rtn = (c == 's') ? ft_type_s(st_opt, ap) : rtn;  // string
	rtn = (c == 'i' || c == 'd') ? ft_type_d(st_opt, ap) : rtn; // decimal
	rtn = (c == 'o') ? ft_type_o(st_opt, ap) : rtn;  // octal
	rtn = (c == 'u') ? ft_type_u(st_opt, ap) : rtn;  // Unsigned int
	rtn = (c == 'x' || c == 'X') ? ft_type_x(st_opt, ap, c) : rtn;  // Hex
	rtn = (c == 'p') ? ft_type_p(st_opt, ap) : rtn;  // pointeur
	rtn = (c == 'f') ? ft_type_f(st_opt, ap) : rtn;  // float
	/// free list
	if (st_opt != NULL)
	{
		if (st_opt->opt_flag != NULL)
			ft_strdel(&(st_opt->opt_flag));
		if (st_opt->opt_len != NULL)
			ft_strdel(&(st_opt->opt_len));
		free(st_opt);		
	}
	return (rtn);
}

/// ft_arg : fill list option and return index len of all opt
int		ft_arg(char *str, st_listopt *st_opt)
{
	int			index_type;
	int			rtn;

	rtn = 0;
	index_type = 0;
	str++;
	//flag
	st_opt->opt_flag = ft_checkflag(str);
	index_type += (st_opt->opt_flag != NULL) ? ft_strlen(st_opt->opt_flag) : 0;
	//width
	st_opt->opt_fwidth = ft_checkfw(&str[index_type]);
	index_type += (st_opt->opt_fwidth >= 0) ? ft_declen(st_opt->opt_fwidth) : 0;
	//precision
	st_opt->opt_pre = ft_checkpre(&str[index_type], &index_type); /// add param and comment line below
	//lenght
	st_opt->opt_len = ft_checklen(&str[index_type]);
	index_type += (st_opt->opt_len != NULL) ? ft_strlen(st_opt->opt_len) : 0;
	return (index_type++);
}

/// ft_printf : loop char of str_print , print result and return fin len of read
int		ft_printf(char *str_print, ...)
{
	va_list		ap;
	st_listopt	*st_opt;
	int			index;
	int			len;
	int			rtn;

	index = 0;
	rtn = 0; 
	va_start(ap, str_print);
	len = (int)ft_strlen(str_print);
	while(index < len && str_print[index] != '\0')
	{
		if (str_print[index] == '%')
		{
			st_opt = ft_add_lstopt();
			index += (ft_arg(&str_print[index], st_opt) + 1);				
			rtn += ft_call_type(str_print[index], st_opt, &ap);
		}
		else
		{
			ft_putchar(str_print[index]);
			rtn++;
		}
		index++;
	}
	va_end(ap);
	return (rtn);
}