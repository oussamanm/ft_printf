/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:47:37 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/25 22:05:15 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/colors.h"

int		b_char(unsigned char bit)
{
	int	i;
	int j;

	i = 256;
	j = 0;
	while ((i = i >> 1))
	{
		if ((bit & i))
		{
			ft_putchar('1');
			j++;
		}
		else if (j != 0)
		{
			ft_putchar('0');
			j++;
		}
	}
	return (j);
}

int		b_int(int x)
{
	unsigned long long int i;
	int j;

	i = 17179869184;
	j = 0;
	while ((i = i >> 1))
	{
		if ((x & i))
		{
			ft_putchar('1');
			j++;
		}
		else if (j != 0)
		{
			ft_putchar('0');
			j++;
		}
	}
	return (j);
}

int		b_str(char *str)
{
	int i;
	int rtn;
	
	i = 0;
	rtn = 0;
	while (str[i] != '\0')
		rtn +=b_char(str[i++]);
	return (rtn);
}

int		ft_type_b(char c, va_list *ap)
{
	int rtn;

	rtn = 0;
	if (c == 'i')
		rtn = b_int(va_arg(*ap, int));
	else if (c == 'c')
		rtn = b_char(va_arg(*ap, int));
	else if (c == 's')
		rtn = b_str(va_arg(*ap, char*));
	else
	{
		ft_putstr("results in undefined behavior\n");
		return (-1);
	}
	return (rtn);
}