/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_opt_si.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 05:31:09 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 05:34:20 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_apply_with(char *resu, char *value, t_listopt *st_opt)
{
	int		len;

	len = (int)ft_strlen(value);
	if (st_opt->opt_fwidth > len || (st_opt->opt_fwidth < len &&
				st_opt->opt_pre != -1 && st_opt->opt_fwidth > st_opt->opt_pre))
	{
		resu = ft_strnew(st_opt->opt_fwidth);
		len = st_opt->opt_fwidth;
	}
	else
	{
		if (st_opt->opt_pre != -1 && st_opt->opt_pre < len)
			len = st_opt->opt_pre;
		resu = ft_strnew(len);
	}
	ft_bchar(resu, len, ' ');
	return (resu);
}

void		ft_applypre_s(char *resu, char *value, t_listopt *st_opt)
{
	char	*n_value;
	size_t	len_value;
	int		reste;

	len_value = ft_strlen(value);
	n_value = value;
	reste = 0;
	if (st_opt->opt_pre < (int)len_value && st_opt->opt_pre != -1)
		n_value = ft_strsub(value, 0, st_opt->opt_pre);
	if (n_value == NULL)
		return ;
	if (st_opt->opt_fwidth > (int)ft_strlen(n_value))
	{
		reste = st_opt->opt_fwidth - (int)ft_strlen(n_value);
		if (st_opt->opt_flag != NULL &&
				ft_check_char(st_opt->opt_flag, '-') == 1)
			reste = 0;
	}
	ft_memcpy(&resu[reste], n_value, ft_strlen(n_value));
	if (n_value != value && n_value)
		free(n_value);
}
