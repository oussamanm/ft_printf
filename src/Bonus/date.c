/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   date.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zamazzal <zouhir.amazzal@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:00:28 by zamazzal          #+#    #+#             */
/*   Updated: 2019/03/25 22:05:29 by zamazzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"
#include "../../includes/date.h"

int		ft_type_k()
{
	time_t sec;
	struct tm *mytime;

	sec = time(NULL);
	mytime = gmtime(&sec);
	ft_putnbr(mytime->tm_year + 1900);
	ft_putchar('-');
	ft_printf("%.2d",mytime->tm_mon + 1);
	ft_putchar('-');
	ft_printf("%.2d",mytime->tm_mday + 1);
	return (10);
}