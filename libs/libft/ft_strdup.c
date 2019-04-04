/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 13:35:27 by onouaman          #+#    #+#             */
/*   Updated: 2018/10/20 04:51:31 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*s2;
	int		lenstr;

	i = 0;
	lenstr = ft_strlen(s1);
	s2 = (char *)malloc(sizeof(char) * (lenstr + 1));
	if (s2 == NULL)
		return (NULL);
	while (i < lenstr)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
