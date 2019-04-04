/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_func_h_str2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 23:33:46 by onouaman          #+#    #+#             */
/*   Updated: 2019/03/30 23:33:48 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

//// ft_add_char : add char in index of string
char	*ft_add_char(char *str, int index, char c, int i_free)
{
	int		len;
	char	*rtn;

	len = (int)ft_strlen(str);
	if (index < 0){
		printf("\nhaniiiiiiiiiiiiiiiiiiii should free str \n");
		return (NULL);}
	rtn = (index > len) ? ft_strnew(index + 1) : ft_strnew(len + 1);
	rtn[index] = c;
	if (index == 0)
		ft_memcpy(&rtn[1], str, len);
	else if (index > 0 && index <= len)
	{
		ft_memcpy(rtn, &str[0], index);
		if (index < len)
			ft_memcpy(&rtn[index + 1], &str[index], len - index);
	}
	else if (index > len)
	{
		ft_memcpy(rtn, str, len);
		ft_bchar(&rtn[len], index - len, '0');
	}
	if (i_free == 1)
		ft_strdel(&str);
	return (rtn);
}

//// ft_remove_char : remove char from string
void	ft_rmchar(char *src, char c)
{
	int		i;
	int		j;
	size_t	len;

	i = 0;
	j = 0;
	if (src == NULL || (len = ft_strlen(src)) == 0)
		return ;
	while (i < (int)len)
	{
		if (src[i] == c)
		{
			src = ft_memmove(&src[i], &src[i + 1], len - i - 1);
			src[len - i - 1] = '\0';
			return ;
		}
		i++;
	}
}

//// ft_string_reverse : shift string to right or left
char	*ft_strrev(char *str, size_t len, int alloc)
{
	size_t	i;
	size_t	j;
	char	*p_str;
	int		temp;

	i = 0;
	if (!str || len == 0)
		return (NULL);
	if (alloc == 1)
	{
		p_str = ft_strnew(len + 1);
		p_str = ft_strncpy(p_str, str, len);
	}
	else
		p_str = str;
	j = len - 1;
	while (i < (len / 2))
	{
		temp = p_str[i];
		p_str[i] = p_str[j];
		p_str[j] = temp;
		i++;
		j--;
	}
	return (p_str);
}

//// ft_shift_str : shift string to right or left
char	*ft_shift_str(int r_l, char *str, int nbr_shift)
{
	char	*new_str;
	int		len;

	new_str = str;
	len = ft_strlen(new_str);
	if (r_l == 0 && nbr_shift <= len)
	{
		ft_strncpy(new_str, &str[nbr_shift - 1], nbr_shift);
	}
	else if (r_l == 1 && nbr_shift <= len)
	{
		while (nbr_shift > 0)
		{
			new_str[--len] = 0;
			nbr_shift--;
		}
	}
	return (new_str);
}

//// ft_escap_zeros : rm all zeros in first of string
char	*ft_escap_str(char *str)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(str);
	while (str[i] != '\0' && str[i] == '0')
		i++;
	if (i != 0 && len != 0)
		ft_strncpy(str, &str[i], len - i);
	return (str);
}
