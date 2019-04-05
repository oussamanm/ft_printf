/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 21:47:02 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/25 22:03:01 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/colors.h"

int printcolor(char *color)
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

int	checkcolor(char *str)
{
	char *color;
	int i;

	i = 0;
	while (str[i] != '\0' && str[i] != '}')
		i++;
	if (str[i] != '}')
		return (0);
	color = ft_strsub(str, 0, i);
	if (printcolor(color))
	{
		free(color);
		return (i);
	}
	free(color);
	return (0);
}