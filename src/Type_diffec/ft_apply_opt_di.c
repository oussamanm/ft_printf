/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_opt_di.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 02:58:57 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 04:41:36 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_applyopt_x(char **resu, char **value,
		t_listopt *st_opt, char c)
{
	int		len;
	char	*n_value;
	int		len_v;

	n_value = *value;
	len_v = (int)ft_strlen(*value);
	len = len_v;
	if (st_opt->opt_fwidth > len_v && st_opt->opt_fwidth > st_opt->opt_pre)
	{
		if (ft_check_char(st_opt->opt_flag, '0') == 1 && st_opt->opt_pre == -1)
			c = '0';
		len = st_opt->opt_fwidth;
	}
	if (st_opt->opt_pre != -1 && st_opt->opt_pre > len_v)
	{
		len = (st_opt->opt_pre > st_opt->opt_fwidth) ? st_opt->opt_pre : len;
		c = (st_opt->opt_pre > st_opt->opt_fwidth) ? '0' : c;
		n_value = ft_strnew_char(st_opt->opt_pre, '0');
		ft_memcpy(&n_value[st_opt->opt_pre - len_v], *value, len_v);
		len_v = ft_strlen(n_value);
	}
	*resu = ft_strnew_char(len, c);
	(*value != n_value) ? ft_strdel(value) : NULL;
	*value = n_value;
	return (len_v);
}

void				ft_applyflagh_x(char **r, char **n_v, t_listopt *st_opt)
{
	int		len;
	int		i;

	i = 0;
	len = (int)ft_strlen(*n_v);
	if (ft_check_char(st_opt->opt_flag, '#') == 1)
	{
		while (*n_v && (*n_v)[i] != '\0')
		{
			i = ((*n_v)[i] != '0') ? -1 : i;
			if ((*n_v)[i] != '0')
				break ;
			i++;
		}
		if (i == -1 && st_opt->opt_fwidth > len &&
				ft_check_char(st_opt->opt_flag, '0') == 1)
			*r = ft_memcpy(*r, (st_opt->c == 'x' ? "0x" : "0X"), 2);
		else if (i == -1)
		{
			*n_v = ft_strjoir((st_opt->c == 'x' ? "0x" : "0X"), *n_v, 2);
			i = ft_strlen(*r);
			ft_strdel(r);
			*r = ft_strnew_char(i + ((st_opt->opt_fwidth > len) ? 0 : 2), ' ');
		}
	}
}

void				ft_correct_flagx(t_listopt *st_opt, char *flag, char c)
{
	int		i;

	i = 0;
	if (c == 'x' || c == 'd' || c == 'i')
	{
		if (st_opt->opt_pre != -1 || ft_check_char(flag, '-') == 1)
		{
			ft_rmchar(flag, '0');
		}
	}
}

char				*ft_apply_lenmod_u(unsigned long long i_val, char *opt_len)
{
	char	*value;

	if (opt_len == NULL)
		return (ft_itoa_u(i_val));
	if (ft_check_str(opt_len, "hh"))
		value = ft_itoa_u((unsigned char)i_val);
	else if (ft_check_char(opt_len, 'h'))
		value = ft_itoa_u((unsigned short int)i_val);
	else if (ft_check_str(opt_len, "ll"))
		value = ft_itoa_u((unsigned long long int)i_val);
	else if (ft_check_char(opt_len, 'l'))
		value = ft_itoa_u((unsigned long int)i_val);
	else
		value = ft_itoa_u(i_val);
	return (value);
}

unsigned long long	ft_apply_lenmod_o(va_list *ap, char *opt_len)
{
	unsigned long long int i_value;

	i_value = va_arg(*ap, unsigned long long);
	if (opt_len == NULL)
		return (i_value);
	if (ft_check_str(opt_len, "hh"))
		i_value = (unsigned char)i_value;
	else if (ft_check_char(opt_len, 'h'))
		i_value = (unsigned short int)i_value;
	else if (ft_check_str(opt_len, "ll"))
		i_value = (unsigned long long int)i_value;
	else if (ft_check_char(opt_len, 'l'))
		i_value = (unsigned long int)i_value;
	return (i_value);
}
