/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 22:35:17 by onouaman          #+#    #+#             */
/*   Updated: 2018/10/12 11:33:24 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned intstart, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	else
	{
		if (s != NULL)
		{
			i = intstart;
			while (s[i] != '\0' && j < len)
			{
				str[j] = s[i];
				i++;
				j++;
			}
			str[j] = '\0';
		}
		return (str);
	}
}
