/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_h_upd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:29:51 by onouaman          #+#    #+#             */
/*   Updated: 2019/03/30 23:29:52 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

/// ft_bchar : simple bchar , fill string with char c
void	ft_bchar(char *str, size_t n, char c)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
}

/// ft_putstrr : simple pustr with free parametre
int		ft_putstrr(char *s, int free_str)
{
	int		i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	if (free_str == 1 && s != NULL)
		ft_strdel(&s);
	return (i);
}

/// ft_strnew_char : simple strnew and fill it with char c
char	*ft_strnew_char(size_t size, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	if (size <= 0)
		return (NULL);
	if (!(str = (char *)malloc(size * sizeof(char) + 1)))
		return (0);
	while (i < size)
	{
		str[i] = c;
		i++;
	}
	str[i] = 0;
	return (str);
}

/// ft_strjoir : simple strjoin with parametre free
char	*ft_strjoir(char *s1, char *s2, int rm)
{
	char		*new_str;
	size_t		j;
	size_t		i;
	size_t		s1_len;
	size_t		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_str = ft_strnew(s1_len + s2_len + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	j = -1;
	while (++i < s1_len)
		*(new_str + i) = *(s1 + i);
	while (++j < s2_len)
		*(new_str + i++) = *(s2 + j);
	if (rm == 1 || rm == 3)
		ft_strdel(&s1);
	else if (rm == 2 || rm == 3)
		ft_strdel(&s2);
	return (new_str);
}
