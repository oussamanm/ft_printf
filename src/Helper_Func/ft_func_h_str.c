/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_h_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:31:42 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/06 16:56:39 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_char(char *str, char c)
{
	char	*p;

	if (str == NULL)
		return (0);
	p = str;
	while (*p)
	{
		if (*p == c)
			return (1);
		p++;
	}
	return (0);
}

int		ft_find_char(char *str, char c)
{
	int		i;

	i = 0;
	if (str == NULL)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_check_str(const char *src, const char *needle)
{
	int		i;
	int		j;
	size_t	cbfind;
	int		k;

	i = 0;
	if (*src == 0 || *needle == 0)
		return (0);
	while (src[i] != '\0')
	{
		k = i++;
		cbfind = 0;
		j = 0;
		if (src[k] == needle[j])
		{
			while (needle[j] != '\0')
			{
				if (src[k++] == needle[j++])
					cbfind++;
			}
		}
		if (cbfind == ft_strlen(needle))
			return (1);
	}
	return (0);
}
