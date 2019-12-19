/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: onouaman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/06 21:14:19 by onouaman          #+#    #+#             */
/*   Updated: 2019/04/12 04:00:39 by onouaman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "colors.h"

int		ft_color(char *color)
{
	if (ft_strequ(color, "black"))
		ft_putstr(BLACK);
	else if (ft_strequ(color, "red"))
		ft_putstr(RED);
	else if (ft_strequ(color, "green"))
		ft_putstr(GREEN);
	else if (ft_strequ(color, "yellow"))
		ft_putstr(YELLOW);
	else if (ft_strequ(color, "blue"))
		ft_putstr(BLUE);
	else if (ft_strequ(color, "magenta"))
		ft_putstr(MAGENTA);
	else if (ft_strequ(color, "cyan"))
		ft_putstr(CYAN);
	else if (ft_strequ(color, "white"))
		ft_putstr(WHITE);
	else if (ft_strequ(color, "eoc"))
		ft_putstr(EOC);
	else
		return (0);
	return (1);
}

int		checkcolor(char *str)
{
	char	*color;
	int		i;

	i = 0;
	while (str[i] != '\0' && str[i] != '}')
		i++;
	if (str[i] != '}' || i < 2)
		return (0);
	color = ft_strsub(str, 0, i);
	if (ft_color(color))
	{
		ft_strdel(&color);
		return (i);
	}
	ft_strdel(&color);
	return (0);
}
